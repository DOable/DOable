<?php
/**
 * @file
 * doable_users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function doable_users_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_doable|user|user|form';
  $field_group->group_name = 'group_user_doable';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'DOable Team',
    'weight' => '3',
    'children' => array(
      0 => 'field_user_doable_team_title',
      1 => 'field_user_doable_board',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'DOable Team',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-user-doable field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_user_doable|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_profile|user|user|form';
  $field_group->group_name = 'group_user_profile';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_organization',
      1 => 'field_user_location',
      2 => 'field_user_bio',
      3 => 'field_user_linkedin',
      4 => 'field_user_twitter',
      5 => 'field_user_google_plus',
      6 => 'field_user_facebook',
      7 => 'field_user_photo',
      8 => 'field_user_organization_title',
      9 => 'field_user_full_name',
      10 => 'field_user_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-user-profile field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_user_profile|user|user|form'] = $field_group;

  return $export;
}
