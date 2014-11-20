<?php
/**
 * @file
 * Provides an actionable element for pages.
 */

class PageActionableElement extends ActionableElementBase {

  /**
   * Implements ActionableElementInterface::getActionOptions().
   */
  public static function getActionOptions() {
    return array(
      'client' => array(
        'view' => t('views'),
        'scrollToBottom' => t('scrolls to the bottom of'),
        'stay' => t('stays for longer than the specified time on')
      )
    );
  }

  /**
   * Implements ActionableElementInterface::optionsForm().
   */
  public static function optionsForm($action = array()) {
    $form = array();
    $form['remains_for'] = array(
      '#type' => 'textfield',
      '#title' => t('Time in seconds'),
      '#description' => t('Enter the time in seconds after which the action should be triggered'),
      '#size' => 4,
      '#default_value' => isset($action['data']['time']) ? $action['data']['remains_for'] : 5,
      '#states' => array(
        'visible' => array(
          ':input[name="event[page]"]' => array('value' => 'client::stay'),
        ),
      )
    );
    $form['bottom_offset'] = array(
      '#type' => 'textfield',
      '#title' => t('Offset from bottom'),
      '#field_suffix' => t('pixels'),
      '#description' => t('Enter the number of pixels from the bottom that will trigger the action'),
      '#size' => 4,
      '#default_value' => isset($action['data']['bottom_offset']) ? $action['data']['bottom_offset'] : 100,
      '#states' => array(
        'visible' => array(
          ':input[name="event[page]"]' => array('value' => 'client::scrollToBottom'),
        )
      )
    );
    return $form;
  }

  /**
   * Implements ActionableElementInterface::validate().
   */
  public static function validate($values) {
    if (empty($values['pages'])) {
      form_set_error('pages', t('You must specify one or more pages'));
    }
  }
}
