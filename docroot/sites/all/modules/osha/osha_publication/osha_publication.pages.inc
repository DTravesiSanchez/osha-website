<?php

function osha_publication_menu_publications_form($form, $form_state) {
  global $language;
  drupal_set_title(t('Publications'));
  $text = osha_publication_req_param($form_state, 'text');
  $sort_by = osha_publication_req_param($form_state, 'sort_by', 'field_publication_date');
  $tags = osha_publication_req_param($form_state, 'tags', array());
  $publication_type = osha_publication_req_param($form_state, 'publication_type', array());
  $languages = osha_publication_req_param($form_state, 'languages', array($language->language));
  $form = array(
    '#action' => url('publications'),
    '#method' => 'GET',
    'left-column' => array(
      '#type' => 'container',
      '#attributes' => array('class' => ['content-filters']),
      '#prefix' => '<aside class="sidebars_first">',
      '#suffix' => '</aside>',
    ),
    'content' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('two_column publications-search-list')),
    ),
    '#token' => FALSE,
  );
  $form['content']['text'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Search'),
    '#maxlength' => 200,
    '#default_value' => $text,
    '#title_display' => 'invisible',
    '#attributes' => array('placeholder' => t('Search'), 'class' => ['search-new-design']),
    '#prefix' => '<div class="views-exposed-widgets clearfix"><div id="edit-search-api-views-fulltext-wrapper" class="views-exposed-widget">',
  );
  $form['content']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#suffix' => '</div>',
  );
  $sorts = [
    'field_publication_date' => t('Publication date'),
    'alphabetically' => t('Alphabetically'),
    'relevance' => t('Relevance'),
  ];
  $form['content']['sort_by'] = array(
    '#title' => t('Sort by'),
    '#type' => 'select',
    '#default_value' => $sort_by,
    '#attributes' => array('class' => ['new-select-style']),
    '#options' => $sorts,
    '#prefix' => '<div class="views-exposed-widget">',
    '#suffix' => '</div>',
  );

  $q = db_select('field_data_field_file', 'b');
  $q->fields('b', array('language'));
  $q->innerJoin('node', 'a', 'a.nid = b.entity_id AND a.vid = b.revision_id');
  $q->condition('b.bundle', 'publication');
  $q->condition('a.status', 1);
  $q->distinct();
  $used_languages = $q->execute()->fetchAllKeyed(0, 0);

  $enabled_lang = language_list();
  $enabled_lang = osha_sort_language_list($enabled_lang);
  if (isset($enabled_lang['sh'])) {
    $enabled_lang['sh']->name = t('Serbian');
  }

  $lang_options = [];
  foreach ($enabled_lang as $lang => $lang_obj) {
    if (!isset($used_languages[$lang])) {
      continue;
    }
    if ($lang_obj->enabled) {
      $lang_options[$lang] = $lang_obj->name;
    }
  }

  $form['content']['languages'] = array(
    '#type' => 'select',
    '#options' => $lang_options,
    '#default_value' => $languages,
    '#title' => t('Available in languages'),
    '#attributes' => array('class' => ['new-select-style']),
    '#chosen' => TRUE,
    '#multiple' => TRUE,
    '#prefix' => '<div class="views-exposed-widget">',
    '#suffix' => '</div></div>',
  );

  $query_params = drupal_get_query_parameters();
  if (!empty($query_params['sort_by'])) {
    unset($query_params['sort_by']);
  }
  if (empty($query_params['text'])) {
    unset($query_params['text']);
  }

  if (!empty($query_params) || $publication_type || $tags) {
    $form['content']['link'] = [
      '#type' => 'markup',
      '#markup' => l(t('Clear filter'), current_path()),
    ];
  }

  $form['left-column']['tags'] = array(
    '#type' => 'checkboxes',
    '#options' => _osha_publication_tags_options_list(TRUE),
    '#default_value' => $tags,
    '#title' => t('Topics'),
  );

  $form['left-column']['publication_type'] = array(
    '#type' => 'checkboxes',
    '#options' => _publication_type_options_list(TRUE),
    '#default_value' => $publication_type,
    '#title' => t('Type'),
  );

  if (empty($form_state['input'])) {
    $form['content']['results-native'] = osha_publication_menu_publications_search_native($form_state);
    $form['content']['results-related'] = [];
  }
  if (!empty($form_state['#results-native'])) {
    $form['content']['results-native'] = $form_state['#results-native'];
    $form['content']['results-related'] = $form_state['#results-related'];
  }

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'osha_publication') . '/js/search-auto-submit.js',
  );

  $get_params = array('text', 'sort_by');
  drupal_add_js(array('osha_publication' => array('get_params' => $get_params)), 'setting');
  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_form_osha_publication_menu_publications_form_alter(&$form, $form_state) {
  // Unset the form_id and build_id in order not to have nasty urls.
  unset($form['form_id']);
  unset($form['form_build_id']);
}

function osha_publication_menu_publications_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['redirect'] = FALSE;
  $form_state['#results-native'] = osha_publication_menu_publications_search_native($form_state);
  $native_nids = array();
  if (!empty($form_state['#results-native']['#nids'])) {
    $native_nids = $form_state['#results-native']['#nids'];
  }
  $form_state['#results-related'] = osha_publication_menu_publications_search_related($form_state, $native_nids);
}

function osha_publication_menu_publications_search_native($form_state) {
  global $language;
  /** @var SearchApiQuery $query */
  /** @var SearchApiSolrService $server */
  $languages = osha_publication_req_param($form_state, 'languages', array($language->language));
  $text = osha_publication_req_param($form_state, 'text');
  $sort_by = osha_publication_req_param($form_state, 'sort_by', 'field_publication_date');
  $tags = osha_publication_req_param($form_state, 'tags', array());
  $publication_type = osha_publication_req_param($form_state, 'publication_type', array());

  $is_search = !empty($text);
  $restrict = array();
  if ($is_search) {
    list($server, $query) = osha_publication_menu_publications_get_query();
    $query->setOption('conjunction', 'OR');
    $query->keys($text);
    $fields = [
      'title_field',
      'body:value',
    ];
    $query->fields($fields);

    $query->condition('status', 1);
    $query->condition('type', 'publication');
    $query->condition('field_file:file', 0, '>');

    $query->condition('field_publication_date', time(), '<');

    if ($sort_by == 'field_publication_date') {
      $query->sort('field_publication_date', 'DESC');
    }
    elseif ($sort_by == 'relevance') {
      $query->sort('search_api_relevance', 'DESC');
    }
    else {
      $query->sort('title2', 'ASC');
    }

    $results = $server->search($query);
    $scores = [];
    foreach ($results['results'] as $row) {
      list ($nid, $lang) = explode('/', $row['id']);
      if (isset($scores[$nid])) {
        if ($row['score'] > $scores[$nid]['score']) {
          $scores[$nid] = $row;
        }
      }
      else {
        $scores[$nid] = $row;
      }
    }
    store_score($scores);

    if (!empty($results['results'])) {
      foreach ($results['results'] as $result) {
        list($nid, $lng) = explode('/', $result['id'], 2);
        $restrict[] = $nid;
      }
    }
    if (empty($restrict)) {
      return array(
        '#prefix' => '<p>' . t('No results') . '</p>',
        '#nids' => '',
      );
    }
  }

  $tags_ids = array();
  if (!empty($tags)) {
    foreach ($tags as $tag) {
      if (is_numeric($tag)) {
        $tags_ids[] = $tag;
      }
      else {
        $tid = _osha_publication_get_tag_by_code($tag);
        if (!empty($tid)) {
          $tags_ids[] = $tid;
        }
      }
    }
  }

  $tags_map = osha_publication_get_main_tags_map(FALSE);
  $publication_tags_ids = array();
  foreach ($tags_ids as $pubt) {
    $publication_tags_ids[] = $pubt;
    foreach ($tags_map as $tid => $main_tid) {
      if ($pubt == $main_tid) {
        $publication_tags_ids[] = $tid;
      }
    }
  }

  $types_map = osha_publication_get_main_publication_types_map(FALSE);
  $publication_type_ids = array();
  if (!empty($publication_type)) {
    foreach ($publication_type as $pubt) {
      if ($pubt) {
        $publication_type_ids[] = $pubt;
        foreach ($types_map as $tid => $main_tid) {
          if ($pubt == $main_tid) {
            $publication_type_ids[] = $tid;
          }
        }
      }
    }
  }

  // Select all publications having field_file available in filtered languages.
  $q = db_select('node', 'a');
  $q->innerJoin('field_data_field_publication_type', 'b', 'a.nid = b.entity_id');
  $q->innerJoin('field_data_field_publication_date', 'c', 'a.nid = c.entity_id');
  if (!empty($publication_tags_ids)) {
    $q->innerJoin('field_data_field_tags', 'd', 'a.nid = d.entity_id');
  }
  $q->fields('a', array('nid', 'vid'));
  $q->condition('a.type', 'publication');
  $q->condition('a.status', 1);

  if ($sort_by == 'field_publication_date') {
    $q->orderBy('field_publication_date_value', 'DESC');
  }
  else if ($sort_by == 'relevance') {
  }
  else {
    $q->orderBy('title', 'ASC');
  }

  if (!empty($restrict)) {
    $q->condition('a.nid', $restrict, 'IN');
  }
  if (!empty($publication_type_ids)) {
    $q->condition('b.field_publication_type_tid', $publication_type_ids, 'IN');
  }
  if (!empty($publication_tags_ids)) {
    $q->condition('d.field_tags_tid', $publication_tags_ids, 'IN');
  }
  $pnids = $q->execute()->fetchCol();
  $nids = array();
  foreach ($pnids as $pnid) {
    $q = db_select('field_data_field_file', 'b');
    $q->fields('b', array('entity_id'));
    $q->innerJoin('node', 'a', 'a.nid = b.entity_id AND a.vid = b.revision_id');
    $q->condition('b.bundle', 'publication');
    $q->condition('b.entity_id', $pnid);
    if (!empty($languages)) {
      $q->condition('b.language', $languages, 'IN');
    }
    $c = $q->countQuery()->execute()->fetchField();
    if ($c >= count($languages)) {
      $nids[] = $pnid;
    }
  }

  if (empty($nids)) {
    return array();
  }
  $nids = array_unique($nids);
  if (!empty($restrict)) {
    $nids = array_intersect(array_unique($restrict), $nids);
  }
  $total = count($nids);
  $per_page = 5;
  $current_page = pager_default_initialize(count($nids), $per_page);
  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  foreach ($nodes as $node) {
    $node->filter_languages = $languages;
  }
  $pager_params = array();
  if ($is_search) {
    $pager_params['text'] = $text;
  }
  if (!empty($sort_by)) {
    $pager_params['sort_by'] = $sort_by;
  }

  $showing_lang = $language->language;
  if (count($languages) == 1) {
    $showing_lang = current($languages);
  }
  $start = $current_page * $per_page;
  $pager = theme('pager', array(
    'tags' => array(),
    'quantity' => 9,
    'parameters' => $pager_params,
  ));
  $suffix = '<div class="content-pagination container">' . $pager . '<div class="pager-total"><span>' . ($start + 1) . ' - ' . ($start + count($nodes)) . ' / ' . $total . '</span></div></div>';
  $ret = array(
    '#nids' => $nids,
    '#prefix' => '<h2>' . t('Publications available') . ' (' . $total . ')</h2>',
    'results-native' => node_view_multiple($nodes, 'osha_search_teaser', 0, $showing_lang),
    '#suffix' => $suffix,
  );
  return $ret;
}

/**
 * Get options for publication type filter.
 */
function _publication_type_options_list($map_only = FALSE) {
  $map = osha_publication_get_main_publication_types_map();
  $return = array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('publication_types');
  if (!empty($vocabulary)) {
    $terms = taxonomy_get_tree($vocabulary->vid);
    foreach ($terms as $key => $term) {
      if ($map_only) {
        if (!empty($map[$term->tid])) {
          $term = taxonomy_term_load($map[$term->tid]);
          if (!$term->field_main_category) {
            continue;
          }
          if (!$term->field_main_category[LANGUAGE_NONE][0]['value']) {
            continue;
          }
          $return[$term->tid] = $term->name;
        }
        else {
          $term = taxonomy_term_load($term->tid);
          if (!$term->field_main_category) {
            continue;
          }
          if (!$term->field_main_category[LANGUAGE_NONE][0]['value']) {
            continue;
          }
          $return[$term->tid] = $term->name;
        }
      }
      else {
        $return[$term->tid] = $term->name;
      }
    }
  }
  return $return;
}

/**
 * Get options for publication type filter.
 */
function _osha_publication_tags_options_list($map_only = FALSE) {

  $return = array();
  $q = db_select('field_data_field_tags', 't')
    ->distinct();
  $q->fields('t', array('field_tags_tid'));
  $q->condition('entity_type', 'node');
  $q->condition('bundle', 'publication');
  $q->innerJoin('taxonomy_term_data', 'td', 'td.tid = t.field_tags_tid');
  $q->orderBy('td.name', 'ASC');
  $tids = $q->execute()->fetchCol();
  if ($map_only) {
    $map = osha_publication_get_main_tags_map();
    $old_tids = $tids;
    $tids = [];
    foreach ($old_tids as $tid) {
      $term_id = $tid;
      if (!empty($map[$term_id])) {
        $term_id = $map[$term_id];
      }
      $term = taxonomy_term_load($term_id);
      if (!$term->field_main_topic) {
        continue;
      }
      if (!$term->field_main_topic[LANGUAGE_NONE][0]['value']) {
        continue;
      }
      $tids[] = $term_id;
    }
  }
  $terms = taxonomy_term_load_multiple($tids);
  if (!empty($terms)) {
    foreach ($terms as $key => $term) {
      if (!empty($term->field_tags_code[LANGUAGE_NONE][0]['value'])) {
        $code = $term->field_tags_code[LANGUAGE_NONE][0]['value'];
        $code = str_replace('/', '__', $code);
        if (!isset($return[$code])) {
          $return[$code] = $term->name;
        }
        else {
          watchdog('osha_publication', 'Tags code "!code" error! Please check !tag1 and !tag2!', array(
            '!code' => $code,
            '!tag1' => $return[$term->tid],
            '!tag2' => $term->name,
          ), WATCHDOG_ERROR);
          $return[$term->tid] = $term->name;
        }
      }
      else {
        $return[$term->tid] = $term->name;
      }
    }
  }
  asort($return);
  return $return;
}
