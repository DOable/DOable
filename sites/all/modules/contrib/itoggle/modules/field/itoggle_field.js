(function ($, Drupal) {
  Drupal.behaviors.itoggle_field = {
    attach: function(context, settings) {
      var $display_type = $('select#edit-instance-widget-settings-itoggle-settings-display-type', context);

      if ($display_type.length) {
        // @TODO update this to use .on() eventually. Not worth introducing a
        // depencency on jQuery Update to do it now though.
        $display_type.bind('change blur', function() {
          var $t = $(this),
            $wrapper = $('div.itoggle-wrapper', context);

          switch (parseInt($t.val(), 10)) {
            case 0:
              $wrapper
                .removeClass('itoggle-display-yesno itoggle-display-onezero')
                .addClass('itoggle-display-onoff');
              break;
            case 1:
              $wrapper
                .removeClass('itoggle-display-onoff itoggle-display-onezero')
                .addClass('itoggle-display-yesno');
              break;
            case 2:
              $wrapper
                .removeClass('itoggle-display-yesno itoggle-display-onoff')
                .addClass('itoggle-display-onezero');
              break;
          }
        });
      }
    }
  };
})(jQuery, Drupal);
