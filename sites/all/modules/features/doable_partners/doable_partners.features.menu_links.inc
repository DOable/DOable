<?php
/**
 * @file
 * doable_partners.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function doable_partners_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_partners:partners
  $menu_links['main-menu_partners:partners'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'partners',
    'router_path' => 'partners',
    'link_title' => 'Partners',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_partners:partners',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-admin-menu---content_add-partner:node/add/partner
  $menu_links['menu-admin-menu---content_add-partner:node/add/partner'] = array(
    'menu_name' => 'menu-admin-menu---content',
    'link_path' => 'node/add/partner',
    'router_path' => 'node/add/partner',
    'link_title' => 'Add Partner',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-admin-menu---content_add-partner:node/add/partner',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Partner');
  t('Partners');


  return $menu_links;
}
