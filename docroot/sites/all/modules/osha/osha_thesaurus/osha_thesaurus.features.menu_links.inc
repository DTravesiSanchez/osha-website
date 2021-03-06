<?php
/**
 * @file
 * osha_thesaurus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function osha_thesaurus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_eu-osha-hierarchical:tools-and-resources/eu-osha-thesaurus/hierarchical.
  $menu_links['main-menu_eu-osha-hierarchical:tools-and-resources/eu-osha-thesaurus/hierarchical'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tools-and-resources/eu-osha-thesaurus/hierarchical',
    'router_path' => 'tools-and-resources/eu-osha-thesaurus/hierarchical',
    'link_title' => 'EU-OSHA hierarchical',
    'options' => array(
      'copyright' => array(
        'copyright' => '',
        'author' => '',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_eu-osha-hierarchical:tools-and-resources/eu-osha-thesaurus/hierarchical',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_eu-osha-thesaurus:tools-and-resources/eu-osha-thesaurus',
  );
  // Exported menu link: main-menu_eu-osha-thesaurus-alphabetical:tools-and-resources/eu-osha-thesaurus/alphabetical.
  $menu_links['main-menu_eu-osha-thesaurus-alphabetical:tools-and-resources/eu-osha-thesaurus/alphabetical'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tools-and-resources/eu-osha-thesaurus/alphabetical',
    'router_path' => 'tools-and-resources/eu-osha-thesaurus/alphabetical',
    'link_title' => 'EU-OSHA thesaurus alphabetical',
    'options' => array(
      'copyright' => array(
        'copyright' => '',
        'author' => '',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_eu-osha-thesaurus-alphabetical:tools-and-resources/eu-osha-thesaurus/alphabetical',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_eu-osha-thesaurus:tools-and-resources/eu-osha-thesaurus',
  );
  // Exported menu link: main-menu_thesaurus-content-type-menu-position-rule:menu-position/22.
  $menu_links['main-menu_thesaurus-content-type-menu-position-rule:menu-position/22'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/22',
    'router_path' => 'menu-position/%',
    'link_title' => 'Thesaurus Content Type (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'identifier' => 'main-menu_thesaurus-content-type-menu-position-rule:menu-position/22',
    ),
    'module' => 'menu_position',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_eu-osha-thesaurus:tools-and-resources/eu-osha-thesaurus',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('EU-OSHA hierarchical');
  t('EU-OSHA thesaurus alphabetical');
  t('Thesaurus Content Type (menu position rule)');

  return $menu_links;
}
