<?php

function training_files_page() {
  ctools_include('modal');
  ctools_include('ajax');


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

  global $user;
  training_dropSettings('UID', $user->uid);
  training_load_managed_files();
  ctools_modal_add_js();
  drupal_add_css(drupal_get_path('module', 'training') . '/css/uploaded_files.css');
  drupal_add_js(drupal_get_path('module', 'training') . '/js/uploaded_files.js');
  training_dropSettings('loaded', FALSE);

  return theme_table($table);
}


