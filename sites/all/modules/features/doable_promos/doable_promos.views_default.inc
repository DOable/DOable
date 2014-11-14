<?php
/**
 * @file
 * doable_promos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function doable_promos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'promos_homepage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_promo';
  $view->human_name = 'Promos - Homepage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Promo: Link */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_promo';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['label'] = '';
  $handler->display->display_options['fields']['view_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_link']['element_label_colon'] = FALSE;
  /* Field: Promo: Title */
  $handler->display->display_options['fields']['field_promo_title']['id'] = 'field_promo_title';
  $handler->display->display_options['fields']['field_promo_title']['table'] = 'field_data_field_promo_title';
  $handler->display->display_options['fields']['field_promo_title']['field'] = 'field_promo_title';
  $handler->display->display_options['fields']['field_promo_title']['label'] = '';
  $handler->display->display_options['fields']['field_promo_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_title']['element_label_colon'] = FALSE;
  /* Field: Promo: Sub-Title */
  $handler->display->display_options['fields']['field_promo_sub_title']['id'] = 'field_promo_sub_title';
  $handler->display->display_options['fields']['field_promo_sub_title']['table'] = 'field_data_field_promo_sub_title';
  $handler->display->display_options['fields']['field_promo_sub_title']['field'] = 'field_promo_sub_title';
  $handler->display->display_options['fields']['field_promo_sub_title']['label'] = '';
  $handler->display->display_options['fields']['field_promo_sub_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_sub_title']['element_label_colon'] = FALSE;
  /* Field: Promo: Body */
  $handler->display->display_options['fields']['field_promo_body']['id'] = 'field_promo_body';
  $handler->display->display_options['fields']['field_promo_body']['table'] = 'field_data_field_promo_body';
  $handler->display->display_options['fields']['field_promo_body']['field'] = 'field_promo_body';
  $handler->display->display_options['fields']['field_promo_body']['label'] = '';
  $handler->display->display_options['fields']['field_promo_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_body']['element_label_colon'] = FALSE;
  /* Field: Promo: Image */
  $handler->display->display_options['fields']['field_promo_image']['id'] = 'field_promo_image';
  $handler->display->display_options['fields']['field_promo_image']['table'] = 'field_data_field_promo_image';
  $handler->display->display_options['fields']['field_promo_image']['field'] = 'field_promo_image';
  $handler->display->display_options['fields']['field_promo_image']['label'] = '';
  $handler->display->display_options['fields']['field_promo_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_promo_image']['alter']['text'] = '<div>
  <div>[field_promo_image]</div>
  <div class="flex-caption">
    <div><h3><a href="http://google.com">[field_promo_title]</a></h3></div>
    <div><h4><a href="http://google.com">[field_promo_sub_title]</a></h4></div>
  </div>
</div>';
  $handler->display->display_options['fields']['field_promo_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_promo_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Filter criterion: Promo: promo type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_promo';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'promo' => 'promo',
  );

  /* Display: Promos - Homepage */
  $handler = $view->new_display('block', 'Promos - Homepage', 'block');
  $export['promos_homepage'] = $view;

  return $export;
}
