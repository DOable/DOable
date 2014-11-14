<?php
/**
 * @file
 * doable_press_coverage.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function doable_press_coverage_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|press_coverage|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'press_coverage';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_press_archive_subtitle' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'subtitle',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|press_coverage|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|press_coverage|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'press_coverage';
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
      'weight' => '4',
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
  $export['node|press_coverage|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function doable_press_coverage_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|press_coverage|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'press_coverage';
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
  $export['node|press_coverage|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|press_coverage|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'press_coverage';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_press_archive_logo',
        1 => 'title_field',
        2 => 'field_archive_publication',
        3 => 'field_press_archive_subtitle',
        4 => 'field_press_date',
        5 => 'field_press_image',
        6 => 'field_press_intro',
        7 => 'links',
        8 => 'field_press_archive_title',
        9 => 'group_press_archive',
        10 => 'field_press_archive_date',
        11 => 'field_press_archive_author',
        12 => 'field_press_archive_image',
        13 => 'field_press_archive_body',
        14 => 'field_press_archive_link',
        15 => 'field_press_pdf',
      ),
    ),
    'fields' => array(
      'field_press_archive_logo' => 'ds_content',
      'title_field' => 'ds_content',
      'field_archive_publication' => 'ds_content',
      'field_press_archive_subtitle' => 'ds_content',
      'field_press_date' => 'ds_content',
      'field_press_image' => 'ds_content',
      'field_press_intro' => 'ds_content',
      'links' => 'ds_content',
      'field_press_archive_title' => 'ds_content',
      'group_press_archive' => 'ds_content',
      'field_press_archive_date' => 'ds_content',
      'field_press_archive_author' => 'ds_content',
      'field_press_archive_image' => 'ds_content',
      'field_press_archive_body' => 'ds_content',
      'field_press_archive_link' => 'ds_content',
      'field_press_pdf' => 'ds_content',
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
  $export['node|press_coverage|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|press_coverage|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'press_coverage';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_press_date',
        2 => 'field_press_image',
        3 => 'field_press_teaser',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_press_date' => 'ds_content',
      'field_press_image' => 'ds_content',
      'field_press_teaser' => 'ds_content',
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
  $export['node|press_coverage|teaser'] = $ds_layout;

  return $export;
}
