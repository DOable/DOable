<?php
/**
 * @file
 * doable_solutions.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function doable_solutions_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|solution|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'solution';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '20',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|solution|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|solution|listing';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'solution';
  $ds_fieldsetting->view_mode = 'listing';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|solution|listing'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|solution|listing_preview';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'solution';
  $ds_fieldsetting->view_mode = 'listing_preview';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_solution_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|solution|listing_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|solution|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'solution';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
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
        'link text' => 'View this Result',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|solution|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|solution|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'solution';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'node_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'View Solution',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_solution_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_solution_sectors' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'sectors',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'inline-items',
          'fis-at' => '',
          'fis-def-at' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'inline-item',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_solution_tags' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Tags',
          'lb-el' => 'div',
          'lb-def-at' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'tags',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'inline-items',
          'fis-at' => '',
          'fis-def-at' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'inline-item',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|solution|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function doable_solutions_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|solution|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'solution';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
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
  $export['node|solution|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|solution|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'solution';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_solution_image',
        1 => 'field_solution_addthis',
        2 => 'title',
        3 => 'field_solution_subtitle',
        4 => 'field_solution_outcomes',
        5 => 'field_solution_summary',
        6 => 'field_solution_financing',
      ),
      'right' => array(
        7 => 'links',
        8 => 'field_solution_logo',
        9 => 'field_solution_launch_date',
        10 => 'field_solution_sectors',
        11 => 'field_solution_timeline',
        12 => 'field_solution_budget',
        13 => 'field_solution_tags',
        14 => 'field_solution_contact_details',
        15 => 'field_solution_website',
        16 => 'field_solution_facebook',
        17 => 'field_solution_twitter',
        18 => 'field_solution_similar',
      ),
      'footer' => array(
        19 => 'field_solution_links',
        20 => 'comments',
      ),
    ),
    'fields' => array(
      'field_solution_image' => 'left',
      'field_solution_addthis' => 'left',
      'title' => 'left',
      'field_solution_subtitle' => 'left',
      'field_solution_outcomes' => 'left',
      'field_solution_summary' => 'left',
      'field_solution_financing' => 'left',
      'links' => 'right',
      'field_solution_logo' => 'right',
      'field_solution_launch_date' => 'right',
      'field_solution_sectors' => 'right',
      'field_solution_timeline' => 'right',
      'field_solution_budget' => 'right',
      'field_solution_tags' => 'right',
      'field_solution_contact_details' => 'right',
      'field_solution_website' => 'right',
      'field_solution_facebook' => 'right',
      'field_solution_twitter' => 'right',
      'field_solution_similar' => 'right',
      'field_solution_links' => 'footer',
      'comments' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
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
  $export['node|solution|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|solution|listing';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'solution';
  $ds_layout->view_mode = 'listing';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
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
  $export['node|solution|listing'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|solution|listing_preview';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'solution';
  $ds_layout->view_mode = 'listing_preview';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_solution_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_solution_image' => 'ds_content',
      'title' => 'ds_content',
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
  $export['node|solution|listing_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|solution|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'solution';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_solution_image',
        1 => 'title',
        2 => 'field_solution_subtitle',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_solution_image' => 'ds_content',
      'title' => 'ds_content',
      'field_solution_subtitle' => 'ds_content',
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
  $export['node|solution|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|solution|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'solution';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_solution_image',
        1 => 'field_solution_sectors',
        2 => 'title',
        3 => 'field_solution_teaser',
        4 => 'field_solution_tags',
        5 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_solution_image' => 'ds_content',
      'field_solution_sectors' => 'ds_content',
      'title' => 'ds_content',
      'field_solution_teaser' => 'ds_content',
      'field_solution_tags' => 'ds_content',
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
  $export['node|solution|teaser'] = $ds_layout;

  return $export;
}
