<?php
/**
 * @file
 * doable_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function doable_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create solution content'.
  $permissions['create solution content'] = array(
    'name' => 'create solution content',
    'roles' => array(
      'Admin' => 'Admin',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any solution content'.
  $permissions['edit any solution content'] = array(
    'name' => 'edit any solution content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own solution content'.
  $permissions['edit own solution content'] = array(
    'name' => 'edit own solution content',
    'roles' => array(
      'Admin' => 'Admin',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
