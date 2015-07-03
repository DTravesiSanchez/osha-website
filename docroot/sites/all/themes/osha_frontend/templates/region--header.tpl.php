<div id="socialNetworksBlue">
	<div id="icons">
		<a href="https://twitter.com/eu_osha"><img src="/sites/all/themes/osha_frontend/images/twitterTop.png" alt="Twitter"></a>
		<a href="https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork"><img src="/sites/all/themes/osha_frontend/images/facebookTop.png" alt="Facebook"></a>
		<a href="http://www.linkedin.com/company/european-agency-for-safety-and-health-at-work"><img src="/sites/all/themes/osha_frontend/images/inTop.png" alt="In"></a>
		<a href="https://www.youtube.com/user/EUOSHA"><img src="/sites/all/themes/osha_frontend/images/youTubeTop.png" alt="YouTube"></a>
		<a href="<?php echo url('tools-and-publications/blog', array('alias' => TRUE)); ?>"><img src="/sites/all/themes/osha_frontend/images/bloggerTop.png" alt="Blogger"></a>
	</div>
</div>
<div id="languagesAndSearch">
	<div id="contact"><?php print l(t('News & Events'), 'news-events', array('attributes' => array('accesskey' => '2'))) ?> | <?php print l(t('Press'), 'about-eu-osha/press-room') ?> |  <?php print l(t('Contact us'), 'contact-us') ?> <span class="a_small"><a  onclick="zoomSmall()">a</a></span><span class="a_medium"><a onclick="zoomMedium()">a</a></span><span class="a_big"><a  onclick="zoomBig()">a</a></span></div>
	<div>
		<img src="/sites/all/themes/osha_frontend/images/languageico.png" alt="Select language">
	</div>
</div>
<div id="agencyLogo"><a href="<?php echo url('<front>');?>"><img src="/sites/all/themes/osha_frontend/images/eu-osha-logo/EU-OSHA-<?php global $language; print $language->language;?>.png" alt="<?php echo t('European Agency for Safety and Health at Work');?>"></a></div>
<div id="europeLogo"><img src="/sites/all/themes/osha_frontend/images/europeLogo.png" alt="Europe Flag"></div>
<?php print render($content); ?>

