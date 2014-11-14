<?php
/**
 * @file
 * doable_promos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function doable_promos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function doable_promos_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function doable_promos_eck_bundle_info() {
  $items = array(
    'promo_promo' => array(
      'machine_name' => 'promo_promo',
      'entity_type' => 'promo',
      'name' => 'promo',
      'label' => 'Promo',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function doable_promos_eck_entity_type_info() {
  $items = array(
    'promo' => array(
      'name' => 'promo',
      'label' => 'Promo',
      'properties' => array(
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
      ),
    ),
  );
  return $items;
}
