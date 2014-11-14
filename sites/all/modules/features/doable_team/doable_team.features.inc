<?php
/**
 * @file
 * doable_team.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function doable_team_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function doable_team_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
