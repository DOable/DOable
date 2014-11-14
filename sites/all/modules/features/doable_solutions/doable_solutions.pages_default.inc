<?php
/**
 * @file
 * doable_solutions.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function doable_solutions_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'solutions';
  $page->task = 'page';
  $page->admin_title = 'Solutions';
  $page->admin_description = '';
  $page->path = 'solutions';
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
  $handler->name = 'page_solutions_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'solutions';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
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
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '74.98542932742507',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '25.014570672574937',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'sidebar' => array(
        'type' => 'region',
        'title' => 'Sidebar',
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
      'center' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b4338e68-8d28-4eed-a2ad-ba352ad30a0e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ba65463c-1a80-469a-830f-0cdb0edb4797';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-solutions_teasers-block';
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
    $pane->uuid = 'ba65463c-1a80-469a-830f-0cdb0edb4797';
    $display->content['new-ba65463c-1a80-469a-830f-0cdb0edb4797'] = $pane;
    $display->panels['center'][0] = 'new-ba65463c-1a80-469a-830f-0cdb0edb4797';
    $pane = new stdClass();
    $pane->pid = 'new-f88aefb2-f025-4536-a608-a59765b17c38';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'block-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'sidebar',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f88aefb2-f025-4536-a608-a59765b17c38';
    $display->content['new-f88aefb2-f025-4536-a608-a59765b17c38'] = $pane;
    $display->panels['sidebar'][0] = 'new-f88aefb2-f025-4536-a608-a59765b17c38';
    $pane = new stdClass();
    $pane->pid = 'new-302be2a7-0a3a-42c2-88ea-4f6ef9803799';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'views-443eba9119d29ba711b770d0bec927ce';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'sidebar',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '302be2a7-0a3a-42c2-88ea-4f6ef9803799';
    $display->content['new-302be2a7-0a3a-42c2-88ea-4f6ef9803799'] = $pane;
    $display->panels['sidebar'][1] = 'new-302be2a7-0a3a-42c2-88ea-4f6ef9803799';
    $pane = new stdClass();
    $pane->pid = 'new-27630d95-0a85-4161-8439-76bb7d8fe893';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'views-solutions_browse_by_tag-block';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'sidebar',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '27630d95-0a85-4161-8439-76bb7d8fe893';
    $display->content['new-27630d95-0a85-4161-8439-76bb7d8fe893'] = $pane;
    $display->panels['sidebar'][2] = 'new-27630d95-0a85-4161-8439-76bb7d8fe893';
    $pane = new stdClass();
    $pane->pid = 'new-ac6defea-8ee5-45b1-9997-997a5c7e03bc';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'boxes-facebook_stream';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'sidebar',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ac6defea-8ee5-45b1-9997-997a5c7e03bc';
    $display->content['new-ac6defea-8ee5-45b1-9997-997a5c7e03bc'] = $pane;
    $display->panels['sidebar'][3] = 'new-ac6defea-8ee5-45b1-9997-997a5c7e03bc';
    $pane = new stdClass();
    $pane->pid = 'new-2808b659-9922-4df5-835f-5da70acedba6';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'boxes-twitter_stream';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'sidebar',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '2808b659-9922-4df5-835f-5da70acedba6';
    $display->content['new-2808b659-9922-4df5-835f-5da70acedba6'] = $pane;
    $display->panels['sidebar'][4] = 'new-2808b659-9922-4df5-835f-5da70acedba6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['solutions'] = $page;

  return $pages;

}
