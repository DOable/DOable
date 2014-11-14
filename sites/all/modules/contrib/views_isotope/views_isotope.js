(function($) {
  $(document).ready(function() {
  
  var $container = $('#isotope-container');
      
  $container.isotope({
    itemSelector: '.isotope-element',
    //filter: '.nothing'
  });
  
  var $optionSets = $('#isotope-options .option-set'),
      $optionLinks = $optionSets.find('a');
 
      $optionLinks.click(function(){
        
        var $this = $(this);
        // don't proceed if already selected
        if ( $this.hasClass('selected') ) {
          return false;
        }
        var $optionSet = $this.parents('.option-set');
        $optionSet.find('.selected').removeClass('selected');
        $this.addClass('selected');
  
        var options = {},
            key = $optionSet.attr('data-option-key'),
            value = $this.attr('data-option-value');
        // parse 'false' as false boolean
        value = value === 'false' ? false : value;
        options[ key ] = value;
        if ( key === 'layoutMode' && typeof changeLayoutMode === 'function' ) {
          // changes in layout modes need extra logic
          changeLayoutMode( $this, options )
        } else {
          // otherwise, apply new options
          $container.isotope( options );
        }
        
        return false;
      });
 });
})(jQuery);