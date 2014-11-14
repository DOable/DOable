<?php
/**
 * @file
 * doable_blog_entries.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function doable_blog_entries_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog_entry|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog_entry';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|blog_entry|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog_entry|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog_entry';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'node_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read More',
        'wrapper' => 'div',
        'class' => 'button',
        'ft' => array(),
      ),
    ),
  );
  $export['node|blog_entry|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function doable_blog_entries_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog_entry|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog_entry';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(),
    'fields' => array(),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|blog_entry|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog_entry|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog_entry';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_blog_subtitle',
        2 => 'field_blog_date',
        3 => 'field_blog_image',
        4 => 'field_blog_body',
        5 => 'field_blog_files',
        6 => 'field_blog_tags',
        7 => 'links',
        8 => 'comments',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_blog_subtitle' => 'ds_content',
      'field_blog_date' => 'ds_content',
      'field_blog_image' => 'ds_content',
      'field_blog_body' => 'ds_content',
      'field_blog_files' => 'ds_content',
      'field_blog_tags' => 'ds_content',
      'links' => 'ds_content',
      'comments' => 'ds_content',
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
    'hide_page_title' => '1',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|blog_entry|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog_entry|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog_entry';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_blog_subtitle',
        2 => 'field_blog_date',
        3 => 'field_blog_image',
        4 => 'field_blog_teaser',
        5 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_blog_subtitle' => 'ds_content',
      'field_blog_date' => 'ds_content',
      'field_blog_image' => 'ds_content',
      'field_blog_teaser' => 'ds_content',
      'node_link' => 'ds_content',
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
    'hide_page_title' => '0',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|blog_entry|teaser'] = $ds_layout;

  return $export;
}
