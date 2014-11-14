<?php
/**
 * @file
 * doable_base_config.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function doable_base_config_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'admin_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Admin Dashboard';
  $page->admin_description = '';
  $page->path = 'dashboard';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_admin_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'admin_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '53660b6f-053a-4abc-8816-7da5adcab62b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-513cd53d-6d22-4f81-82fa-2ddbfc096c24';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-admin-menu---content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Manage Content',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '513cd53d-6d22-4f81-82fa-2ddbfc096c24';
    $display->content['new-513cd53d-6d22-4f81-82fa-2ddbfc096c24'] = $pane;
    $display->panels['center'][0] = 'new-513cd53d-6d22-4f81-82fa-2ddbfc096c24';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['admin_dashboard'] = $page;

  return $pages;

}
