<?php

/**
 * @file
 * Defines a guestpass user.
 */

/**
 * Some constants
 */
define('GUEST_LINK_CRUMB', 'guest');

/**
 * Implements hook_help().
 *
 * @param $section
 *   string file path
 *
 * @return
 *   string
 */
function guestpass_help($page = 'admin/help#guestpass', $arg) {
  switch ($page) {
    case 'admin/help#guestpass':
      return t('<p>This module does stuff</p>');
    case 'admin/config/people/guestpass':
      return t('<p>Here be settings for Guestpass.</p>');
    case 'node/%node/guestpass':
      return t('<p> Creat a guestpass to share a link.</p>');
  }
}

/**
 * Implements hook_permission().
 *
 * @return
 *   array of permissions
 */
function guestpass_permission() {
  return array(
    'create a guestpass for own content' => array(
      'title' => t('Create a guestpass for own content'),
      'description' => t('Create a guestpass for own content'),
      'restrict access' => TRUE,
    ),
    'delete a guestpass for own content' => array(
      'title' => t('Delete a guestpass for own content'),
      'description' => t('Delete a guestpass for own content'),
      'restrict access' => TRUE,
    ),
    'adminster guestpasses' => array(
      'title' => t('Adminster guestpasses'),
      'description' => t('Adminster guestpasses'),
      'restrict access' => TRUE,
    ),
  );
}

/**
 * Implements hook_menu().
 *
 * @return
 *   array of menu information
 */
function guestpass_menu() {
  global $user;
  $items = array();
  $items['guest/%'] = array(
    'page callback' => 'guestpass_login_redirect_view',
    'page arguments' => array(1),
    'type' => MENU_CALLBACK,
    'access callback' => TRUE,
  );
  $items['node/%node/guestpass'] = array(
    'title' => 'Guestpass',
    'page arguments' => array('guestpass_create_guestpass_form', 1),
    'page callback' => 'drupal_get_form',
    'access arguments' => array('create a guestpass for own content', 1),
    'access callback' => 'guestpass_create_access',
    'type' => MENU_LOCAL_TASK,
  );
  $items['admin/config/people/guestpass'] = array(
    'title' => 'Guestpass Settings',
    'page arguments' => array('guestpass_admin_settings'),
    'page callback' => 'drupal_get_form',
    'access arguments' => array('administer site configuration'),
    'description' => 'Global configuration for guestpasses',
    'file' => 'guestpass.admin.inc',
    'type' => MENU_NORMAL_ITEM,
  );
  
  return $items;
}
/**
 * Defines the access callback for the guestpass tab
 */
function guestpass_create_access($op, $node) {
  $node_types = variable_get('node_types');
  if(!strcmp($node_types[$node->type], $node->type)){
    global $user;
    if ($user->uid == $node->uid) {
      return TRUE;
    }
  }
  return FALSE;
}


/**
 * Implements hook_cron().
 * Deletes guest users whose accounts are older than what is specified in the admin settings.
 *
 */
function guestpass_cron() {
  $cron_setting = variable_get('guestpass_time_autodelete', 0);
  $delta_time = variable_get('guestpass_delay', 3600);

  // If time to wait is set to never or cron is not enabled do nothing.
  if ($delta_time == 'never' || $cron_setting == 1) {
  }
  else {
    $result = db_query("SELECT * FROM {guestpass_guests} order by created")->fetchAll();
    foreach ($result as $res) {
      if ($res->created + $delta_time < time()) {
        user_delete($res->guest_uid);
        db_delete('guestpass_guests')
          ->condition('guest_uid', $res->guest_uid)
          ->execute();
      }
    }
  }
}

/**
 * Page to create, view, and delete guestpasses
 */
function guestpass_create_guestpass_form($form, &$form_state, $node) {
  global $user, $base_root;
  $header = array(
    'guest_link' => array('data' => t('Guestpass Link'), 'field' => 'g.guest_link'),
    'redirect_url' => array('data' => t('Page'), 'field' => 'g.redirect_url'),
  );
  $gps = db_query('SELECT * FROM {guestpass_relationships} WHERE host_uid = :host_uid', array(':host_uid' => $user->uid)) -> fetchAll();

  $options = array();
  foreach ($gps as $gp) {
    $options[$gp->guest_link] = array(
      'guest_link' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => check_plain($base_root . base_path() . $gp->guest_link),
          '#href' => $base_root . base_path() . $gp->guest_link,
        ),
      ),
      'redirect_url' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => check_plain($base_root . base_path() . $gp->redirect_url),
          '#href' => $base_root . base_path() . $gp->redirect_url,
        ),
      ),
    );
  }
  $form = array();
  $form['existing_guestpasses'] = array(
    '#type' => 'fieldset',
    '#title' => 'Guestpasses',
    '#weight' => 0,
  );
  $form['existing_guestpasses']['guestpasses'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('You currently do not have any guestpasses to share.'),
    '#multiple' => TRUE,
    '#weight' => 0,
  );
    $form['existing_guestpasses']['submit'] = array(
    '#type' => 'button',
    '#value' => t('Delete Selected Guestpass'),
    '#submit' => array('guestpass_delete_submit'),
    '#executes_submit_callback' => TRUE,
    '#weight' => 10,
  );

  $form['create_guestpass'] = array(
    '#type' => 'fieldset',
    '#title' => 'Create Guestpass',
    '#weight' => 1,
  );
  $form['create_guestpass']['guest_link'] = array(
    '#type' => 'value',
    '#value' => _random_url(GUEST_LINK_CRUMB, 16),
  );
  $form['create_guestpass']['nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );
  $form['create_guestpass']['host_uid'] = array(
    '#type' => 'value',
    '#value' => $user->uid,
  );
  if(variable_get('email_settings') == 0){
    $form['create_guestpass']['send_to_email'] = array(
      '#type' => 'textfield',
      '#title' => 'Recipient',
      '#description' => 'Email address of recipient.',
      //'#required' => TRUE,
    );
    $form['create_guestpass']['custom_message'] = array(
      '#type' => 'textarea',
      '#title' => 'Message',
      '#description' => 'Enter a personalized message.'
    );
  }
  
  $form['create_guestpass']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create guestpass'),
  );
  
  return $form;
}
/**
 * Implements validate guestpass form
 */
// function guestpass_create_guestpass_form_validate($form, &$form_state) {
  // if(variable_get('email_settings') == 0){
    // if (!_check_email_address($form_state['values']['send_to_email'])) {
      // form_set_error('', t('It appears you have entered an invalid email recipient.'));
    // }
  // }
// }
/**
 * Implements create guestpass button
 */
function guestpass_create_guestpass_form_submit($form, &$form_state) {
  global $base_root;
  $host_user = $form_state['values']['host_uid'];
  $guestpass_link = $form_state['values']['guest_link'];
  $nid = $form_state['values']['nid'];
  $redirect_page = 'node/' . $nid;
  _create_guest_link($host_user, $guestpass_link, $redirect_page);
  drupal_set_message($base_root . base_path()  . $guestpass_link, 'guestpass', TRUE);
  $recipient = $form_state['values']['send_to_email'];
  $custom_message = $form_state['values']['custom_message'];
  if(variable_get('email_settings') == 0 && $recipient != ''){
    guestpass_send_email($recipient, $custom_message, $guestpass_link);
    drupal_set_message('An email has been sent to '. $recipient, 'guestpass', TRUE);
  }
  drupal_goto('node/' . $nid);
}
/**
 * Callback for the delete button on the guestpass table.
 */
function guestpass_delete_submit($form, &$form_state) {
  global $user, $base_root;
  //drupal_set_message('Deleted a guestpass', 'alert' );
  $nid = $form_state['values']['nid'];
  // array_filter returns only elements with TRUE values
  $selected = $form_state['values']['guestpasses'];
  foreach ($selected as $key) {
    if ($key != '0') {
    drupal_set_message(check_plain('Deleted the guestpass ' . $base_root . base_path() . $key), 'alert');
    db_delete('guestpass_relationships')
      ->condition('guest_link', $key)
      ->execute();
    }
  }

  drupal_goto('node/' . $nid . '/guestpass');
}
/**
 * Login and redirect the guest user
 */
function guestpass_login_redirect_view($guest_link_slug) {
  global $user;
  $guest_link = GUEST_LINK_CRUMB . '/' . $guest_link_slug;
  if (!$user -> uid) {
    $new_guest = _create_guest_user($guest_link);
    $form_state['uid'] = $new_guest -> uid;
    user_login_submit(array(), $form_state);
    drupal_set_message('You are viewing this site with a guestpass.', 'guestpass', TRUE);
  }
  $relationship = db_query('SELECT * FROM {guestpass_relationships} WHERE guest_link = :my_link', array(':my_link' => $guest_link)) -> fetchObject();
  $redirect_page = $relationship->redirect_url;
  drupal_goto($redirect_page);

}

/**
 * Generate a random string
 */
function _random_string($len = 16) {
  $length = $len;
  $characters = '0123456789abcdefghijklmnopqrstuvwxyz';
  $string = '';
  for ($p = 0; $p < $length; $p++) {
      $string .= $characters[mt_rand(0, drupal_strlen($characters)-1)];
  }
  return $string;
}
/**
 * Generate a random URL
 */
function _random_url($crumb, $len = 16) {
  $rand_string = _random_string($len);
  $randURL = $crumb . '/' . $rand_string;
  return $randURL;
}
/**
 * Generate a random username
 */
function _rand_username($prefix, $len = 16) {
  $rand_string = _random_string($len);
  $randName = $prefix . '_' . $rand_string;
  return $randName;
}
/**
 * Generate dummy email address
 */
function _rand_email($domain, $len = 16) {
  $rand_string = _random_string($len);
  $randEmail = $rand_string . '@' . $domain;
  return $randEmail;
}
/**
 * Create guest link.
 */
function _create_guest_link($host_user, $guestpass_link, $redirect_page) {
  $link = $guestpass_link;
  $relationship = array(
    'host_uid' => $host_user,
    'redirect_url' => $redirect_page,
    'guest_link' => $link,
  );
  drupal_write_record('guestpass_relationships', $relationship);
  module_invoke_all('create_guestpass', user_load($host_user));
  return $link;
}
/**
 * Create guest user
 */
function _create_guest_user($guest_link) {
  // create a new user with junk username/password/email
  $guest_role = user_role_load_by_name('guest');
  $guestaccount = array(
    'name' => _rand_username(GUEST_LINK_CRUMB, 16),
    'pass' => user_password(10),
    'mail' => _rand_email('nomail.local', 16),
    'status' => 1,
    'roles' => array($guest_role->rid => 'guest'),
    'init' => 'email address',
  );
  $new_user = user_save(drupal_anonymous_user(), $guestaccount);

  // put the user in the guestpass_guest table so we know s/he's a guest user
  $guest = array(
    'guest_link' => $guest_link,
    'guest_uid' => $new_user->uid,
    'created' => time(),
  );
  drupal_write_record('guestpass_guests', $guest);
  module_invoke_all('create_guestuser', $guest);
  return $new_user;
}

function guestpass_send_email($recipient, $custom_message, $guestpass_link){
  global $user, $base_root;
    $module = 'guestpass';
    $key = '$user';
    $language = language_default();
    $params = array();
    $from = $user->mail;
    $send = FALSE;
    $message = drupal_mail($module, $key, $recipient, $language, $params, $from, $send);

    $message['subject'] = variable_get('message_title');
    $message['body'] = array();
    $message['body'][] = $custom_message;
    $default_message = variable_get('default_message');
    $default_message = str_replace('<site_name>', variable_get('site_name', "Default site name"), $default_message);
    $default_message = str_replace('<guest_link>', $base_root . base_path() . $guestpass_link, $default_message);
    $message['body'][] = $default_message;

    // Retrieve the responsible implementation for this message.
    $system = drupal_mail_system($module, $key);

    // Format the message body.
    $message = $system->format($message);

    // Send e-mail.
    $message['result'] = $system->mail($message);
}
function _check_email_address($email) {
  // First, we check that there's one @ symbol, 
  // and that the lengths are right.
  if (!ereg("^[^@]{1,64}@[^@]{1,255}$", $email)) {
    // Email invalid because wrong number of characters 
    // in one section or wrong number of @ symbols.
    return false;
  }
  // Split it into sections to make life easier
  $email_array = explode("@", $email);
  $local_array = explode(".", $email_array[0]);
  for ($i = 0; $i < sizeof($local_array); $i++) {
    if
(!ereg("^(([A-Za-z0-9!#$%&'*+/=?^_`{|}~-][A-Za-z0-9!#$%&
↪'*+/=?^_`{|}~\.-]{0,63})|(\"[^(\\|\")]{0,62}\"))$",
$local_array[$i])) {
      return false;
    }
  }
  // Check if domain is IP. If not, 
  // it should be valid domain name
  if (!ereg("^\[?[0-9\.]+\]?$", $email_array[1])) {
    $domain_array = explode(".", $email_array[1]);
    if (sizeof($domain_array) < 2) {
        return false; // Not enough parts to domain
    }
    for ($i = 0; $i < sizeof($domain_array); $i++) {
      if
(!ereg("^(([A-Za-z0-9][A-Za-z0-9-]{0,61}[A-Za-z0-9])|
↪([A-Za-z0-9]+))$",
$domain_array[$i])) {
        return false;
      }
    }
  }
  return true;
}