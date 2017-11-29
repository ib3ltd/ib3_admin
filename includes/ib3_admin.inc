<?php

/**
 * @file
 * Contains functions needed for the theme.
 */

global $_ib3_admin_path_to_core;
$_ib3_admin_path_to_core = drupal_get_path('theme', 'ib3_admin');

/**
 * Get theme functionalities.
 */
function ib3_admin_get_theme(&$variables) {
  ib3_admin_load_debuggers($variables);
  ib3_admin_add_libraries($variables);
}

/**
 * Get the path to the static files folder in the theme.
 */
function ib3_admin_get_staticpath($addprefix = FALSE, $theme_key = 'ib3_admin') {
  $ret = '';
  if ($addprefix) {
    $ret = '/';
  }
  $ret .= drupal_get_path('theme', $theme_key) . '/static/';
  return $ret;
}

/**
 * Add libraries to the theme.
 */
function ib3_admin_add_libraries(&$variables) {
  $enquire = theme_get_setting('ib3_admin_enquire_js');
  if (!empty($enquire)) {
    $variables['page']['#attached']['library'][] = 'ib3_admin/enquire';
  }

  $transit = theme_get_setting('ib3_admin_transit_js');
  if (!empty($transit)) {
    $variables['page']['#attached']['library'][] = 'ib3_admin/transit';
  }

  $placeholder = theme_get_setting('ib3_admin_placeholder_js');
  if (!empty($placeholder)) {
    $variables['page']['#attached']['library'][] = 'ib3_admin/placeholder';
  }

  $prettify = theme_get_setting('ib3_admin_prettify_js');
  if (!empty($prettify)) {
    $variables['page']['#attached']['drupalSettings']['ib3_admin']['prettify_hide_upload'] = theme_get_setting('ib3_admin_prettify_js_hide_upload');
    $variables['page']['#attached']['drupalSettings']['ib3_admin']['prettify_add_remove'] = theme_get_setting('ib3_admin_prettify_js_add_remove');
    $variables['page']['#attached']['library'][] = 'ib3_admin/prettify';
  }
}

/**
 * Load debugging helper files.
 */
function ib3_admin_load_debuggers(&$variables) {
  $debug = FALSE;
  // Load window size bookmarklet.
  if (theme_get_setting('ib3_admin_show_window_size') === 1) {
    $debug = TRUE;
    $variables['page']['#attached']['library'][] = 'ib3_admin/windowsize';
  }
  if (theme_get_setting('ib3_admin_show_grid') === 1) {
    $debug = TRUE;
    $variables['page']['#attached']['library'][] = 'ib3_admin/grid';
  }
  if ($debug) {
    drupal_set_message(t('Please turn off ib3 debuggers on production websites.'), 'warning');
  }
}