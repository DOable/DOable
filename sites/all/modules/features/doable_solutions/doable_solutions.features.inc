<?php
/**
 * @file
 * doable_solutions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function doable_solutions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function doable_solutions_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function doable_solutions_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow Solution".
  $flags['follow_solution'] = array(
    'content_type' => 'node',
    'title' => 'Follow Solution',
    'global' => 0,
    'types' => array(
      0 => 'solution',
    ),
    'flag_short' => 'Follow this Solution',
    'flag_long' => 'Please click to follow this Solution',
    'flag_message' => 'Your are now following this Solution',
    'unflag_short' => 'Stop Following this Solution',
    'unflag_long' => 'Please click to stop following this Solution',
    'unflag_message' => 'You are no longer following this Solution',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'doable_solutions',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function doable_solutions_node_info() {
  $items = array(
    'solution' => array(
      'name' => t('Solution'),
      'base' => 'node_content',
      'description' => t('A content type for projects that are delivering Solutions to Climate Change'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function doable_solutions_weight_features_default_settings() {
  $settings = array();

  $settings['solution'] = array(
    'enabled' => 0,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
