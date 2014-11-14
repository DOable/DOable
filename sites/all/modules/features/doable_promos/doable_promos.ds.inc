<?php
/**
 * @file
 * doable_promos.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function doable_promos_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'promo|promo|form';
  $ds_layout->entity_type = 'promo';
  $ds_layout->bundle = 'promo';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_promo_title',
        1 => 'field_promo_sub_title',
        2 => 'field_promo_body',
        3 => 'field_promo_image',
        4 => 'field_promo_link',
        5 => 'field_promo_type',
        6 => 'redirect',
      ),
      'hidden' => array(
        7 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_promo_title' => 'ds_content',
      'field_promo_sub_title' => 'ds_content',
      'field_promo_body' => 'ds_content',
      'field_promo_image' => 'ds_content',
      'field_promo_link' => 'ds_content',
      'field_promo_type' => 'ds_content',
      'redirect' => 'ds_content',
      '_add_existing_field' => 'hidden',
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
  );
  $export['promo|promo|form'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function doable_promos_ds_view_modes_info() {
  $export = array();

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
