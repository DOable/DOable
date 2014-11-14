<?php
/**
 * @file
 * doable_team.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function doable_team_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|grid';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'grid';
  $ds_fieldsetting->settings = array(
    'field_user_photo' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['user|user|grid'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function doable_team_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|grid';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'grid';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_user_photo',
        1 => 'field_user_full_name',
        2 => 'field_user_doable_team_title',
        3 => 'field_user_bio',
        4 => 'field_user_linkedin',
        5 => 'field_user_twitter',
        6 => 'field_user_google_plus',
        7 => 'field_user_facebook',
      ),
    ),
    'fields' => array(
      'field_user_photo' => 'ds_content',
      'field_user_full_name' => 'ds_content',
      'field_user_doable_team_title' => 'ds_content',
      'field_user_bio' => 'ds_content',
      'field_user_linkedin' => 'ds_content',
      'field_user_twitter' => 'ds_content',
      'field_user_google_plus' => 'ds_content',
      'field_user_facebook' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_sidebars' => 0,
  );
  $export['user|user|grid'] = $ds_layout;

  return $export;
}
