<?php
/**
 * @file
 * doable_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function doable_users_user_default_roles() {
  $roles = array();

  // Exported role: Admin.
  $roles['Admin'] = array(
    'name' => 'Admin',
    'weight' => 3,
  );

  // Exported role: DOable Team.
  $roles['DOable Team'] = array(
    'name' => 'DOable Team',
    'weight' => 8,
  );

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 6,
  );

  // Exported role: Evaluator.
  $roles['Evaluator'] = array(
    'name' => 'Evaluator',
    'weight' => 7,
  );

  // Exported role: Partner.
  $roles['Partner'] = array(
    'name' => 'Partner',
    'weight' => 4,
  );

  // Exported role: Solution Owner.
  $roles['Solution Owner'] = array(
    'name' => 'Solution Owner',
    'weight' => 5,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
