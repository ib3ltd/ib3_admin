<?php
/**
 * @file
 * General theme settings elements.
 */

use Drupal\Core\Form\FormState;
use Drupal\Core\Url;

/**
 * Alter the theme settings form to add our own settings.
 *
 * @param array $form
 *   The form array passed by reference.
 * @param FormState $form_state
 *   The form state array.
 */
function ib3_admin_form_system_theme_settings_alter(array &$form, FormState $form_state) {
  $form['ib3_admin_settings'] = array(
    '#type'   => 'vertical_tabs',
    '#weight' => -10,
    '#prefix' => '<h3>' . t('Configuration') . '</h3>',
  );

  ib3_admin_theme_settings_general($form, $form_state);
}

/**
 * Setup the theme settings form.
 */
function ib3_admin_theme_settings_general(&$form, &$form_state) {
  _ib3_admin_theme_get_colors($form);
  _ib3_admin_theme_get_layout($form);
  _ib3_admin_theme_get_breadcrumb($form);
}

/**
 * Layout form fields.
 */
function _ib3_admin_theme_get_colors(&$form) {
  $form['ib3_admin_color'] = array(
    '#type'  => 'details',
    '#title' => t('Color settings'),
    '#group' => 'ib3_admin_settings',
  );

  $form['ib3_admin_color']['ib3_admin_color_profile'] = array(
    '#type'          => 'select',
    '#title'         => t('Color profiles.'),
    '#default_value' => theme_get_setting('ib3_admin_color_profile'),
    '#options'       => array(
      'ib3' => t('ib3'),
      'marvin'     => t('Marvin'),
    ),
  );
}

/**
 * Layout form fields.
 */
function _ib3_admin_theme_get_layout(&$form) {
  $form['ib3_admin_layout'] = array(
    '#type'  => 'details',
    '#title' => t('Layout settings'),
    '#group' => 'ib3_admin_settings',
  );

  $form['ib3_admin_layout']['ib3_admin_layout_login'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Better login screen'),
    '#description'   => t('Use a better, styled and clean login screen'),
    '#default_value' => theme_get_setting('ib3_admin_layout_login'),
  );
}

/**
 * Breadcrumb form fields.
 */
function _ib3_admin_theme_get_breadcrumb(&$form) {
  $form['ib3_admin_breadcrumb'] = array(
    '#type'  => 'details',
    '#title' => t('Breadcrumb settings'),
    '#group' => 'ib3_admin_settings',
  );
  $form['ib3_admin_breadcrumb']['breadcrumb_options'] = array(
    '#type'   => 'container',
    '#states' => array(
      'invisible' => array(
        ':input[name="ib3_admin_breadcrumb"]' => array('value' => 'no'),
      ),
    ),
  );
  $form['ib3_admin_breadcrumb']['breadcrumb_options']['ib3_admin_breadcrumb_home'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Show home page link in breadcrumb'),
    '#default_value' => theme_get_setting('ib3_admin_breadcrumb_home'),
  );
  $form['ib3_admin_breadcrumb']['breadcrumb_options']['ib3_admin_breadcrumb_trailing'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Append a separator to the end of the breadcrumb'),
    '#default_value' => theme_get_setting('ib3_admin_breadcrumb_trailing'),
    '#description'   => t('Useful when the breadcrumb is placed just before the title.'),
    '#states'        => array(
      'disabled' => array(
        ':input[name="ib3_admin_breadcrumb_title"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['ib3_admin_breadcrumb']['breadcrumb_options']['ib3_admin_breadcrumb_title'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Append the content title to the end of the breadcrumb'),
    '#default_value' => theme_get_setting('ib3_admin_breadcrumb_title'),
    '#description'   => t('Useful when the breadcrumb is not placed just before the title.'),
  );
}

/**
 * A helper function to create a h3 tag.
 *
 * @param string $value
 *   The translated value for in the h3.
 *
 * @return string
 *   The h3 tag.
 */
function _ib3_admin_theme_create_prefix($value) {
  $meta_generator = array(
    '#type'  => 'html_tag',
    '#tag'   => 'h3',
    '#value' => $value,
  );

  return drupal_render($meta_generator);
}
