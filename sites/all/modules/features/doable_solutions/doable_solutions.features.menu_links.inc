<?php
/**
 * @file
 * doable_solutions.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function doable_solutions_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_solutions:solutions
  $menu_links['main-menu_solutions:solutions'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'solutions',
    'router_path' => 'solutions',
    'link_title' => 'Solutions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_solutions:solutions',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-admin-menu---content_add-solution:node/add/solution
  $menu_links['menu-admin-menu---content_add-solution:node/add/solution'] = array(
    'menu_name' => 'menu-admin-menu---content',
    'link_path' => 'node/add/solution',
    'router_path' => 'node/add/solution',
    'link_title' => 'Add Solution',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-admin-menu---content_add-solution:node/add/solution',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Solution');
  t('Solutions');


  return $menu_links;
}
