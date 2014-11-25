// Menu scroll
jQuery(document).ready(function() {
var nav = jQuery('#block-menu-block-1');
pos = nav.offset();
	// Esperamos al DOM
	jQuery(window).scroll(function(){
		// Anclamos el men� si el scroll es
		// mayor a la posici�n superior del tag
		if ( (jQuery(this).scrollTop() >= 122)){
		// A�adimos la clase fixes al men� y la clase stickey a breadcrumb para que se siga viendo
			jQuery('#block-menu-block-1').addClass('fixed');
			var text = '/blog';
			var url_blog = jQuery(location).attr('href');
			//If the URL have blog. Remove the class stickey
			if (url_blog.indexOf(text) != -1) {
				jQuery('.breadcrumb').removeClass('stickey');
			}else{
				jQuery('.breadcrumb').addClass('stickey');
			}			
		// Eliminamos las clases para volver a la posici�n original
		} else if ( (jQuery(this).scrollTop() <= 122)){
		// Elimina clase fixes y stickey
			jQuery('#block-menu-block-1').removeClass('fixed');
			jQuery('.breadcrumb').removeClass('stickey');
		}
	});
});
