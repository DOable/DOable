<?php

/**
 * @file
 * Contains the overridden block display plugin.
 */

/**
 * The plugin that overrides block display exposed form options.
 *
 * @ingroup views_display_plugins
 */
class vbfb_plugin_display_block extends views_plugin_display_block {

  /**
   * Allows block views to put exposed filter forms in blocks.
   */
  public function uses_exposed_form_in_block() {
    return TRUE;
  }

}
