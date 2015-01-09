(function ($) {
  "use strict";

  Drupal.behaviors.itoggleNodeTypeFieldsetSummaries = {
    attach: function (context) {
      $('#edit-itoggle', context).drupalSetSummary(function(context) {
        var $fieldset = $('fieldset#edit-itoggle'),
        enabled = $fieldset.find('input[name^="itoggle[itoggle_enable"]').attr('checked');
        enabled = enabled ? Drupal.t('Enabled') : Drupal.t('Disabled');
        return Drupal.checkPlain(enabled);
      });
    }
  };

})(jQuery);