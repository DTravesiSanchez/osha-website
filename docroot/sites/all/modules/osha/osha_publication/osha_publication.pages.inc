<?php

function osha_publication_menu_publications_form($form, $form_state) {
  drupal_set_title(t('Publications'));
  global $language;
  $text = osha_publication_req_param($form_state, 'text');
  $sort = osha_publication_req_param($form_state, 'sort_by', 'search_api_relevance');
  $direction = osha_publication_req_param($form_state, 'direction', 'desc');
  $languages = osha_publication_req_param($form_state, 'languages', array($language->language));
  $tags = osha_publication_req_param($form_state, 'tags', array());
  $publication_type = osha_publication_req_param($form_state, 'publication_type', array());
  $form = array(
    '#action' => url('tools-and-publications/publications'),
    '#method' => 'GET',
    'left-column' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('publications-sidebar-first'))
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
    '#attributes' => array('placeholder' => t('Search')),
    '#prefix' => '<div id="publication-search">',
  );
  $sorts = array('search_api_relevance' => t('Relevance'), 'field_publication_date' => t('Publication date'));
  $form['content']['sort_by'] = array(
    '#title' => t('Sort by'),
    '#type' => 'select',
    '#default_value' => $sort,
    '#options' => $sorts,
  );
  $order = array('desc' => t('Desc'), 'asc' => t('Asc'));
  $form['content']['direction'] = array(
    '#title' => t('Order'),
    '#type' => 'select',
    '#default_value' => $direction,
    '#options' => $order,
  );
  $form['content']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#suffix' => '</div>',
  );
  $form['left-column']['languages'] = array(
    '#type' => 'checkboxes',
    '#options' => osha_language_list_options(),
    '#default_value' => $languages,
    '#title' => t('Available in languages'),
  );
  $form['left-column']['tags'] = array(
    '#type' => 'checkboxes',
    '#options' => _osha_publication_tags_options_list(),
    '#default_value' => $tags,
    '#title' => t('Topics'),
  );
  $form['left-column']['publication_type'] = array(
    '#type' => 'checkboxes',
    '#options' => _publication_type_options_list(),
    '#default_value' => $publication_type,
    '#title' => t('Type'),
  );
  if (empty($form_state['input'])) {
    $form['content']['results-native'] = osha_publication_menu_publications_search_native($form_state);
    $native_nids = $form['content']['results-native']['#nids'];
    $form['content']['results-related'] = osha_publication_menu_publications_search_related($form_state, $native_nids);
  }
  if (!empty($form_state['#results-native'])) {
    $form['content']['results-native'] = $form_state['#results-native'];
    $form['content']['results-related'] = $form_state['#results-related'];
  }

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'osha_publication') . '/js/search-auto-submit.js',
  );

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
  $languages = osha_publication_req_param($form_state, 'languages', array($language->language));
  $text = osha_publication_req_param($form_state, 'text');
  $sort = osha_publication_req_param($form_state, 'sort_by', 'search_api_relevance');
  $direction = osha_publication_req_param($form_state, 'direction', 'desc');
  $tags = osha_publication_req_param($form_state, 'tags', array());
  $publication_type = osha_publication_req_param($form_state, 'publication_type', array());

  $is_search = !empty($text);
  $restrict = array();
  if ($is_search) {
    /** @var SearchApiQuery $query */
    /** @var SearchApiSolrService $server */
    list($server, $query) = osha_publication_menu_publications_get_query();
    $query->condition('status', 1);
    $query->condition('type', 'publication');
    $query->condition('field_file:file', 0, '>');
    $query->keys($text);
    $query->fields(array('title_field', 'body:value'));
    if (!empty($sort)) {
      $query->sort($sort, $direction);
    }

    $results = $server->search($query);
    if (!empty($results['results'])) {
      foreach ($results['results'] as $result) {
        list($lng, $nid) = explode('_', $result['id'], 2);
        $restrict[] = $nid;
      }
    }
    if (empty($restrict)) {
      return array(
        '#nids' => '',
      );
    }
  }
  $tags_ids = array();
  if (!empty($tags)) {
    foreach ($tags as $tag) {
      $tags_ids[] = $tag;
    }
  }
  $publication_type_ids = array();
  if (!empty($publication_type)) {
    foreach ($publication_type as $pubt) {
      if ($pubt) {
        $publication_type_ids[] = $pubt;
      }
    }
  }

  // Select all publications having field_file available in filtered languages.
  $q = db_select('node', 'a');
  $q->innerJoin('field_data_field_publication_type', 'b', 'a.nid = b.entity_id');
  $q->innerJoin('field_data_field_publication_date', 'c', 'a.nid = c.entity_id');
  if (!empty($tags_ids)) {
    $q->innerJoin('field_data_field_tags', 'd', 'a.nid = d.entity_id');
  }
  $q->fields('a', array('nid', 'vid'));
  $q->condition('a.type', 'publication');
  $q->condition('a.status', 1);
  $q->orderBy('field_publication_date_value', 'DESC');
  if (!empty($restrict)) {
    $q->condition('a.nid', $restrict, 'IN');
  }
  if (!empty($publication_type_ids)) {
    $q->condition('b.field_publication_type_tid', $publication_type_ids, 'IN');
  }
  if (!empty($tags_ids)) {
    $q->condition('d.field_tags_tid', $tags_ids, 'IN');
  }
  $pnids = $q->execute()->fetchCol();
  $nids = array();
  foreach($pnids as $pnid) {
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

  $per_page = 7;
  $current_page = pager_default_initialize(count($nids), $per_page);
  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  foreach($nodes as $node) {
    $node->filter_languages = $languages;
  }
  $pager_params = array('languages' => $languages);
  if ($is_search) {
    $pager_params['text'] = $text;
  }
  if (!empty($sort)) {
    $pager_params['sort_by'] = $sort;
    $pager_params['direction'] = $direction;
  }
  if (!empty($tags)) {
    $pager_params['tags'] = $tags;
  }
  $ret = array(
    '#nids' => $nids,
    '#prefix' => '<h2 class="h4-title">' . t('Publications available') . '</h2>',
    'results-native' => node_view_multiple($nodes, 'osha_search_teaser', 0, $language->language),
    '#suffix' => theme('pager', array(
      'tags' => array('<', '<', '', '>', '>'),
      'quantity' => 9,
      'parameters' => $pager_params,
    ))
  );
  return $ret;
}

function osha_publication_menu_publications_search_related($form_state, $native_nids) {
  global $language;
  $ret = array();
  $languages = osha_publication_req_param($form_state, 'languages', array($language->language));
  if(!empty($languages)) {
    if (in_array('en', $languages)) {
      return $ret;
    }
  }
  else {
    if($language->language == 'en') {
      return $ret;
    }
  }
  $text = osha_publication_req_param($form_state, 'text');
  $sort = osha_publication_req_param($form_state, 'sort_by', 'search_api_relevance');
  $direction = osha_publication_req_param($form_state, 'direction', 'desc');
  $tags = osha_publication_req_param($form_state, 'tags', array());
  $publication_type = osha_publication_req_param($form_state, 'publication_type', array());
  $is_search = !empty($text);

  $tags_ids = array();
  if (!empty($tags)) {
    foreach ($tags as $tag) {
      $tags_ids[] = $tag;
    }
  }
  $publication_type_ids = array();
  if (!empty($publication_type)) {
    foreach ($publication_type as $pubt) {
      if ($pubt) {
        $publication_type_ids[] = $pubt;
      }
    }
  }

  $q = db_select('node', 'a');
  $q->innerJoin('field_data_field_publication_type', 'b', 'a.nid = b.entity_id');
  $q->innerJoin('field_data_field_publication_date', 'c', 'a.nid = c.entity_id');
  if (!empty($tags_ids)) {
    $q->innerJoin('field_data_field_tags', 'd', 'a.nid = d.entity_id');
  }
  $q->fields('a', array('nid', 'vid'));
  $q->condition('a.type', 'publication');
  $q->condition('a.status', 1);
  $q->orderBy('field_publication_date_value', 'DESC');
  if (!empty($restrict)) {
    $q->condition('a.nid', $restrict, 'IN');
  }
  if (!empty($publication_type_ids)) {
    $q->condition('b.field_publication_type_tid', $publication_type_ids, 'IN');
  }
  if (!empty($tags_ids)) {
    $q->condition('d.field_tags_tid', $tags_ids, 'IN');
  }
  $nids = $q->execute()->fetchCol();
  if (!empty($native_nids)) { // Remove the nodes displayed above (native)
    $nids = array_filter($nids, function($nid) use ($native_nids) {
      return !in_array($nid, $native_nids);
    });
  }
  if (empty($nids)) {
    return array();
  }
  $per_page = 3;
  $current_page = pager_default_initialize(count($nids), $per_page, 1);
  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  foreach($nodes as $node) {
    $node->filter_languages = $languages;
  }
  $languages = osha_publication_req_param($form_state, 'languages', array());
  $pager_params = array('languages' => $languages);
  if ($is_search) {
    $pager_params['text'] = $text;
  }
  if (!empty($sort)) {
    $pager_params['sort_by'] = $sort;
    $pager_params['direction'] = $direction;
  }
  if (!empty($tags_ids)) {
    $pager_params['tags'] = $tags_ids;
  }
  if (!empty($publication_type_ids)) {
    $pager_params['publication_type'] = $publication_type_ids;
  }
  $ret = array(
    '#prefix' => '<h4>' . t('Other relevant publications in English') . '</h4>',
    'results-related' => node_view_multiple($nodes, 'osha_search_teaser', 0, $language->language),
    '#suffix' => theme('pager', array(
      'tags' => array('<', '<', '', '>', '>'),
      'quantity' => 9,
      'parameters' => $pager_params,
      'element' => 1,
    ))
  );
  return $ret;
}

function osha_publication_menu_publications_get_query() {
  $server = search_api_server_load('solr_server');
  $index = search_api_index_load(SOLR_SEARCH_INDEX);
  $query = new SearchApiQuery($index);
  $query->fields(array()); // Avoid PHP notice
  $solr = new SearchApiSolrService($server);
  return array($solr, $query);
}

/**
 * Get options for publication type filter.
 */
function _publication_type_options_list() {
  $return = array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('publication_types');
  if (!empty($vocabulary)) {
    $terms = taxonomy_get_tree($vocabulary->vid);
    foreach ($terms as $key => $term) {
      $return[$term->tid] = $term->name;
    }
  }
  return $return;
}

/**
 * Get options for publication type filter.
 */
function _osha_publication_tags_options_list() {
  $return = array();
  $q = db_select('field_data_field_tags', 't')
    ->distinct();
  $q->fields('t', array('field_tags_tid'));
  $q->condition('entity_type', 'node');
  $q->condition('bundle', 'publication');
  $q->innerJoin('taxonomy_term_data', 'td', 'td.tid = t.field_tags_tid');
  $q->orderBy('td.name', 'ASC');
  $tids = $q->execute()->fetchCol();
  $terms = taxonomy_term_load_multiple($tids);
  if (!empty($terms)) {
    foreach ($terms as $key => $term) {
      $return[$term->tid] = $term->name;
    }
  }
  return $return;
}