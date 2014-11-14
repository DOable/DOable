<?php
/**
 * @file
 * doable_solutions.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function doable_solutions_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'browse_solutions';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 999999;
  $quicktabs->title = 'Browse Solutions';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_tags_browse_by-block',
      'hide_title' => 1,
      'title' => 'Tags',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_tags_browse_by-block_1',
      'hide_title' => 1,
      'title' => 'Sector',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'views_delta_tags_browse_by-block_2',
      'hide_title' => 1,
      'title' => 'Carbon Sources',
      'weight' => '-98',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'accordion';
  $quicktabs->style = 'Basic';
  $quicktabs->options = array(
    'history' => 0,
    'jquery_ui' => array(
      'autoHeight' => 0,
      'collapsible' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Browse Solutions');
  t('Carbon Sources');
  t('Sector');
  t('Tags');

  $export['browse_solutions'] = $quicktabs;

  return $export;
}
