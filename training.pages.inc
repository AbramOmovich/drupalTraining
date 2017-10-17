<?php

function training_messages_page($form = NULL){
  training_user_has_messages();

  $output = '';

  if (is_null($form)){
    $form = drupal_get_form('training_send_message_form');
  }
  $output .= drupal_render($form);

  $header = [
    ['data' => '№', 'field' => 'mid', 'sort' => 'desc'],
    ['data' => t('User'), 'field' => 'uid',],
    ['data' => t('Title'), 'field' => 'mid',],
    ['data' => t('Text'), 'field' => 'mid',],
  ];

  $table = [
    'header' => $header,
    'rows' => [],
    'caption' => t('User messages')
  ];

  $messages = db_select('training_messages','fm')
    ->extend('PagerDefault')
    ->extend('TableSort')
    ->orderByHeader($header)
    ->fields('fm', array('mid', 'uid', 'title', 'body'))
    ->limit(5)
    ->execute()
    ->fetchAllAssoc('mid', PDO::FETCH_ASSOC);

  $table['rows'] = $messages;
  foreach ($table['rows'] as &$row){
    $user = entity_load_single('user', $row['uid']);
    $row['uid'] = l($user->name, entity_uri('user', $user)['path']);

    $row [] = training_form_message_image_button('delete-16x16.png', $row['mid'], 'delete');
    $row [] = training_form_message_image_button('edit.png', $row['mid'], 'edit');
  }

  $output .= theme('table', $table);
  $output .= theme('pager');

  return $output;
}

function training_form_message_image_button($imagePath, $mid, $link){
  return [
    'data'=> l(
      theme('image',['path' => drupal_get_path('module', 'training') . "/img/{$imagePath}"]),
      'message/' . $mid . "/{$link}",
      ['html' => TRUE]
    )
  ];
}