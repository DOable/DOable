<?php
/**
 * @file
 * doable_solutions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function doable_solutions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'solutions_browse_by_tag';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Solutions - Browse By Tag';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Browse Solutions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_1',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['use-grouping-header'] = 1;
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = 'none';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['style_options']['clearstyle'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['row_options']['separator'] = ',';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/tags" class="button-link">View all Tags</a>';
  $handler->display->display_options['footer']['area']['format'] = 'ds_code';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'budget' => 'budget',
    'carbon_sources' => 'carbon_sources',
    'emission_type' => 'emission_type',
    'energy_cycle' => 'energy_cycle',
    'density' => 'density',
    'sector' => 'sector',
    'solution_strategy' => 'solution_strategy',
    'tags' => 'tags',
    'timeline' => 'timeline',
  );

  /* Display: Block - Browse by Tags */
  $handler = $view->new_display('block', 'Block - Browse by Tags', 'block');
  $export['solutions_browse_by_tag'] = $view;

  $view = new view();
  $view->name = 'solutions_teasers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Solutions - Teasers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_solution_budget_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_solution_sectors_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_solution_timeline_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_solution_image']['id'] = 'field_solution_image';
  $handler->display->display_options['fields']['field_solution_image']['table'] = 'field_data_field_solution_image';
  $handler->display->display_options['fields']['field_solution_image']['field'] = 'field_solution_image';
  $handler->display->display_options['fields']['field_solution_image']['label'] = '';
  $handler->display->display_options['fields']['field_solution_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solution_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_solution_image']['settings'] = array(
    'image_style' => 'teaser',
    'image_link' => 'content',
  );
  /* Field: Content: Sector(s) */
  $handler->display->display_options['fields']['field_solution_sectors']['id'] = 'field_solution_sectors';
  $handler->display->display_options['fields']['field_solution_sectors']['table'] = 'field_data_field_solution_sectors';
  $handler->display->display_options['fields']['field_solution_sectors']['field'] = 'field_solution_sectors';
  $handler->display->display_options['fields']['field_solution_sectors']['label'] = '';
  $handler->display->display_options['fields']['field_solution_sectors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solution_sectors']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_solution_teaser']['id'] = 'field_solution_teaser';
  $handler->display->display_options['fields']['field_solution_teaser']['table'] = 'field_data_field_solution_teaser';
  $handler->display->display_options['fields']['field_solution_teaser']['field'] = 'field_solution_teaser';
  $handler->display->display_options['fields']['field_solution_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_solution_teaser']['element_label_colon'] = FALSE;
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_solution_tags']['id'] = 'field_solution_tags';
  $handler->display->display_options['fields']['field_solution_tags']['table'] = 'field_data_field_solution_tags';
  $handler->display->display_options['fields']['field_solution_tags']['field'] = 'field_solution_tags';
  $handler->display->display_options['fields']['field_solution_tags']['label'] = '';
  $handler->display->display_options['fields']['field_solution_tags']['element_label_class'] = 'label-inline ';
  $handler->display->display_options['fields']['field_solution_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solution_tags']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['solutions_teasers'] = $view;

  $view = new view();
  $view->name = 'solutions_teasers_filtered';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Solutions - Teasers Filtered';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_solution_budget_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_solution_sectors_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_solution_timeline_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_solution_image']['id'] = 'field_solution_image';
  $handler->display->display_options['fields']['field_solution_image']['table'] = 'field_data_field_solution_image';
  $handler->display->display_options['fields']['field_solution_image']['field'] = 'field_solution_image';
  $handler->display->display_options['fields']['field_solution_image']['label'] = '';
  $handler->display->display_options['fields']['field_solution_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solution_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_solution_image']['settings'] = array(
    'image_style' => 'teaser',
    'image_link' => 'content',
  );
  /* Field: Content: Sector(s) */
  $handler->display->display_options['fields']['field_solution_sectors']['id'] = 'field_solution_sectors';
  $handler->display->display_options['fields']['field_solution_sectors']['table'] = 'field_data_field_solution_sectors';
  $handler->display->display_options['fields']['field_solution_sectors']['field'] = 'field_solution_sectors';
  $handler->display->display_options['fields']['field_solution_sectors']['label'] = '';
  $handler->display->display_options['fields']['field_solution_sectors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solution_sectors']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_solution_teaser']['id'] = 'field_solution_teaser';
  $handler->display->display_options['fields']['field_solution_teaser']['table'] = 'field_data_field_solution_teaser';
  $handler->display->display_options['fields']['field_solution_teaser']['field'] = 'field_solution_teaser';
  $handler->display->display_options['fields']['field_solution_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_solution_teaser']['element_label_colon'] = FALSE;
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_solution_tags']['id'] = 'field_solution_tags';
  $handler->display->display_options['fields']['field_solution_tags']['table'] = 'field_data_field_solution_tags';
  $handler->display->display_options['fields']['field_solution_tags']['field'] = 'field_solution_tags';
  $handler->display->display_options['fields']['field_solution_tags']['label'] = '';
  $handler->display->display_options['fields']['field_solution_tags']['element_label_class'] = 'label-inline ';
  $handler->display->display_options['fields']['field_solution_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solution_tags']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );
  /* Filter criterion: Content: Budget (field_solution_budget) */
  $handler->display->display_options['filters']['field_solution_budget_tid']['id'] = 'field_solution_budget_tid';
  $handler->display->display_options['filters']['field_solution_budget_tid']['table'] = 'field_data_field_solution_budget';
  $handler->display->display_options['filters']['field_solution_budget_tid']['field'] = 'field_solution_budget_tid';
  $handler->display->display_options['filters']['field_solution_budget_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_solution_budget_tid']['expose']['operator_id'] = 'field_solution_budget_tid_op';
  $handler->display->display_options['filters']['field_solution_budget_tid']['expose']['label'] = 'Budget';
  $handler->display->display_options['filters']['field_solution_budget_tid']['expose']['operator'] = 'field_solution_budget_tid_op';
  $handler->display->display_options['filters']['field_solution_budget_tid']['expose']['identifier'] = 'field_solution_budget_tid';
  $handler->display->display_options['filters']['field_solution_budget_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_solution_budget_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_solution_budget_tid']['vocabulary'] = 'budget';
  /* Filter criterion: Content: Sector(s) (field_solution_sectors) */
  $handler->display->display_options['filters']['field_solution_sectors_tid']['id'] = 'field_solution_sectors_tid';
  $handler->display->display_options['filters']['field_solution_sectors_tid']['table'] = 'field_data_field_solution_sectors';
  $handler->display->display_options['filters']['field_solution_sectors_tid']['field'] = 'field_solution_sectors_tid';
  $handler->display->display_options['filters']['field_solution_sectors_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_solution_sectors_tid']['expose']['operator_id'] = 'field_solution_sectors_tid_op';
  $handler->display->display_options['filters']['field_solution_sectors_tid']['expose']['label'] = 'Sector';
  $handler->display->display_options['filters']['field_solution_sectors_tid']['expose']['operator'] = 'field_solution_sectors_tid_op';
  $handler->display->display_options['filters']['field_solution_sectors_tid']['expose']['identifier'] = 'field_solution_sectors_tid';
  $handler->display->display_options['filters']['field_solution_sectors_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_solution_sectors_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_solution_sectors_tid']['vocabulary'] = 'sector';
  /* Filter criterion: Content: Timeline (field_solution_timeline) */
  $handler->display->display_options['filters']['field_solution_timeline_tid']['id'] = 'field_solution_timeline_tid';
  $handler->display->display_options['filters']['field_solution_timeline_tid']['table'] = 'field_data_field_solution_timeline';
  $handler->display->display_options['filters']['field_solution_timeline_tid']['field'] = 'field_solution_timeline_tid';
  $handler->display->display_options['filters']['field_solution_timeline_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_solution_timeline_tid']['expose']['operator_id'] = 'field_solution_timeline_tid_op';
  $handler->display->display_options['filters']['field_solution_timeline_tid']['expose']['label'] = 'Timeline';
  $handler->display->display_options['filters']['field_solution_timeline_tid']['expose']['operator'] = 'field_solution_timeline_tid_op';
  $handler->display->display_options['filters']['field_solution_timeline_tid']['expose']['identifier'] = 'field_solution_timeline_tid';
  $handler->display->display_options['filters']['field_solution_timeline_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_solution_timeline_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_solution_timeline_tid']['vocabulary'] = 'timeline';
  /* Filter criterion: Content: Target Population Density (field_solution_density) */
  $handler->display->display_options['filters']['field_solution_density_tid']['id'] = 'field_solution_density_tid';
  $handler->display->display_options['filters']['field_solution_density_tid']['table'] = 'field_data_field_solution_density';
  $handler->display->display_options['filters']['field_solution_density_tid']['field'] = 'field_solution_density_tid';
  $handler->display->display_options['filters']['field_solution_density_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_solution_density_tid']['expose']['operator_id'] = 'field_solution_density_tid_op';
  $handler->display->display_options['filters']['field_solution_density_tid']['expose']['label'] = 'Population Density';
  $handler->display->display_options['filters']['field_solution_density_tid']['expose']['operator'] = 'field_solution_density_tid_op';
  $handler->display->display_options['filters']['field_solution_density_tid']['expose']['identifier'] = 'field_solution_density_tid';
  $handler->display->display_options['filters']['field_solution_density_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_solution_density_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_solution_density_tid']['vocabulary'] = 'density';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['solutions_teasers_filtered'] = $view;

  $view = new view();
  $view->name = 'solutions_trending_sidebar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Solutions - Trending Sidebar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Trending Solutions';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_solution_budget_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_solution_sectors_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_solution_timeline_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_solution_image']['id'] = 'field_solution_image';
  $handler->display->display_options['fields']['field_solution_image']['table'] = 'field_data_field_solution_image';
  $handler->display->display_options['fields']['field_solution_image']['field'] = 'field_solution_image';
  $handler->display->display_options['fields']['field_solution_image']['label'] = '';
  $handler->display->display_options['fields']['field_solution_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solution_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_solution_image']['settings'] = array(
    'image_style' => 'listing_preview',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_solution_teaser']['id'] = 'field_solution_teaser';
  $handler->display->display_options['fields']['field_solution_teaser']['table'] = 'field_data_field_solution_teaser';
  $handler->display->display_options['fields']['field_solution_teaser']['field'] = 'field_solution_teaser';
  $handler->display->display_options['fields']['field_solution_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_solution_teaser']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['field_solution_teaser']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_solution_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solution_teaser']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_solution_tags']['id'] = 'field_solution_tags';
  $handler->display->display_options['fields']['field_solution_tags']['table'] = 'field_data_field_solution_tags';
  $handler->display->display_options['fields']['field_solution_tags']['field'] = 'field_solution_tags';
  $handler->display->display_options['fields']['field_solution_tags']['label'] = '';
  $handler->display->display_options['fields']['field_solution_tags']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_solution_tags']['element_label_class'] = 'label-inline ';
  $handler->display->display_options['fields']['field_solution_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solution_tags']['delta_offset'] = '0';
  /* Field: Content: Sector(s) */
  $handler->display->display_options['fields']['field_solution_sectors']['id'] = 'field_solution_sectors';
  $handler->display->display_options['fields']['field_solution_sectors']['table'] = 'field_data_field_solution_sectors';
  $handler->display->display_options['fields']['field_solution_sectors']['field'] = 'field_solution_sectors';
  $handler->display->display_options['fields']['field_solution_sectors']['label'] = '';
  $handler->display->display_options['fields']['field_solution_sectors']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_solution_sectors']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_solution_sectors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solution_sectors']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );

  /* Display: Solutions - Trending Sidebar */
  $handler = $view->new_display('block', 'Solutions - Trending Sidebar', 'block');
  $export['solutions_trending_sidebar'] = $view;

  return $export;
}
