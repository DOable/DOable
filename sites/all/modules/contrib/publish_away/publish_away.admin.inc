<?php
/**
 * @file
 * Content publish away and module settings.
 */

/**
 * FormsAPI for configuring the publish away module.
 */
function publish_away_admin_form($form, $form_state, $domain_id = 1) {
  global $publish_away_domain_id;
  $publish_away_domain_id = $domain_id;
  drupal_set_title('Publish away your contents');
  $form = array();
  $form['#tree'] = TRUE;
  $output = '<p>' . t("This module is used to post the Tweet and Facebook status with Image from your content forms.") . '</p>';
  $form['#prefix'] = $output;
  // If domain module is used.
  if (module_exists('domain') && function_exists('domain_domains')) {
    $form['domains'] = array(
      '#type' => 'fieldset',
      '#title' => t('Domains'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => ''
    );
    $domains_list = array();
    foreach (domain_domains() as $data) {
      // The domain must be valid.
      if ($publish_away_domain_id != $data['domain_id'] && ($data['valid']
        || user_access('access inactive domains'))) {
        // Filter checkbox output but not select list.
        $options[$data['domain_id']] = empty($format) ? check_plain($data['sitename']) : $data['sitename'];
        $domains_list[$data['domain_id']] = l(check_plain($data['sitename']),
        'admin/config/services/publish-away/' . $data['domain_id']);
      }
    }
    if (!empty($domains_list)) {
      $form['domains']['choices'] = array(
        '#markup' => theme('item_list', array('items' => $domains_list, 'type' => 'ul'))
      );
    }
  }
  // Facebook connect.
  $account_set = publish_away_fb_login();
  // Twitter connect.
  $account_set .= publish_away_twitter_login();
  // End Facebook connect.
  $form['fb_connect_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Accounts'),
    '#collapsible' => TRUE,
  );
  $form['fb_connect_fieldset']['fb_connect'] = array(
    '#markup' => $account_set,
  );
  // Facebook settings.
  $form['facebook'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Get your Facebook API keys on <a href="https://developers.facebook.com" target="_blank">https://developers.facebook.com</a> and do not forget to authorize the application to post new status by using 
      this link<br /> https://graph.facebook.com/oauth/authorize?client_id=[FB_APP_ID]&redirect_uri=http://'.$_SERVER['HTTP_HOST'] . '/' . current_path() . '&scope=publish_stream,offline_access,manage_pages,publish_actions'),
  );
  $form['facebook']['publish_away_fb_appId'] = array(
    '#title' => t('AppId'),
    '#type' => 'textfield',
    '#default_value' => publish_away_get('publish_away_fb_appId', NULL),
    '#required' => FALSE,
    // '#disabled' => publish_away_get('publish_away_fb_token', NULL) != NULL,
  );
  $form['facebook']['publish_away_fb_secret'] = array(
    '#title' => t('Secret key'),
    '#type' => 'textfield',
    '#default_value' => publish_away_get('publish_away_fb_secret', NULL),
    '#required' => FALSE,
    // '#disabled' => publish_away_get('publish_away_fb_token', '') != NULL,
  );
  $form['facebook']['publish_away_fb_page_id'] = array(
    '#title' => t('Facebook Page ID'),
    '#type' => 'textfield',
    '#default_value' => publish_away_get('publish_away_fb_page_id', NULL),
    '#required' => FALSE,
  );
  // Twitter settings.
  $form['twitter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Get your Twitter API keys on <a href="@twitterurl" target="_blank">@twitterurl</a>', array('@twitterurl' => 'https://dev.twitter.com'))
  );
  $form['twitter']['publish_away_consumer_key'] = array(
    '#title' => t('Consumer key'),
    '#type' => 'textfield',
    '#default_value' => publish_away_get('publish_away_consumer_key', NULL),
    '#required' => FALSE,
  );
  $form['twitter']['publish_away_consumer_secret'] = array(
    '#title' => t('Consumer secret key'),
    '#type' => 'textfield',
    '#default_value' => publish_away_get('publish_away_consumer_secret', NULL),
    '#required' => FALSE,
  );
  $form['twitter']['publish_away_oauth_token'] = array(
    '#title' => t('Access token'),
    '#type' => 'textfield',
    '#default_value' => publish_away_get('publish_away_oauth_token', NULL),
    '#required' => FALSE,
  );
  $form['twitter']['publish_away_oauth_token_secret'] = array(
    '#title' => t('Access token secret'),
    '#type' => 'textfield',
    '#default_value' => publish_away_get('publish_away_oauth_token_secret', NULL),
    '#required' => FALSE,
  );
  // Bitly settings.
  $form['bitly'] = array(
    '#type' => 'fieldset',
    '#title' => t('Bitly settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Get your Bilty API Keys on https://bitly.com. To shorten the links visit <a href="@bitlyurl" target="_blank" >@bitlyurl</a> and get your Bilty API Key', array('@bitlyurl' => 'https://bitly.com/a/your_api_key')),
  );
  $form['bitly']['publish_away_bitly_username'] = array(
    '#title' => t('Bitly username'),
    '#type' => 'textfield',
    '#default_value' => publish_away_get('publish_away_bitly_username', NULL),
    '#required' => FALSE,
  );
  $form['bitly']['publish_away_bitly_apikey'] = array(
    '#title' => t('Bitly API Key'),
    '#type' => 'textfield',
    '#default_value' => publish_away_get('publish_away_bitly_apikey', NULL),
    '#required' => FALSE,
  );
  // Content types.
  $form['content-types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content types settings'),
    '#collapsible' => TRUE,
  );
  $types = array();
  foreach (node_type_get_types() as $type => $info) {
    $types += array($type => $info->name);
  }
  $form['content-types']['publish_away_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Allow publish away action for the following content types :'),
    '#default_value' => publish_away_get('publish_away_types', array()),
    '#options' => $types,
  );
  
  $form['#submit'][] = 'publish_away_admin_form_submit';
  
  return system_settings_form($form);
}

/**
 * Implement publish_away_admin_form validate hook.
 */
function publish_away_admin_form_validate($form, &$form_state) {
  form_state_values_clean($form_state);
  if (!empty($form_state['values']['facebook'])) {
    if ($form_state['values']['facebook']['publish_away_fb_appId'] == '' && $form_state['values']['facebook']['publish_away_fb_secret'] != '') {
      form_set_error('facebook][publish_away_fb_appId', t('AppId is missing.'));
    }
    if (($form_state['values']['facebook']['publish_away_fb_appId'] != '' && $form_state['values']['facebook']['publish_away_fb_secret'] == '')) {
      form_set_error('facebook][publish_away_fb_secret', t('Secret key is missing.'));
    }
  }
  if (!empty($form_state['values']['twitter'])) {
    if ($form_state['values']['twitter']['publish_away_consumer_key'] != '' && $form_state['values']['twitter']['publish_away_consumer_secret'] == '') {
      form_set_error('twitter][publish_away_consumer_secret', t('Consumer secret key is missing.'));
    }
    if ($form_state['values']['twitter']['publish_away_consumer_key'] == '' && $form_state['values']['twitter']['publish_away_consumer_secret'] != '') {
      form_set_error('twitter][publish_away_consumer_key', t('Consumer key is missing.'));
    }
    if ($form_state['values']['twitter']['publish_away_consumer_key'] != '' && $form_state['values']['twitter']['publish_away_consumer_secret'] == '') {
      form_set_error('twitter][publish_away_consumer_secret', t('Consumer secret key is missing.'));
    }
    if ($form_state['values']['twitter']['publish_away_consumer_key'] == '' && $form_state['values']['twitter']['publish_away_consumer_secret'] != '') {
      form_set_error('twitter][publish_away_consumer_key', t('Consumer key is missing.'));
    }
    if ($form_state['values']['twitter']['publish_away_consumer_key'] != '' && $form_state['values']['twitter']['publish_away_oauth_token'] == '') {
      form_set_error('twitter][publish_away_oauth_token', t('Access token'));
    }
    if ($form_state['values']['twitter']['publish_away_consumer_key'] != '' && $form_state['values']['twitter']['publish_away_oauth_token_secret'] == '') {
      form_set_error('twitter][publish_away_oauth_token_secret', t('Access token secret'));
    }
  }
  if (!empty($form_state['values']['bitly'])) {
    if ($form_state['values']['bitly']['publish_away_bitly_username'] == '' && $form_state['values']['bitly']['publish_away_bitly_apikey'] != '') {
      form_set_error('bitly][publish_away_bitly_username', t('Bitly username is missing.'));
    }
    if (($form_state['values']['bitly']['publish_away_bitly_username'] != '' && $form_state['values']['bitly']['publish_away_bitly_apikey'] == '')) {
      form_set_error('bitly][publish_away_bitly_apikey', t('Bitly API Key is missing.'));
    }
  }
}

/**
 * Implement publish_away_admin_form submit hook.
 */
function publish_away_admin_form_submit($form, &$form_state) {
  form_state_values_clean($form_state);
  if (!empty($form_state['values'])) {
    foreach ($form_state['values'] as $values) {
      if (!empty($values)) {
        foreach ($values as $key => $value) {
          publish_away_set($key, $value);
        }
      }
    }
  }
}

function publish_away_fb_login() {
  // Facebook connect.
  $facebook_html = '';
  $token_fb = publish_away_get('publish_away_fb_token', NULL);
  if (empty($token_fb) || trim($token_fb) == '') {
    module_load_include('inc', 'publish_away', 'facebook');
    $config = array(
      'appId'  => publish_away_get('publish_away_fb_appId', NULL),
      'secret' => publish_away_get('publish_away_fb_secret', NULL),
    );
    $facebook = new Facebook($config);
    if (!empty($facebook)) {
      $user_id = $facebook->getUser();
      if ($user_id) {
        // We have a user ID, so probably a logged in user.
        // If not, we'll get an exception, which we handle below.
        try {
          $user_profile = $facebook->api('/me','GET');
          publish_away_set('publish_away_fb_user_profile', $user_profile);
          publish_away_set('publish_away_fb_id', $user_profile['id']);
          publish_away_set('publish_away_fb_name', $user_profile['name']);
          $token = $facebook->getAccessToken();
          publish_away_set('publish_away_fb_token', $token);
        }
        catch(FacebookApiException $e) {
          // If the user is logged out, you can have a 
          // user ID even though the access token is invalid.
          // In this case, we'll get an exception, so we'll
          // just ask the user to login again here.
          $login_url = $facebook->getLoginUrl();
          $facebook_html .= 'Please <a href="' . $login_url . '">' . t('you need to connect the Facebook account which will display selected contents') . '.</a><br />';
          error_log($e->getType());
          error_log($e->getMessage());
        }   
      }
      else {
        // No user, print a link for the user to login.
        $login_url = $facebook->getLoginUrl();
        $facebook_html .= 'Please <a href="' . $login_url . '">' . t('you need to connect to the Facebook account which will display selected contents') . '.</a><br />';
      }
    }
  }
  elseif (!empty($token_fb) && publish_away_get('publish_away_fb_appId', NULL) != NULL) {
    $fb_profile = publish_away_get('publish_away_fb_user_profile');
    $facebook_html .= '<strong>' . t('Facebook account') . ' :</strong> ' . publish_away_get('publish_away_fb_name', NULL) . '<br />';
    if (isset($fb_profile['quotes']) && trim($fb_profile['quotes']) != '') {
      $facebook_html .= '<br /><strong>' . t('Last Facebook status') . ' :</strong> ' . $fb_profile['quotes'];
    }
    // $logout_url = 'admin/config/services/publish-away/fb-logout';
    // $facebook_html .= ' <a href="' . url($logout_url) . '">' . t('Logout') . '</a><br />';
  }
  else {
    publish_away_admin_fb_logout(FALSE);
  }
  return $facebook_html;
}

function publish_away_twitter_login() {
  $twitter_html = '';
  $consumer_key = publish_away_get('publish_away_consumer_key', NULL);
  $consumer_secret = publish_away_get('publish_away_consumer_secret', NULL);
  $oauth_token = publish_away_get('publish_away_oauth_token', NULL);
  $oauth_token_secret = publish_away_get('publish_away_oauth_token_secret', NULL);
  
  if (!empty($consumer_key) && !empty($consumer_secret) && !empty($oauth_token) && !empty($oauth_token_secret) 
          && $consumer_key != '' && $consumer_secret != '' && $oauth_token != '' && $oauth_token_secret != '') {
    
    if (!class_exists('tmhOAuth')) {
      require_once drupal_get_path('module', 'publish_away') . '/tmhOAuth/tmhOAuth.php';
    }
    if (!class_exists('tmhUtilities')) {
      require_once drupal_get_path('module', 'publish_away') . '/tmhOAuth/tmhUtilities.php';
    }
    
    $tmhOAuth = new tmhOAuth(array(
      'consumer_key' => $consumer_key,
      'consumer_secret' => $consumer_secret,
      'user_token' => $oauth_token,
      'user_secret' => $oauth_token_secret,
    ));
    $code = $tmhOAuth->request('GET', $tmhOAuth->url('1.1/account/verify_credentials'));
    
    if ($code == 200) {
      $twitter_user = json_decode($tmhOAuth->response['response']);
      if (isset($twitter_user->id) && trim($twitter_user->id) != '') {
        $twitter_html .= '<strong>' . t('Twitter account') . ' :</strong> ' . $twitter_user->name;
        if (isset($twitter_user->status) && isset($twitter_user->status->text) && trim($twitter_user->status->text) != '') {
          $twitter_html .= '<br /><strong>' . t('Your last Tweet') . ' :</strong> ' . $twitter_user->status->text;
        }
        $twitter_html .= '<br /><img style="veryical-align:middle;" src="'. $twitter_user->profile_image_url .'" alt="'. t('@user image', array('@user' => $twitter_user->name)) .'" />';
      }
    }
    else {
      drupal_set_message(t('There was an error from Twitter.'), 'error');
    }
  }
  return $twitter_html;
}

function publish_away_admin_fb_logout($return = TRUE) {
  // Log out the Facebook acount.
  /*module_load_include('inc', 'publish_away', 'facebook');
  $config = array(
    'appId'  => publish_away_get('publish_away_fb_appId', NULL),
    'secret' => publish_away_get('publish_away_fb_secret', NULL),
    'access_token' => publish_away_get('publish_away_fb_token', NULL),
  );
  $facebook = new Facebook($config);
  $facebook->api('/' . publish_away_get('publish_away_fb_id', 'me') . '/permissions', 'DELETE');*/
  publish_away_set('publish_away_fb_token', NULL);
  publish_away_set('publish_away_fb_id', NULL);
  publish_away_set('publish_away_fb_secret', NULL);
  publish_away_set('publish_away_fb_name', NULL);
  if ($return) {
    drupal_goto(url('admin/config/services/publish-away'));
  }
}
