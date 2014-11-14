<?php
/**
 * @file
 * doable_articles.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function doable_articles_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-admin-menu---content.
  $menus['menu-admin-menu---content'] = array(
    'menu_name' => 'menu-admin-menu---content',
    'title' => 'Admin Menu - Content',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Menu - Content');


  return $menus;
}
