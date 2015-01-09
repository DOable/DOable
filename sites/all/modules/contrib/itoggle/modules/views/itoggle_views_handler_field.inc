<?php
/**
 * @file
 * Views field handler for iToggle Views.
 */

/**
 * A handler to provide a custom field for iToggle.
 *
 * @ingroup views_field_handlers
 */
class itoggle_views_handler_field extends views_handler_field {

  protected $_itoggle;

  function init(&$view, &$options) {
    // Find out the field name (ie what entity type and what property).
    $field_name = str_replace('itoggle-', '', $options['id']);
    list ($type, $property) = explode('-', $field_name);
    // Trim suffix if multiple widgets in view.
    list($property) = explode('_', $property);
    $entity_info = entity_get_info($type);

    // Store information in instance.
    $this->_itoggle = array(
      'id' => $entity_info['entity keys']['id'],
      'type' => $type,
      'property' => $property,
    );

    // Add id as additional field.
    $this->additional_fields[$this->_itoggle['id']] = $this->_itoggle['id'];

    parent::init($view, $options);
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render the trigger field and its linked popup information.
   */
  function render($values) {
    $type = $this->_itoggle['type'];
    $property = $this->_itoggle['property'];
    $id = $this->_itoggle['id'];

    // Special case with comments.
    if ($type === 'node' && isset($values->comment_nid)) {
      $values->nid = $values->comment_nid;
    }

    if (isset($values->{$id})) {
      $id = $values->{$id};

      // Check if property value already exists in $values array before
      // loading entity.
      if (array_key_exists($property, $values)) {
        $value = $values->{$property};
      }
      else if (array_key_exists("{$type}_{$property}", $values)) {
        $value = $values->{"{$type}_{$property}"};
      }
      // No go, gotta load the entity.
      else {
        $entity = current(entity_load($type, array($id)));
        $value = $entity->{$property};
      }

      $clickable = $this->options['itoggle_clickable'];
      $display_type = $this->options['itoggle_display_type'];

      return array(
        '#theme' => 'itoggle',
        '#type' => $type,
        '#id' => $id,
        '#property' => $property,
        '#checked' => (bool) $value,
        '#scope' => 'entity',
        '#clickable' => $clickable,
        '#display_type' => $display_type,
       );
    }
    return NULL;
  }

  /**
   * Called to determine what to tell the clicksorter.
   */
  function click_sort($order) {
    $property = $this->_itoggle['property'];

    if (isset($this->field_alias)) {
      // Since fields should always have themselves already added, just
      // add a sort on the field.
      $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type'])
          : array();
      $this->query->add_orderby(NULL, NULL, $order, $property, $params);
    }
  }

  /**
   * iToggle field options.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['itoggle_clickable'] = array('default' => TRUE, 'bool' => TRUE);
    $options['itoggle_display_type'] = array('default' => 0);
    return $options;
  }

  /**
   * iToggle field options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['itoggle'] = array(
      '#type' => 'fieldset',
      '#title' => t('iToggle'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -1,
      '#tree' => TRUE,
    );

    // Prefix options with module name to avoid conflicts.
    $clickable = $this->options['itoggle_clickable'];
    $display_type = $this->options['itoggle_display_type'];
    $options_form = itoggle_get_options_form($clickable, $display_type);

    // Add extra messages in Views UI.
    $options_form['warning_views'] = array(
      '#markup' => '<p><strong>' . t('You will have to save the View and refresh the page to see the iToggle widget.') . '</strong></p>',
      '#weight' => -4,
    );
    $options_form['clickable']['#description'] .= '<br/><strong>' . t("Regardless of your choice, the widget won't be clickable in the Views preview.") . '</strong>';

    // Wrap the form in a fieldset.
    foreach ($options_form as $key => $value) {
      $form['itoggle'][$key] = $value;
    }
  }

  /**
   * iToggle field options submit callback.
   */
  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
    $options = $form_state['values']['options']['itoggle'];
    unset($form_state['values']['options']['itoggle']);

    // Prefix options with module name to avoid conflicts.
    $form_state['values']['options']['itoggle_clickable'] = $options['clickable'];
    $form_state['values']['options']['itoggle_display_type'] = $options['display_type'];
  }

}