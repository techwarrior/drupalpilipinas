<?php
/**
 * @file
 * photo_album.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function photo_album_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'photo_album';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo Album';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Add Photo */
  $handler->display->display_options['fields']['field_gallery_add_photo']['id'] = 'field_gallery_add_photo';
  $handler->display->display_options['fields']['field_gallery_add_photo']['table'] = 'field_data_field_gallery_add_photo';
  $handler->display->display_options['fields']['field_gallery_add_photo']['field'] = 'field_gallery_add_photo';
  $handler->display->display_options['fields']['field_gallery_add_photo']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_add_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_add_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_add_photo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_gallery_add_photo']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_gallery_add_photo']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_gallery_add_photo']['separator'] = '         ';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gallery_field' => 'gallery_field',
  );

  /* Display: Gallery */
  $handler = $view->new_display('entity_view', 'Gallery', 'entity_view_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Add Photo */
  $handler->display->display_options['fields']['field_gallery_add_photo']['id'] = 'field_gallery_add_photo';
  $handler->display->display_options['fields']['field_gallery_add_photo']['table'] = 'field_data_field_gallery_add_photo';
  $handler->display->display_options['fields']['field_gallery_add_photo']['field'] = 'field_gallery_add_photo';
  $handler->display->display_options['fields']['field_gallery_add_photo']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_add_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_add_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_add_photo']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_gallery_add_photo']['settings'] = array(
    'colorbox_node_style' => 'medium',
    'colorbox_image_style' => 'large',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  $handler->display->display_options['fields']['field_gallery_add_photo']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_gallery_add_photo']['separator'] = '                           ';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gallery_field' => 'gallery_field',
  );
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'gallery_field',
  );

  /* Display: Album */
  $handler = $view->new_display('entity_view', 'Album', 'entity_view_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'album',
  );
  $export['photo_album'] = $view;

  return $export;
}
