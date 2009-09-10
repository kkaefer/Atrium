<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <?php print $head ?>
    <?php print $styles ?>
    <title><?php print $head_title ?></title>
  </head>
  <body <?php print drupal_attributes($attr) ?>>

  <?php if ($admin) print $admin ?>

  <?php if ($messages): ?><div id='growl'><?php print $messages; ?></div><?php endif; ?>

  <div id='global' class='atrium-skin'><div class='limiter clear-block'>
    <?php print $breadcrumb; ?>
    <?php if ($header || $search_box): ?>
      <div id='header'><div class='toggle-blocks clear-block'>
        <?php // if ($search_box) print $search_box; ?>
        <?php if ($header) print $header; ?>
      </div></div>
    <?php endif; ?>
  </div></div>

  <?php if ($primary_links): ?>
  <div id='navigation' class='atrium-skin'><div class='limiter clear-block'>
    <?php if (isset($primary_links)) print theme('links', $primary_links, array('id' => 'features-menu', 'class' => 'links primary-links')) ?>
    <?php if ($space_tools || $space_user_links): ?>
      <div id='space-tools'>
        <?php if ($space_user_links) print $space_user_links; ?>
        <?php if ($space_tools): ?>
          <div class='dropdown-blocks toggle-blocks clear-block'><?php print $space_tools ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
  </div></div>
  <?php endif; ?>

  <div id='page-header'><div class='limiter clear-block'>
    <div id='page-tools'>
      <?php if ($page_tools): ?><div class='dropdown-blocks toggle-blocks clear-block'><?php print $page_tools ?></div><?php endif; ?>
      <?php if ($context_links): ?><div class='context-links'><?php print $context_links ?></div><?php endif; ?>
    </div>
    <?php if ($title): ?><h2 class='page-title'><?php print $title ?></h2><?php endif; ?>
    <?php if ($tabs):?><div class='tabs'><?php print $tabs ?></div><?php endif; ?>
  </div></div>

  <div id='page'><div class='limiter clear-block'>

    <?php if ($tabs2) print $tabs2 ?>

    <?php if (!empty($custom_layout)): ?>
      <?php print $content ?>
    <?php else: ?>
      <?php if ($mission): ?><div class="mission"><?php print $mission ?></div><?php endif; ?>
      <div id='content'><div class='main clear-block'>
        <?php print $content ?>
      </div></div>
      <?php if ($right): ?>
        <div id='right'><div class='sidebar clear-block'><?php print $right ?></div></div>
      <?php endif; ?>
    <?php endif; ?>

  </div></div>

  <?php if (!empty($footer_message)): ?>
    <div id="footer"><div class='limiter clear-block'><?php print $footer_message ?></div></div>
  <?php endif; ?>

  <?php print $scripts ?>
  <?php print $closure ?>

  </body>
</html>
