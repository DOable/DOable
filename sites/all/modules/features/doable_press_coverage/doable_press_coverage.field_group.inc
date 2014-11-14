<?php
/**
 * @file
 * doable_press_coverage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function doable_press_coverage_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_press_archive|node|press_coverage|form';
  $field_group->group_name = 'group_press_archive';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_coverage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Archive Version',
    'weight' => '6',
    'children' => array(
      0 => 'field_press_pdf',
      1 => 'field_press_archive_title',
      2 => 'field_press_archive_subtitle',
      3 => 'field_press_archive_date',
      4 => 'field_press_archive_link',
      5 => 'field_press_archive_author',
      6 => 'field_press_archive_body',
      7 => 'field_press_archive_image',
      8 => 'field_archive_publication',
      9 => 'field_press_archive_logo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_press_archive|node|press_coverage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_press_archive|node|press_coverage|full';
  $field_group->group_name = 'group_press_archive';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_coverage';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Archive Version',
    'weight' => '6',
    'children' => array(
      0 => 'field_press_pdf',
      1 => 'field_press_archive_title',
      2 => 'field_press_archive_date',
      3 => 'field_press_archive_link',
      4 => 'field_press_archive_author',
      5 => 'field_press_archive_body',
      6 => 'field_press_archive_image',
      7 => 'field_archive_publication',
      8 => 'field_press_archive_logo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Archive Version',
      'instance_settings' => array(
        'classes' => 'group-press-archive field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_press_archive|node|press_coverage|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_press_general|node|press_coverage|form';
  $field_group->group_name = 'group_press_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_coverage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '5',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_press_general|node|press_coverage|form'] = $field_group;

  return $export;
}
