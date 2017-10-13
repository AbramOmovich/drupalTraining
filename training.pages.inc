<?php

function training_messages_page(){

  drupal_add_css(drupal_get_path('module', 'training') . '/css/training.css');

  $output = '';

  $form = drupal_get_form('send_message_form');
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
    ->extend('PagerDefault')->extend('TableSort')->orderByHeader($header)
    ->fields('fm', array('mid', 'uid', 'title', 'body'))
    ->limit(5)
    ->execute()->fetchAllAssoc('mid', PDO::FETCH_ASSOC);

  $table['rows'] = $messages;
  foreach ($table['rows'] as &$row){
    $user = entity_load_single('user', $row['uid']);
    $row['uid'] = l($user->name, entity_uri('user', $user)['path']);

    $row [] = [
      'data'=> l(
        theme('image',['path' => drupal_get_path('module', 'training') . '/img/delete-16x16.png']),
        'message/' . $row['mid'] . '/delete',
        ['html' => TRUE]
      )
    ];
    $row [] = [
      'data'=> l(
        theme('image',['path' => drupal_get_path('module', 'training') . '/img/edit.png']),
        'message/' . $row['mid'] . '/edit',
        ['html' => TRUE]
      )
    ];

  }

  $output .= theme('table', $table);
  $output .= theme('pager');

  return $output;
}