<?php
/**
 * @file
 * doable_base_config.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function doable_base_config_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'intro';
  $ds_view_mode->label = 'Intro';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
    'node' => 'node',
  );
  $export['intro'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'listing';
  $ds_view_mode->label = 'Listing';
  $ds_view_mode->entities = array(
    'comment' => 'comment',
    'node' => 'node',
    'user' => 'user',
  );
  $export['listing'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'listing_preview';
  $ds_view_mode->label = 'Listing Preview';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['listing_preview'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'promo';
  $ds_view_mode->label = 'Promo';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $export['promo'] = $ds_view_mode;

  return $export;
}
