<?php
/**
 * @file
 * doable_articles.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function doable_articles_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_articles:articles
  $menu_links['main-menu_articles:articles'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'articles',
    'router_path' => 'articles',
    'link_title' => 'Articles',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_articles:articles',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-admin-menu---content_add-article:node/add/solution
  $menu_links['menu-admin-menu---content_add-article:node/add/solution'] = array(
    'menu_name' => 'menu-admin-menu---content',
    'link_path' => 'node/add/solution',
    'router_path' => 'node/add/solution',
    'link_title' => 'Add Article',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-admin-menu---content_add-article:node/add/solution',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Article');
  t('Articles');


  return $menu_links;
}
