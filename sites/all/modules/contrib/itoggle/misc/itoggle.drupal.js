(function ($) {
  "use strict";

  Drupal.behaviors.itoggle = {
    attach: function(context, settings) {
      var $toggle = $('div.itoggle-wrapper', context);

      if ($toggle.length) {
        $toggle.once(function() {
          var $t = $(this),
          id = $t.attr('data-id'),
          type = $t.attr('data-type'),
          bundle = $t.attr('data-bundle'),
          property = $t.attr('data-property'),
          scope = $t.attr('data-scope'),
          token_key = 'itoggle_' + type + '_' + property + '_' + id;

          var itoggle_settings = {
            keepLabel: false,
            speed: settings.itoggle.speed,
            onSlideOn: function(){
              if (settings.itoggle.onslideon) {
                eval(settings.itoggle.onslideon);
              }

              if (scope === 'field-edit') {
                var replace = property.replace(/_/g, '-'),
                $target = $('#edit-' + replace, context);

                if ($target.is('input')) {
                  $target.attr('checked', 'checked');
                } else {
                  $target.find('input[type=checkbox]').attr('checked', 'checked');
                }
              } else {
                if (settings.itoggle.clickable[token_key]) {
                  var serial = 'token=' + settings.itoggle.tokens[token_key] + '&type=' + type +
                    '&bundle=' + bundle + '&property='  + property + '&id=' + id +
                    '&value=1&scope=' + scope;

                  $.post(settings.basePath + 'js/itoggle', serial, function(response){
                    if (!response.ok || response.ok !== true) {
                      var $object = $t.find('label.itoggle');

                      $object.animate({
                        backgroundPosition:'100% -'+h+'px'
                      }, settings.itoggle.speed, settings.itoggle.easing, function(){
                        $object.removeClass('iTon').addClass('iToff');
                      });
                    }
                  }, 'json');
                }
              }
            },
            onSlideOff: function(){
              if (settings.itoggle.onslideoff) {
                eval(settings.itoggle.onslideoff);
              }

              if (scope === 'field-edit') {
                var replace = property.replace(/_/g, '-'),
                $target = $('#edit-' + replace, context);

                if ($target.is('input')) {
                  $target.removeAttr('checked');
                } else {
                  $target.find('input[type=checkbox]').removeAttr('checked');
                }
              } else {
                if (settings.itoggle.clickable[token_key]) {
                  var serial = 'token=' + settings.itoggle.tokens[token_key] +
                    '&type=' + type + '&bundle=' + bundle + '&property='  +
                    property + '&id=' + id + '&value=0&scope=' + scope;

                  $.post(settings.basePath + 'js/itoggle', serial, function(response){
                    if (!response.ok || response.ok !== true) {
                      var $object = $t.find('label.itoggle');

                      $object.animate({
                        backgroundPosition:'0% -'+h+'px'
                      }, settings.speed, settings.easing, function(){
                        $object.removeClass('iToff').addClass('iTon');
                      });
                    }
                  }, 'json');
                }
              }
            }
          };

          /* Spawn hell portals */
          if (settings.itoggle.onclick) {
            itoggle_settings.onClick = function() {
              eval(settings.itoggle.onclick);
            }
          }

          if (settings.itoggle.onclickon) {
            itoggle_settings.onClickOn = function() {
              eval(settings.itoggle.onclickon);
            }
          }

          if (settings.itoggle.onclickoff) {
            itoggle_settings.onClickOff = function() {
              eval(settings.itoggle.onclickoff);
            }
          }

          if (settings.itoggle.onslide) {
            itoggle_settings.onSlide = function() {
              eval(settings.itoggle.onslide);
            }
          }

          /* No demons? Proceed */

          if (settings.itoggle.easing) {
            itoggle_settings.easing = settings.itoggle.easing;
          }

          $t.find('input:first').iToggle(itoggle_settings);

          // Figure out if we're in Views UI.
          var $views_ui = $('#views-ui-edit-form', context);

          if ($views_ui.length || !settings.itoggle.clickable[token_key]) {
            // Must wait until events are fully bound.
            setTimeout(function(){
              $t.find('label.itoggle').unbind('click').css('cursor', 'default').find('span').css('cursor', 'default').click(function() {
                return false
              } );
            }, 100);
          }
        });
      }
    }
  };

})(jQuery);
