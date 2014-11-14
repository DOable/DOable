<?php
/**
 * @file
 * doable_press_coverage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function doable_press_coverage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function doable_press_coverage_node_info() {
  $items = array(
    'press_coverage' => array(
      'name' => t('Press Coverage'),
      'base' => 'node_content',
      'description' => t('A content type for Press Coverage about the Nation'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
