<?php
/**
 * @file
 * featured_blog.features.inc
 */

/**
 * Implements hook_views_api().
 */
function featured_blog_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function featured_blog_image_default_styles() {
  $styles = array();

  // Exported image style: blog_290x191.
  $styles['blog_290x191'] = array(
    'name' => 'blog_290x191',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 290,
          'height' => 191,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
