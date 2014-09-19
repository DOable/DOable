<?php
/**
 * Implements admin settingpage.
 *
 * @return
 *  array of form elements
 */
function guestpass_admin_settings() {
  $nta = node_type_get_types();
  $node_types = array();
  foreach($nta as $nt){
    $node_types[$nt->type] = $nt->type;
  }

  // Node settings
  $form['guestpass']['node'] = array(
    '#type' => 'fieldset',
    '#title' => t('Node type settings.'),
    '#collapsible' => TRUE,
    '#collapsed' => 1,
    '#description' => t('The the types of nodes to associate with Guestpass.'),
  );
  $form['guestpass']['node']['node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Nodes types'),
    '#description' => t('A guestlink local menu item will appear on the selected node types'),
    '#multiple' => TRUE,
    '#options' => $node_types,
    '#default_value' => variable_get('node_types'),
  );
  
  // Email settings.
  $form['guestpass']['email'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email settings.'),
    '#collapsible' => TRUE,
    '#collapsed' => 1,
    '#description' => t('The email sent when a guestpass is created.'),
  );
  $form['guestpass']['email']['email_settings'] = array(
    '#type' => 'radios',
    '#title' => t('Send email to guest when guestpass created'),
    '#default_value' => variable_get('email_settings', 0),
    '#options' => array(0 => t('Email Guest'), 1 => t('No email')),
  );
  $form['guestpass']['email']['message_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Email message title'),
    '#default_value' => t('Guestpass from ' . variable_get('site_name', "Default site name")),
  );
  $form['guestpass']['email']['default_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Email message'),
    '#suffix' => t('Use &lt;guest_link&gt; to insert a link to the guestpass page and &lt;site_name&gt; for the name of the site.'),
    '#default_value' => t('You have been sent a guestpass from <site_name>: <guest_link>'),
  );
  // Cron settings.
  $form['guestpass']['cron'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cron settings.'),
    '#collapsible' => TRUE,
    '#collapsed' => 1,
    '#description' => t('Automatically delete guestpass guest accounts after a certain amount of time has elapsed.'),
  );
  $form['guestpass']['cron']['guestpass_time_autodelete'] = array(
    '#type' => 'radios',
    '#title' => t('Should guestpass guest accounts be automatically deleted?'),
    '#default_value' => variable_get('guestpass_time_autodelete', 0),
    '#options' => array(0 => t('Automatically delete'), 1 => t('Do Nothing')),
  );
  $form['guestpass']['cron']['guestpass_delay'] = array(
    "#type" => 'select',
    '#title' => t('Time until automatic action is taken'),
    '#default_value' => variable_get('guestpass_delay', 3600),
    '#options' => array(
      3600 => t('1 hour'),
      7200 => t('2 hours'),
      14400 => t('4 hours'),
      21600 => t('6 hours'),
      43200 => t('12 hours'),
      86400 => t('1 day'),
      172800 => t('2 days'),
      259200 => t('3 days'),
      432000 => t('5 days'),
      604800 => t('1 week'),
      1201600 => t('2 weeks'),
      'never' => t('never'),
    ),
    '#suffix' => t('<div class="description">NOTE: Cron must be enabled and configured for Time-based settings to work.</div>'),
  );
  return system_settings_form($form['guestpass']);
}
