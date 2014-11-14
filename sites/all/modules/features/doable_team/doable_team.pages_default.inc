<?php
/**
 * @file
 * doable_team.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function doable_team_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'team';
  $page->task = 'page';
  $page->admin_title = 'Team';
  $page->admin_description = '';
  $page->path = 'team';
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
  $handler->name = 'page_team_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'team';
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
  $display->uuid = '3b48f844-6dea-429d-b0b0-1a04c090fd16';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-43029f21-91a2-4929-b7ac-1c1b503643b9';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'boxes-team';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '43029f21-91a2-4929-b7ac-1c1b503643b9';
    $display->content['new-43029f21-91a2-4929-b7ac-1c1b503643b9'] = $pane;
    $display->panels['center'][0] = 'new-43029f21-91a2-4929-b7ac-1c1b503643b9';
    $pane = new stdClass();
    $pane->pid = 'new-df83d159-a60f-4a19-a0aa-059a453faa9a';
    $pane->panel = 'center';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:be8cddae-a44f-4641-b8fe-984bdbb35de3';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'df83d159-a60f-4a19-a0aa-059a453faa9a';
    $display->content['new-df83d159-a60f-4a19-a0aa-059a453faa9a'] = $pane;
    $display->panels['center'][1] = 'new-df83d159-a60f-4a19-a0aa-059a453faa9a';
    $pane = new stdClass();
    $pane->pid = 'new-e11daca2-2879-4af7-a024-25fb91adaa64';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-team_grid-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e11daca2-2879-4af7-a024-25fb91adaa64';
    $display->content['new-e11daca2-2879-4af7-a024-25fb91adaa64'] = $pane;
    $display->panels['center'][2] = 'new-e11daca2-2879-4af7-a024-25fb91adaa64';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['team'] = $page;

  return $pages;

}
