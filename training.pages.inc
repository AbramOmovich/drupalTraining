<?php

function training_files_page() {
  ctools_include('modal');
  ctools_include('ajax');

  training_load_managed_files();
  $table = [
    'caption' => ctools_modal_text_button(t('Upload file'), 'training/files/nojs', t('Upload file')),
    'header' => [
      '№', 'user_id', 'path', 'status', 'download',
    ],
    'rows' => [],
    'attributes' => [
      'id' => 'uploaded-files-table'
    ],
    'colgroups' => [],
    'sticky' => FALSE,
    'empty' => NULL,
  ];

  ctools_modal_add_js();

  global $user;
  drupal_add_js(array('uid' => $user->uid, ), 'setting');
  drupal_add_css(drupal_get_path('module', 'training') . '/css/uploaded_files.css');
  drupal_add_js(drupal_get_path('module', 'training') . '/js/uploaded_files.js');

  return theme_table($table);
}


