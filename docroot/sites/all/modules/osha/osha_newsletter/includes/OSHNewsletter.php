<?php

class OSHNewsletter {

  public static function getTemplatesList() {
    // @todo: replace with a new vocabulary for newsletter templates
    return [
      'newsletter_full_width_details' => 'Full width: thumbnail + details',
      'newsletter_full_width_list' => 'Full width: title + short description',
      'newsletter_half_width_details' => '1/2 width: thumbnail + details',
      'newsletter_half_width_list' => '1/2 width: title + short description',
      'newsletter_half_image_left' => '1/2 width with background image on left side',
      'newsletter_full_width_2_col_blocks' => 'Full width: blocks on 2 columns'
    ];
  }

  public static function getChildStyle($parentTemaplate, $default = 'newsletter_item') {
    $styles = [
      'newsletter_full_width_details' => 'highlights_item',
      'newsletter_full_width_list' => 'newsletter_item',
      'newsletter_half_width_details' => 'highlights_item',
      'newsletter_half_width_list' => 'newsletter_item',
      'newsletter_half_image_left' => 'newsletter_item',
      'newsletter_full_width_2_col_blocks' => 'newsletter_item'
    ];
    if (empty($styles[$parentTemaplate])) {
      return $default;
    }
    return $styles[$parentTemaplate];
  }

  public static function alterContentForm(&$form, &$form_state) {
    // add submit button to send newsletter and send test newsletter
    if (isset($form['content'])) {
      foreach ($form['content'] as $k => &$v) {
        if (strpos($k, 'taxonomy_term:') !== FALSE) {
          $v['style']['#options'] = self::getTemplatesList();
        }
        elseif (strpos($k, 'node:') === 0) {
          hide($v['style']);
        }
      }

      $form['actions']['send_test_newsletter'] = array(
        '#type' => 'submit',
        '#value' => t('Send test newsletter'),
        '#submit' => array('osha_newsletter_send_test_email')
      );
      $form['actions']['send_newsletter'] = array(
        '#type' => 'submit',
        '#value' => t('Send newsletter to subscribers'),
        '#submit' => array('osha_newsletter_send_email_to_subscribers')
      );
    }

    // Attach js to add css class for taxonomy rows.
    // #attributes on $v doesn't work.
    if (isset($form_state['entity_collection']) && $form_state['entity_collection']->bundle == 'newsletter_content_collection') {
      $form['#attached']['js'][] = drupal_get_path('module', 'osha_newsletter') . '/includes/js/collection_form.js';
    }
  }

  public static function renderTemplate($template, $variables) {
    switch ($template) {
      case 'newsletter_multiple_columns':
        $content = [
          '#theme' => 'table',
          '#header' => [],
          '#rows' => [0 => []]
        ];
        foreach ($variables as $column) {
          if (empty($column['#style'])) {
            $content['#rows'][0]['data'] = [];
          }
          else {
            $content['#rows'][0]['data'][] = self::renderTemplate($column['#style'], $column);
          }
        }
        return drupal_render($content);
        break;
      case 'newsletter_full_width_list':
      case 'newsletter_half_width_details':
      case 'newsletter_half_width_list':
      case 'newsletter_half_image_left':
      case 'newsletter_full_width_2_col_blocks':
      case 'newsletter_full_width_details':
        if (empty($variables['nodes'])) {
          return '';
        }
        $content = [
          'header' => ['data' => taxonomy_term_view($variables['section'], 'token')],
          'rows' => [],
        ];
        foreach ($variables['nodes'] as $node) {
          $content['rows'][] = [
            'data' => [node_view($node['node'], $node['#style'])],
          ];
        }
        return render($content);
      default:
        return theme($template, $variables);
    }
  }

  public static function render(EntityCollection $source) {
    $content = [];
    $entityCollectionItems = entity_collection_load_content($source->bundle, $source);

    $campaign_id = '';
    if (!empty($source->field_campaign_id[LANGUAGE_NONE][0]['value'])) {
      $campaign_id = $source->field_campaign_id[LANGUAGE_NONE][0]['value'];
    };

    $items = $entityCollectionItems->children;
    $last_section = null;

    // @todo: replace hardcoded sections with taxonomy terms
    $templatesList = self::getTemplatesList();
    foreach ($items as $item) {
      switch ($item->type) {
        case 'taxonomy_term':
          $current_section = $item->entity_id;
          $content[$current_section] = [
            '#style' => !empty($item->style) ? $item->style : key($templatesList),
            'section' => $item->content,
            'nodes' => [],
          ];
          break;
        case 'node':
          if (empty($current_section)) {
            // Found a node before all sections
            // @todo: maybe we should display a warning?
            continue;
          }
          $content[$current_section]['nodes'][] = [
            '#style' => self::getChildStyle($content[$current_section]['#style']),
            'node' => $item->content,
          ];
          break;
      }
    }

    $languages = osha_language_list(TRUE);

    $renderedContent = '';
    foreach ($content as $section) {
      if (preg_match('/.*(half_width).*/', $section['#style'])) {
        if (!empty($half_column)) {
          $renderedContent .= self::renderTemplate('newsletter_multiple_columns', [$half_column, $section]);
          $half_column = null;
        }
        else {
          $half_column = $section;
        }
      }
      else {
        if (!empty($half_column)) {
          $renderedContent .= self::renderTemplate('newsletter_multiple_columns', [$half_column, 'second_column' => []]);
          $half_column = null;
        }
        $renderedContent .= self::renderTemplate($section['#style'], $section);
      }
    }

    return [
      'header' => theme('newsletter_header', array(
        'languages' => $languages,
        'newsletter_title' => $source->title,
        'newsletter_id' => $source->eid,
        'newsletter_date' =>
          !empty($source->field_publication_date)
          ? $source->field_publication_date[LANGUAGE_NONE][0]['value']
          : $source->field_created[LANGUAGE_NONE][0]['value'],
        'campaign_id' => $campaign_id
      )),
      'body' =>  $renderedContent, //add css styles to href in body
      'footer' => theme('newsletter_footer', array('campaign_id' => $campaign_id)),
    ];
  }
}