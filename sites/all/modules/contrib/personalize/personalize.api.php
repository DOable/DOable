<?php

/**
 * CTools plugin hook for defining an agent type.
 *
 * All agent type plugins must specify a class that implements
 * PersonalizeAgentInterface. If the agent type supports explicit
 * targeting (allowing the mapping of visitor contexts to specific
 * options in an option set, e.g. "Users from Canada should always
 * see option C") then the class should implement the
 * PersonalizeExplicitTargetingInterface. There is a PersonalizeAgentBase
 * which it usually makes sense to extend.
 *
 * In addition to providing this class, all modules providing agent types
 * are expected to implement hook_personalize_campaign_report(), which will
 * be called from the 'reports' page of any agent of a type provided by the
 * module.
 *
 * @see modules/personalize_target/plugins/agent_types/PersonalizeTarget.inc
 * @see hook_personalize_campaign_report().
 */
function hook_personalize_agent_type() {
  $info = array();
  $path = drupal_get_path('module', 'my_module') . '/plugins/agent_types';
  $info['my_agent_type'] = array(
    'path' => $path,
    'handler' => array(
      'file' => 'MyAgentType.inc',
      'class' => 'MyAgentType',
    ),
  );
  return $info;
}

/**
 * CTools plugin hook for defining an Option Set type.
 *
 * An Option Set type plugin provides a mechanism for personalizing
 * a particular type of thing in Drupal, e.g. a block in the case of
 * the plugin provided by personalize_blocks module. The plugin does
 * not need to provide a class, rather it is expected to act on whatever
 * type of Drupal content it is concerned with personalizing. This will
 * mean calling the personalize_element_with_option_set() function at
 * the time of rendering that content, and it will usually mean adding
 * personalize_options_wrapper as a theme wrapper on the element being
 * rendered. Finally, all modules providing Option Set type plugins are
 * expected to implement hook_personalize_create_new_links().
 *
 * @see hook_personalize_create_new_links()
 * @see modules/personalize_blocks.module
 */
function hook_personalize_option_set_type() {
  return array(
    'my_type' => array()
  );
}

/**
 * An agent is about to be created or updated.
 *
 * This hook is invoked before the agent is saved to the database so
 * modules can alter the information that is saved.
 *
 * @param stdClass $agent
 *   A stdClass object representing the agent being saved.
 */
function hook_personalize_agent_presave($agent) {

}

/**
 * Respond to agent being saved.
 *
 * This hook is invoked after an agent has been saved to the database.
 *
 * @param stdClass $agent
 *   A stdClass object representing the agent that has just been saved.
 */
function hook_personalize_agent_save($agent) {

}

/**
 * Respond to an agent's status change.
 *
 * This hook is invoked after an agent's status has changed, e.g. from
 * 'paused' to 'running'.
 *
 * @param $agent_name
 *   The name of the agent whose status has just been updated.
 * @param $old_status
 *   The status of the agent before the change.
 * @param $new_status
 *   The status of the agent after the change
 */
function hook_personalize_agent_update_status($agent_name, $old_status, $new_status) {

}

/**
 * Respond to agent being deleted.
 *
 * This hook is invoked after the agent has been deleted from the db.
 *
 * @param stdClass $agent
 *   A stdClass object representing the agent that has been deleted.
 */
function hook_personalize_agent_delete($agent) {

}

/**
 * An Option Set is about to be created or updated.
 *
 * This hook is invoked before the Option Set is saved to the database
 * so modules can alter the information that is saved.
 *
 * @param stdClass $option_set
 *   A stdClass object representing the Option Set being saved.
 */
function hook_personalize_option_set_presave($option_set) {

}

/**
 * Add additional data to a loaded option set.
 *
 * @see e.g. personalize_fields_option_set_load().
 */
function hook_personalize_option_set_load($option_set) {

}

/**
 * Respond to Option Set being saved.
 *
 * This hook is invoked after an Option Set has been saved to the db.
 *
 * @param stdClass $option_set
 *   A stdClass object representing the Option Set that's just been saved.
 */
function hook_personalize_option_set_save($option_set) {

}

/**
 * Respond to an Option Set  being deleted.
 *
 * This hook is invoked after the Option Set is deleted from the database.
 *
 * @param stdClass $option_set
 *   A stdClass object representing the Option Set that's been deleted.
 */
function hook_personalize_option_set_delete($option_set) {

}

/**
 * Respond to an MVT being deleted.
 *
 * This hook is invoked after an MVT has been deleted from the db.
 *
 * @param $mvt
 *   A fully loaded MVT object representing a multivariate test
 *   that has just been deleted from the DB. The Option Sets
 *   associated wtih the MVT, though still part of this object,
 *   will have already been disassociated from the deleted MVT.
 */
function hook_personalize_mvt_delete($mvt) {

}

/**
 * Respond to a goal being created or updated.
 *
 * This goal is invoked after a goal has been saved to the db.
 *
 * @param array $goal_array
 *   An associative array representing the goal, with the following
 *   keys:
 *   - agent The name of the agent the goal was saved for.
 *   - name The name of the action used by the goal.
 *   - value The value of the goal.
 */
function hook_personalize_goal_save($goal_array) {

}

/**
 * Respond to ajax submission of agent-related changes.
 *
 * This hook is invoked at the end of the ajax callback when any of
 * the forms on the campaign edit page are submitted.
 *
 * @param stdClass $agent
 *   A stdClass object representing the agent being updated.
 */
function hook_personalize_form_ajax_submit($agent_data) {

}

/**
 * Returns links for the "create new personalized content" dropdown.
 *
 * This hook is typically implemented by modules that provide an
 * Option Set type, and returns an array of link information for
 * getting to the place where Option Sets of this type can be created.
 * For example, personalize_fields module provides links to create
 * new nodes of any types that contain at least one personalizable
 * field.
 *
 * @return array
 *   An array  of associative arrays, each representing a link, with
 *   the following keys:
 *   - title The clickable text for the link.
 *   - path The path to go to in order to create this type of
 *     personalized thing.
 *
 * @see personalize_fields_personalize_create_new_links().
 */
function hook_personalize_create_new_links() {
  return array(
    array(
      'title' => 'Personalized widget',
      'path' => 'admin/my-module/add/new/widget'
    )
  );
}

/**
 * Returns link to edit the option set.
 *
 * This hook is implemented by modules that provide an Option Set type, and
 * returns the path to edit an option set.
 *
 * @param stdClass $option_set
 *   The option set to edit.
 *
 * @return string
 *   The path to the edit the option set.
 */
function hook_personalize_edit_link($option_set) {
}

/**
 * Returns link to delete the option set.
 *
 * This hook is implemented by modules that provide an Option Set type, and
 * returns the path to delete an option set.
 *
 * @param stdClass $option_set
 *   The option set to delete.
 *
 * @return string
 *   The path to the delete the option set.
 */
function hook_personalize_delete_link($option_set) {
}

/**
 * Returns a render array or themed output for a report on the specified agent.
 *
 * This hook will be invoked on the module responsible for the agent type of
 * the agent in question.
 *
 * @param stdClass $agent_data
 *   A stdClass object representing the loaded agent.
 * @param stdClass $option_set
 *   (optional) The content variation set for filtering report data.
 *
 * @return string|array
 *   Either a string of themed output or an array that can be passed to drupal_render.
 */
function hook_personalize_campaign_report($agent_data, $option_set) {

}

/**
 * Allows alteration the array of available executors.
 *
 * @param array $executors
 *   An array of all available executors keyed by executor name.
 *   - description: The description to display for this executor.
 */
function hook_personalize_executors_alter($executors) {

}

/**
 * Returns an array of executors options supported by a personalizable option.
 *
 * Executors may define a single executor on the option set if selectable
 * options are not supported.
 *
 * @return array
 *   An array of executors options keyed by executor name.  Each can specify
 *   the following values:
 *   - default: option boolean indicating if this is the default executor.
 */
function hook_personalize_get_executor_options() {

}

/**
 * Returns a render array for a specific option.
 *
 * This hook is invoked with the selected option from an option set and is
 * required in order to support rendering via Ajax callback.
 *
 * @param stdClass $option_set
 *   A stdClass object representing the loaded option set.
 * @param array $option
 *   The option data for the selected option.
 *
 * @return array
 *   The render array for the selected option.
 */
function hook_personalize_option_load($option_set, $option) {

}
