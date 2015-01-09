<?php
/**
 * @file
 * iToggle settings.
 */

/**
 * Form callback.
 *
 * Return iToggle settings form.
 *
 * @see itoggle_menu().
 */
function itoggle_form_admin() {
  $form = array();

  $form['itoggle']['basic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Basic Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['itoggle']['basic']['itoggle_compression_type'] = array(
    '#type' => 'radios',
    '#title' => t('Choose iToggle compression level'),
    '#options' => array(
      'min' => t('Production (Minified)'),
      'none' => t('Development (Uncompressed Code)'),
    ),
    '#default_value' => variable_get('itoggle_compression_type', 'min'),
  );

  $form['itoggle']['basic']['itoggle_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include Default CSS'),
    '#description' => t('Uncheck this if you want to include your own styles for iToggle.'),
    '#default_value' => variable_get('itoggle_css', TRUE),
  );

  $form['itoggle']['basic']['itoggle_speed'] = array(
    '#type' => 'textfield',
    '#size' => 4  ,
    '#title' => t('Animation Speed'),
    '#description' => t('iToggle animation speed, in milliseconds. Default is 200.'),
    '#default_value' => variable_get('itoggle_speed', 200),
  );

  $form['itoggle']['basic']['easing'] = array(
    '#type' => 'fieldset',
    '#title' => t('Easing'),
    '#description' => t('If you install the <a href="@easing_module">jQuery Easing</a> module you can specify an <a href="@easing_library">easing</a> function for iToggle here.', array('@easing_module' => 'https://drupal.org/project/jqeasing', '@easing_library' => 'http://gsgd.co.uk/sandbox/jquery/easing')),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  // Support the jquery.easing plugin via the jQuery Easing module.
  if (module_exists('jqeasing')) {
    $easing_options = _itoggle_jqeasing_options();

    // Sort easing methods.
    ksort($easing_options);

    $form['itoggle']['basic']['easing']['itoggle_easing_function'] = array(
      '#type' => 'select',
      '#title' => t('Easing Function'),
      '#empty_option' => ' -None- ',
      '#description' => t("Specify an easing callback here. iToggle default is 'easeOutExpo'."),
      '#default_value' => variable_get('itoggle_easing_function', ''),
      '#options' => $easing_options,
    );
  }

  $form['advanced'] = array(
    '#title' => t('Advanced Settings'),
    '#type' => 'fieldset',
    '#description' => '<p>' . t('For a full description of all iToggle callbacks, see the <a href="@link">documentation</a>.', array('@link' => 'http://labs.engageinteractive.co.uk/itoggle/')) . '</p>',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['advanced']['note'] = array(
    '#markup' => '<strong>' . t('Important') . '</strong><p>' . t("All of these callbacks are automatically wrapped in a closure, so you do don't need to specify it, just enter the code directly.") . '</p>',
  );

  $form['advanced']['example'] = array(
    '#markup' => '<p>' . t('For example') . ':</p><code>alert("onclick");</code></p>',
  );

  $form['advanced']['warning'] = array(
    '#markup' => '<strong>' . t('Warning') . '</strong><p>' . t('The callbacks are called using eval(), yes, we hate it too so please be careful!') . '</p>',
  );

  $form['advanced']['advanced_confirm'] = array(
    '#type' => 'checkbox',
    '#title' => t('I confirm that I have read the above warnings and wish to configure callbacks for iToggle'),
    '#default_value' => FALSE,
  );

  $form['advanced']['container'] = array(
    '#type' => 'container',
    '#states' => array(
      'invisible' => array(
        'input[name="advanced_confirm"]' => array('checked' => FALSE),
      ),
    ),
  );

  $form['advanced']['container']['itoggle_onclick'] = array(
    '#title' => t('OnClick callback'),
    '#type' => 'textarea',
    '#description' => t('Specify an OnClick callback for iToggle.'),
    '#default_value' => variable_get('itoggle_onclick', ''),
  );

  $form['advanced']['container']['itoggle_onclickon'] = array(
    '#title' => t('OnClickOn callback'),
    '#type' => 'textarea',
    '#description' => t('Specify an OnClickOn callback for iToggle.'),
    '#default_value' => variable_get('itoggle_onclickon', ''),
  );

  $form['advanced']['container']['itoggle_onclickoff'] = array(
    '#title' => t('OnClickOff callback'),
    '#type' => 'textarea',
    '#description' => t('Specify an OnClickOff callback for iToggle.'),
    '#default_value' => variable_get('itoggle_onclickoff', ''),
  );

  $form['advanced']['container']['itoggle_onslide'] = array(
    '#title' => t('OnSlide callback'),
    '#type' => 'textarea',
    '#description' => t('Specify an OnSlide callback for iToggle.'),
    '#default_value' => variable_get('itoggle_onslide', ''),
  );

  $form['advanced']['container']['itoggle_onslideon'] = array(
    '#title' => t('OnSlideOn callback'),
    '#type' => 'textarea',
    '#description' => t('Specify an OnSlideOn callback for iToggle.'),
    '#default_value' => variable_get('itoggle_onslideon', ''),
  );

  $form['advanced']['container']['itoggle_onslideoff'] = array(
    '#title' => t('OnSlideOff callback'),
    '#type' => 'textarea',
    '#description' => t('Specify an OnSlideOff callback for iToggle.'),
    '#default_value' => variable_get('itoggle_onslideoff', ''),
  );

  return system_settings_form($form);
}

/**
 * List of all easing methods available from jQuery Easing v1.3.
 *
 * Note: This should really go in the jqeasing module. But we're keeping it here
 * since that module doesn't seem like it's getting updated too often.
 *
 * @return array
 */
function _itoggle_jqeasing_options() {
  $easing_methods = &drupal_static(__FUNCTION__);

  if (!isset($easing_methods)) {
    $easing_methods = array(
      'jswing',
      'def',
      'easeInQuad',
      'easeOutQuad',
      'easeInOutQuad',
      'easeInCubic',
      'easeOutCubic',
      'easeInOutCubic',
      'easeInQuart',
      'easeOutQuart',
      'easeInOutQuart',
      'easeInQuint',
      'easeOutQuint',
      'easeInOutQuint',
      'easeInSine',
      'easeOutSine',
      'easeInOutSine',
      'easeInExpo',
      'easeOutExpo',
      'easeInOutExpo',
      'easeInCirc',
      'easeOutCirc',
      'easeInOutCirc',
      'easeInElastic',
      'easeOutElastic',
      'easeInOutElastic',
      'easeInBack',
      'easeOutBack',
      'easeInOutBack',
      'easeInBounce',
      'easeOutBounce',
      'easeInOutBounce',
    );

    // Allow other modules to alter this.
    drupal_alter('itoggle_easing', $easing_methods);

    // Map this into an associative array.
    $easing_methods = drupal_map_assoc($easing_methods);
  }

  return $easing_methods;
}
