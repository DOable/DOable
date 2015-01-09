<?php
/**
 * @file
 * iToggle ajax functions.
 */

/**
 * Page callback.
 * iToggle widget AJAX callback.
 *
 * @see itoggle_menu()
 */
function itoggle_ajax_callback() {
  // Extract values from POST.
  $token = filter_input(INPUT_POST, 'token');
  $type = filter_input(INPUT_POST, 'type');
  $bundle = filter_input(INPUT_POST, 'bundle');
  $property = filter_input(INPUT_POST, 'property');
  $id = filter_input(INPUT_POST, 'id');
  $value = filter_input(INPUT_POST, 'value');
  $scope = filter_input(INPUT_POST, 'scope');

  // Generate token key.
  $token_key = "itoggle_{$type}_{$property}_{$id}";

  // Route request.
  if (!empty($token) && drupal_valid_token($token, $token_key)) {
    switch ($scope) {
      case 'entity':
        $ok = _itoggle_ajax_toggle_entity($type, $property, $id, $value);
        break;
      case 'field':
        $ok = _itoggle_ajax_toggle_field($type, $bundle, $property, $id, $value);
        break;
      // Should never really get here.
      case 'field-edit':
        $ok = TRUE;
        break;
    }
  }
  else {
    // Let $ok be NULL so we know the difference between FALSE (error) and
    // undefined (invalid token).
    $ok = NULL;
  }

  drupal_json_output(array('ok' => $ok));
  exit;
}

/**
 * Change an entity field's value.
 *
 * @param string
 *   The entity $type.
 * @param string
 *   The entity $bundle.
 * @param string
 *   The entity $field.
 * @param int $id
 *   The entity'd id.
 * @param int $value
 *   The new value of the entity field.
 * @param int $delta
 *   The delta of the entity field.
 * @return boolean
 *   Whether we managed to change the field value.
 *
 * @see itoggle_ajax_callback()
 */
function _itoggle_ajax_toggle_field($type, $bundle, $field, $id, $value, $delta = 0) {
  $access = FALSE;

  // Check permissions.
  switch ($type) {
    case 'node':
      $node = node_load($id);
      $user = user_uid_optional_load();

      $access = user_access('administer nodes', $user)
        || user_access('bypass node access')
        || user_access("edit any {$bundle} content", $user)
        || ($node->uid == $user->uid && user_access("edit own {$bundle} content", $user));
      break;
    case 'user':
      $access = user_access('administer users');
      break;
    case 'taxonomy_term':
    case 'taxomomy_vocabulary':
      $access = user_access('administer taxonomy');
      break;
    default:
      $info = itoggle_get_entity_info();
      // Try to use access callback if available.
      if (isset($info[$type]['access callback'])) {
        $entity = entity_load_single($type, $id);
        $access = call_user_func($info[$type]['access callback'], 'edit', $entity);
      }
      // Fallback to generic catch-all permission.
      else {
        $access = user_access('administer site configuration');
      }
  }

  if ($access) {
    if ($entity = entity_load_single($type, $id)) {
//      $lang = $entity->language;
      $lang = LANGUAGE_NONE;
      $entity->{$field}[$lang][$delta] = $value;

      try {
        $return = entity_save($type, $entity) !== FALSE;
      }
      catch (Exception $e) {
        // Fail silently.
        $return = FALSE;
      }

      return $return !== FALSE;
    }
  }

  return FALSE;
}

/**
 * Change an entity property's value.
 *
 * @param string
 *   The entity $type.
 * @param string
 *   The entity $property.
 * @param int $id
 *   The entity'd id.
 * @param int $value
 *   The new value of the entity property.
 * @return boolean
 *   Whether we managed to change the property value.
 *
 * @see itoggle_ajax_callback()
 */
function _itoggle_ajax_toggle_entity($type, $property, $id, $value) {
  $access = FALSE;

  // Check permissions.
  switch ($type) {
    case 'node':
      $access = user_access('bypass node access') || user_access('administer nodes');
      break;
    case 'user':
      $access = user_access('administer users');
      break;
    case 'taxonomy_term':
    case 'taxomomy_vocabulary':
      $access = user_access('administer taxonomy');
      break;
    default:
      $info = itoggle_get_entity_info();
      // Try to use access callback if available.
      if (isset($info[$type]['access callback'])) {
        $entity = entity_load_single($type, $id);
        $access = call_user_func($info[$type]['access callback'], 'edit', $entity);
      }
      // Fallback to generic catch-all permission.
      else {
        $access = user_access('administer site configuration');
      }
  }

  if (!$access && $type === 'node' && module_exists('override_node_options')) {
    if ($node = node_load($id)) {
      switch ($property) {
        case 'status':
          $prop = 'published';
          break;
        case 'promote':
          $prop = 'promote to front page';
          break;
        case 'sticky':
          $prop = 'sticky';
          break;
        default:
          // Prevent errors, access check will fail anyway.
          $prop = '';
          break;
      }

      $access = user_access("override {$node->type} {$prop} option");
    }
  }

  if ($access === TRUE) {
    if ($entity = entity_load_single($type, $id)) {
      $entity->{$property} = $value;

      try {
        $return = entity_save($type, $entity) !== FALSE;
      }
      catch (Exception $e) {
        // Fail silently.
        $return = FALSE;
      }

      return $return !== FALSE;
    }
  }

  return FALSE;
}
