<?php


/**
 * @file
 *
 */

/**
 * Widget that renders facets as a list of clickable links.
 */
class FacetapiWidgetLocation extends FacetapiWidgetLinks {
  /**
   * Overrides FacetapiWidgetLinks::init().
   *
   * Adds additional JavaScript settings and CSS.
   */
  public function init() {
    parent::init();
  }
  
  /**
   * Overrides FacetapiWidget::settingsForm().
   */
  function settingsForm(&$form, &$form_state) {

    $form['widget']['widget_settings']['location'][$this->id]['radius'] = array(
      '#type' => 'textfield',
      '#title' => t('Radius'),
      '#default_value' => $this->settings->settings['radius'],
      '#description' => t('Set the radius of the location center point'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['location'][$this->id]['center_point'] = array(
      '#type' => 'textfield',
      '#title' => t('Center Point'),
      '#default_value' => $this->settings->settings['center_point'],
      '#description' => t('Sets the center point coordinate'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['location'][$this->id]['facet_options'] = array(
      '#type' => 'textfield',
      '#title' => t('Facet Options'),
      '#default_value' => $this->settings->settings['facet_options'],
      '#description' => t('Set the amount of facet options'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    
    // Hides all but the last element. The #states system will override this,
    // however it is necessary if JavaScript is disabled so multiple elements
    // aren't displayed to the user.
    $last = end($form['widget']['widget_settings']['location']);
    foreach ($form['widget']['widget_settings']['location'] as $id => $element) {
      if ($last != $element) {
        $form['widget']['widget_settings']['location'][$id]['#attributes']['style'] = 'display: none;';
      }
    }
  }
    /**
   * Overrides FacetapiWidget::getDefaultSettings().
   */
  function getDefaultSettings() {
    return array(
      'facet_options' => '0.5,0.1,0.01',
      'center_point' => '39.7391667,-104.9841667',
      'radius' => 1000000,
    );
  }
}
