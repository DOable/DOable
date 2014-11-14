<?php
/**
 * @file
 * doable_blog_entries.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function doable_blog_entries_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blog_general|node|blog_entry|form';
  $field_group->group_name = 'group_blog_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_blog_body',
      1 => 'field_blog_files',
      2 => 'field_blog_image',
      3 => 'field_blog_subtitle',
      4 => 'field_blog_teaser',
      5 => 'field_blog_date',
      6 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-blog-general field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blog_general|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blog_related_content|node|blog_entry|form';
  $field_group->group_name = 'group_blog_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Content',
    'weight' => '7',
    'children' => array(
      0 => 'field_blog_tags',
      1 => 'field_blog_related_content',
      2 => 'field_temp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-blog-related-content field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blog_related_content|node|blog_entry|form'] = $field_group;

  return $export;
}
