<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
<div id="page">

  <header class="header" id="header" role="banner">
    <?php if(isset($blog) && $blog): ?>
      <?php require "header_blog.tpl.php"; ?>
    <?php else: ?>
      <?php require "header.tpl.php"; ?>
    <?php endif; ?>
  </header>
  <?php print $breadcrumb; ?>
  <div id="main">

	<?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_first  = render($page['sidebar_first']);
      // andrei: remove sidebar_second from introduction pages
      $node = menu_get_object();
      if (isset($node) && isset($node->article_type_code) && $node->article_type_code != 'section') {
        unset($page['sidebar_second']);
      }
      $sidebar_second = render($page['sidebar_second']);

    ?>

    <?php if ($sidebar_first): ?>
      <aside class="sidebars_first">
        <?php print $sidebar_first; ?>
      </aside>
    <?php endif; ?>
	<?php if (($sidebar_second) && ($sidebar_first)): ?>
		<div id="content" class="three_column">
	<?php else: ?>
		<div id="content" class="two_column">
	<?php endif; ?>
	<?php print render($page['highlighted']); ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>
	
	 <?php if ($sidebar_second): ?>
      <aside class="sidebars_second">
        <?php print $sidebar_second; ?>
      </aside>
    <?php endif; ?>
	
  </div>

  <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
