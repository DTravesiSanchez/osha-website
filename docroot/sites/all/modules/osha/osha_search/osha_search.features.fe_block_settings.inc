<?php
/**
 * @file
 * osha_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['facetapi-3I2yRvUb4ut1RBNTxP1zBVR6kihmGEsp'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '3I2yRvUb4ut1RBNTxP1zBVR6kihmGEsp',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search/directives
legislation/directives
legislation/directives/*
legislation/directive/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 21,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Date of directive',
    'visibility' => 1,
  );

  $export['facetapi-3wdzGmfuaWV8dFrp0unV5StIH22e8cRK'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '3wdzGmfuaWV8dFrp0unV5StIH22e8cRK',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'publications
tools-and-publications/publications',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 25,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Type',
    'visibility' => 1,
  );

  $export['facetapi-H521BlbvKT4VvBQ0eUjaRB22CnF0x2vm'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'H521BlbvKT4VvBQ0eUjaRB22CnF0x2vm',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search/*
publications
tools-and-publications/publications',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_frontend',
        'weight' => 23,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Topics',
    'visibility' => 1,
  );

  $export['facetapi-IYV4lO4uBWV9Cstx0SMmJ5nValwNGZX4'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'IYV4lO4uBWV9Cstx0SMmJ5nValwNGZX4',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 23,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Topics',
    'visibility' => 1,
  );

  $export['facetapi-ROXIK6Y7tQue0DgP244H4JOcqy10UCEc'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ROXIK6Y7tQue0DgP244H4JOcqy10UCEc',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_frontend',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['facetapi-bhmRHTzU2n0ejKZP9wDI0S1oi2DgbSDm'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'bhmRHTzU2n0ejKZP9wDI0S1oi2DgbSDm',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search/site',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 17,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Content type',
    'visibility' => 1,
  );

  $export['menu-menu-search'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-search',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => 'search/site
search/wiki',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_frontend',
        'weight' => -34,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_search-osha_search_box'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'osha_search_box',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_search',
    'node_types' => array(),
    'pages' => 'search/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 1,
      ),
      'osha_admin' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_admin',
        'weight' => 1,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 10,
      ),
      'seven' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 1,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['osha_search-osha_search_clear_filters'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'osha_search_clear_filters',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_search',
    'node_types' => array(),
    'pages' => 'search/*
tools-and-publications/publications
tools-and-publications/seminars
legislation/directives/*
safety-and-health-legislation/european-directives
node/2544
legislation/guidelines/*
themes/dangerous-substances/search
themes/dangerous-substances/search/*
themes/musculoskeletal-disorders/search',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 8,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_search-osha_search_language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'osha_search_language',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_search',
    'node_types' => array(),
    'pages' => 'search/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 3,
      ),
      'osha_admin' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_admin',
        'weight' => 3,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 3,
      ),
    ),
    'title' => 'Language',
    'visibility' => 1,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -1,
      ),
      'osha_admin' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_admin',
        'weight' => -1,
      ),
      'osha_frontend' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 2,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views--exp-search-site'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-search-site',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'search/site
search/site*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views--exp-search-wiki'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-search-wiki',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'search/wiki',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 2,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views--exp-search_directives-page'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-search_directives-page',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'search/directives
legislation/directives
legislation/directives/*
legislation/directive/*
node/11
safety-and-health-legislation/european-directives',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 11,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views--exp-search_seminars-page'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-search_seminars-page',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/2427
search/seminars',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 14,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
