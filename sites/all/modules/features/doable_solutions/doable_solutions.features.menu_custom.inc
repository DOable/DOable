<?php
/**
 * @file
 * doable_solutions.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function doable_solutions_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-admin-menu---content.
  $menus['menu-admin-menu---content'] = array(
    'menu_name' => 'menu-admin-menu---content',
    'title' => 'Admin Menu - Content',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Menu - Content');
  t('Main menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
