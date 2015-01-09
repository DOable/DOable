(function ($) {
  "use strict";

  Drupal.behaviors.itoggleNodeFieldsetSummaries = {
    attach: function (context) {
      var $fieldset = $('#edit-options', context);
      $fieldset.drupalSetSummary(function (context) {
        var summary = '';
        $fieldset.find('div.form-type-itoggle').each(function() {
          var $t = $(this),
          $wrapper = $t.find('div.itoggle-wrapper'),
          property = $wrapper.attr('data-property'),
          label = $t.find('label').text(),
          checked = $wrapper.find('input').is(':checked');

          if (property === 'status') {
            if (checked) {
              summary += label;
            }
            else {
              summary += Drupal.t('Not Published');
            }
          }
          else if (checked) {
            summary += ', ' + label;
          }
        });
        return summary;
      });
    }
  };

})(jQuery);