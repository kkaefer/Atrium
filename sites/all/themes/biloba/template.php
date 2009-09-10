<?php
/*
 * Override of theme_breadcrumb().
 */
function biloba_breadcrumb($breadcrumb) {
  // Get the site-wide space.
  $active_space = spaces_get_space();
  if ($active_space->type === "site" && $active_space->sid == 1) {
    $site_space = $active_space;
    unset($active_space);
  }
  else {
    $site_space = spaces_load("site", 1);
  }

  // Replace first breadcrumb with site-wide space name.
  $home = _biloba_get_space_title($site_space);
  $breadcrumb[0] = "<h1 class='space-title'>" . l($home, '<front>', array('html' => TRUE, 'purl' => array('disabled' => TRUE))) . "</h1>";

  if (isset($active_space) && ($active_space->type === "og" || $active_space->type === "user")) {
    $group = _biloba_get_space_title($active_space);
    $breadcrumb[2] = l($group, '<front>', array('html' => TRUE));
  }

  return '<div class="breadcrumb">'. implode("<span class='divider'>»</span>", $breadcrumb) .'</div>';
}

function _biloba_get_space_title($space) {
  if (!empty($space->settings['logo']['fid'])) {
    $file = db_fetch_object(db_query('SELECT * FROM {files} f WHERE f.fid = %d', $space->settings['logo']['fid']));
    if ($file->filepath && file_exists($file->filepath)) {
      $title = theme('imagecache', 'spaces-logo', $file->filepath, $space->title);
    }
  }
  return isset($title) ? $title : check_plain($space->title);
}