<?php

/**
 * Implements hook_views_plugins().
 */
function views_isotope_views_plugins() {
  return array(
    'style' => array(
      'isotope' => array(
        'title' => t('Isotope Grid'),
        'help' => t('Display the results using the jQuery Isotope plugin'),
        'handler' => 'views_isotope_plugin_style_isotope',
        'theme' => 'views_isotope',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
        'parent' => 'list',
        'theme file' => 'views_isotope.theme.inc',
      ),
      'isotope_filter_block' => array(
        'title' => t('Isotope Filter Block'),
        'help' => t('Display the results formatted to filter an Isotope View'),
        'handler' => 'views_isotope_plugin_style_isotope',
        'theme' => 'views_isotope_filter_block',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
        'parent' => 'list',
        'theme file' => 'views_isotope.theme.inc',
      ),

    ),
  );
}
