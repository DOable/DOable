<?php
/**
 * @file
 * doable_press_coverage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function doable_press_coverage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'press';
  $page->task = 'page';
  $page->admin_title = 'Press Coverage';
  $page->admin_description = 'A page for the <em>Podcast</em>';
  $page->path = 'press';
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
  $handler->name = 'page_press_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'press';
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
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 2,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'intro',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'intro' => array(
        'type' => 'region',
        'title' => 'Intro',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'body',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'body' => array(
        'type' => 'region',
        'title' => 'Body',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header_a' => NULL,
      'header_b' => NULL,
      'header_c' => NULL,
      'subheader_a' => NULL,
      'subheader_b' => NULL,
      'subheader_c' => NULL,
      'navigation' => NULL,
      'title' => NULL,
      'body' => NULL,
      'sidebar_a' => NULL,
      'sidebar_b' => NULL,
      'sidebar_c' => NULL,
      'footer_a' => NULL,
      'footer_b' => NULL,
      'footer_c' => NULL,
      'intro' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cc3a74ef-5266-4deb-8dcc-afcb43b0553d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-67299a79-e5a3-4715-9056-1ba39445340f';
    $pane->panel = 'body';
    $pane->type = 'views';
    $pane->subtype = 'press_teasers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '67299a79-e5a3-4715-9056-1ba39445340f';
    $display->content['new-67299a79-e5a3-4715-9056-1ba39445340f'] = $pane;
    $display->panels['body'][0] = 'new-67299a79-e5a3-4715-9056-1ba39445340f';
    $pane = new stdClass();
    $pane->pid = 'new-af7bf895-7c78-4b7a-9551-fe5a1309d466';
    $pane->panel = 'intro';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:8';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'intro',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'af7bf895-7c78-4b7a-9551-fe5a1309d466';
    $display->content['new-af7bf895-7c78-4b7a-9551-fe5a1309d466'] = $pane;
    $display->panels['intro'][0] = 'new-af7bf895-7c78-4b7a-9551-fe5a1309d466';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['press'] = $page;

  return $pages;

}
