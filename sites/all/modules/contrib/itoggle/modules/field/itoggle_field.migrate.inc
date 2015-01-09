<?php
/**
 * @file
 * Migrate integration for iToggle Field.
 */

/**
 * Implements hook_migrate_api().
 */
function itoggle_field_migrate_api() {
  return array(
    'api' => 2,
    'field handlers' => array(
      'MigrateItoggleFieldHandler',
    ),
  );
}

/**
 * iToggle Field Migrate Field Handler Class
 *
 * This field only accepts one value and it can either be a simple 1 or 0
 * integer or a boolean.
 *
 * @code
 *   $this->addFieldMapping('field_itoggle', 1);
 *   $this->addFieldMapping('field_itoggle', FALSE);
 * @endcode
 */
class MigrateItoggleFieldHandler extends MigrateSimpleFieldHandler {
  public function __construct() {
    parent::__construct(array(
      'value_key' => 'value',
      'skip_empty' => FALSE,
    ));
    $this->registerTypes(array('itoggle_field'));
  }
}
