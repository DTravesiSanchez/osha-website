<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 */
?>
<?php
$translated = osha_tmgmt_literal_get_translation($title);
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($translated): ?>
    <div class="related_wiki_head"><span><?php print $translated;?><span></div>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php print $content; ?>
</div>
