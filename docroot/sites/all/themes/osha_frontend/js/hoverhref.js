jQuery(document).ready(function () {
    hoverThemes();
	zoomMedium();
	hoverSlideHome();
});


function hoverThemes() {
	jQuery("#block-menu-block-3 ul li").each(function() {
		var obj=jQuery(this);
		jQuery(".introduction-image img",this).mouseover(function() {
		obj.find(".introduction-title").css("border-bottom", "10px solid #DC2E81");
		obj.find(".introduction-title a").css("background","url('/sites/all/themes/osha_frontend/images/flecha.png') 100% 25% no-repeat").css("padding-right", "1.5em");
		});
	});
	
	jQuery("#block-menu-block-3 ul li").each(function() {
		var obj=jQuery(this);
		jQuery(".introduction-image img",this).mouseout(function() {
		obj.find(".introduction-title").css("border-bottom", "10px solid #D2DCED");
		obj.find(".introduction-title a").css("background","none");
		});
	});
	
	jQuery("#block-menu-block-3 ul li").each(function() {
		var obj=jQuery(this);
		jQuery(".introduction-title",this).mouseover(function() {
		obj.find(".introduction-title").css("border-bottom", "10px solid #DC2E81");
		obj.find(".introduction-title a").css("background","url('/sites/all/themes/osha_frontend/images/flecha.png') 100% 25% no-repeat").css("padding-right", "1.5em");
		});
	});
	
	jQuery("#block-menu-block-3 ul li").each(function() {
		var obj=jQuery(this);
		jQuery(".introduction-title",this).mouseout(function() {
		obj.find(".introduction-title").css("border-bottom", "10px solid #D2DCED");
		obj.find(".introduction-title a").css("background","none");
		});
	});
	
	
	/*INFOGRAPHICS*/
	
	jQuery(".view-infographic div div").each(function() {
		var obj=jQuery(this);
		jQuery(".views-field-field-thumbnail img",this).mouseover(function() {
		obj.find(".views-field-title-field").css("border-bottom", "10px solid #DC2E81");
		obj.find(".views-field-title-field a").css("background","url('/sites/all/themes/osha_frontend/images/flecha.png') 100% 25% no-repeat").css("padding-right", "1.5em");
		});
	});
	
	jQuery(".view-infographic div div").each(function() {
		var obj=jQuery(this);
		jQuery(".views-field-field-thumbnail img",this).mouseout(function() {
		obj.find(".views-field-title-field").css("border-bottom", "10px solid #D2DCED");
		obj.find(".views-field-title-field a").css("background","none");
		});
	});
	
	jQuery(".view-infographic div div").each(function() {
		var obj=jQuery(this);
		jQuery(".views-field-title-field",this).mouseover(function() {
		obj.find(".views-field-title-field").css("border-bottom", "10px solid #DC2E81");
		obj.find(".views-field-title-field a").css("background","url('/sites/all/themes/osha_frontend/images/flecha.png') 100% 25% no-repeat").css("padding-right", "1.5em");
		});
	});
	
	jQuery(".view-infographic div div").each(function() {
		var obj=jQuery(this);
		jQuery(".views-field-title-field",this).mouseout(function() {
		obj.find(".views-field-title-field").css("border-bottom", "10px solid #D2DCED");
		obj.find(".views-field-title-field a").css("background","none");
		});
	});
	
}


function hoverSlideHome() {

	jQuery("#num_slides div").each(function() {
		jQuery(this).mouseover(function() {
		jQuery("span",this).addClass('text_white');
		jQuery("span",this).removeClass('text_blue');
		});
	});
	
	jQuery("#num_slides div").each(function() {
		jQuery(this).mouseout(function() {
		jQuery("span",this).addClass('text_blue');
		jQuery("span",this).removeClass('text_white');
		});
	});	
	
	jQuery("#num_slides div").each(function() {
		jQuery(this).mouseover(function() {
		jQuery("img",this).addClass('img_opac');
		jQuery("img",this).removeClass('img_no_opac');
		});
	});	
	
	jQuery("#num_slides div").each(function() {
		jQuery(this).mouseout(function() {
		jQuery("img",this).addClass('img_no_opac');
		jQuery("img",this).removeClass('img_opac');
		});
	});	
	
}

function displayMenuThirdLevel() {
	
	
	
 // init: collapse all groups except for the first one
    jQuery("#block-menu-block-2 #main-menu-links #main-menu-links #main-menu-links").each(function(i)
    {
        
		jQuery(this).hide();
       
    });

	
	jQuery('#block-menu-block-2 #main-menu-links #main-menu-links .expanded').each(function () {
    jQuery(this).css("cursor","pointer");
    jQuery(this).click(function () {
      jQuery("ul",this).slideToggle();
		if ( jQuery(this).hasClass("expand")) {
			jQuery(this).removeClass("expand").addClass("is-expanded");
		} else if (jQuery(this).hasClass("is-expanded")) {
			jQuery(this).removeClass("is-expanded").addClass("expand");
		}
	  });
	});
	
	
	jQuery(document).ready(function () {
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .active #main-menu-links" ).show();
		//When the children is active, show the ul
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .is-active" ).parent( "#main-menu-links" ).show();
		
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .is-active" ).parent( "#main-menu-links" ).parent( ".is-active-trail").removeClass('is-expanded');
	  
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .is-active" ).parent( "#main-menu-links" ).parent( ".is-active-trail").addClass('expand');
		
		
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .active #main-menu-links" ).show();
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .is-active").removeClass('is-expanded');
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links .is-active").addClass('expand');
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links #main-menu-links .is-active").removeClass('expand');
		jQuery( "#block-menu-block-2 #main-menu-links #main-menu-links #main-menu-links li a").removeClass('expand');
		
		
		jQuery("#block-menu-block-2 #main-menu-links #main-menu-links .active").each(function() {
			var html=jQuery("#block-menu-block-2 #main-menu-links #main-menu-links .active").html();
			if(html.indexOf("ul")==-1) {
				jQuery(this).removeClass('expand');
			}
		});
		

		
	});
	
}
        
	function zoomSmall() {
		jQuery("body").addClass("bodysmall");
		jQuery("body").removeClass("bodymedium");
		jQuery("body").removeClass("bodybig");
	}
	
	function zoomMedium() {
		jQuery("body").addClass("bodymedium");
		jQuery("body").removeClass("bodysmall");
		jQuery("body").removeClass("bodybig");
	}
	function zoomBig() {
		jQuery("body").addClass("bodybig");
		jQuery("body").removeClass("bodysmall");
		jQuery("body").removeClass("bodymedium");
	}
	
	
// Tools & Publications filters
jQuery(document).ready(function() {
	// Toggle event for facetapi filters blocks.
    jQuery(".block-facetapi .item-list").has('ul, select').each(function() {
		// If no active filters, hide the filtering on init.
		if (jQuery(this).find('a.facetapi-active, option[value]:selected, input:checked').length == 0) {
			jQuery(this).hide();
		}
		else {
			jQuery(this).closest('.block-facetapi').find('h2.block-title').addClass('expand');
		}
	}).closest('.block-facetapi').find('h2.block-title').click(function() {
		jQuery(this).closest('.block-facetapi').find("div.item-list").slideToggle();
		jQuery(this).toggleClass("expand");
    });
});

/* Show searcher in responsive menu */
jQuery(document).ready(function() {
	var menuExpanded = false;
    // Click event: show language and search box
	jQuery("a[href$='#nav']").click(function() {		
		!menuExpanded?showSearcher():hideSearcher();		
		menuExpanded = !menuExpanded;
    });
});

function showSearcher() {	
	jQuery(".mean-container #block-lang-dropdown-language-content").css("display","block");
	jQuery(".mean-container #block-search-form").css("display","block");
	jQuery(".mean-container #languagesAndSearch").css("display","block");
}
function hideSearcher() {	
	jQuery(".mean-container #block-lang-dropdown-language-content").css("display","none");
	jQuery(".mean-container #block-search-form").css("display","none");
	jQuery(".mean-container #languagesAndSearch").css("display","none");
}


/* Add image to External links - _target=blank */

jQuery(document).ready(function() {
	jQuery('#content a[target="_blank"]').append('<span class="osha_target_external_link">&nbsp;</span>');
});


jQuery(document).ready(function() {
	// Toggle event for facetapi filters blocks.
    jQuery(".region-sidebar-first .view-fop-flags").has('ul, select').each(function() {
		// If no active filters, hide the filtering on init.
		if (jQuery(this).find('.fop-country-list').length == 0) {
			jQuery(this).hide();
		}
		else {
			jQuery(this).closest('.region-sidebar-first').find('h3').addClass('expand');
		}
	}).closest('.region-sidebar-first').find('h3').click(function() {
		jQuery(this).closest('.item-list').find(".fop-country-list").slideToggle();
		jQuery(this).toggleClass("expand");
    });
});


