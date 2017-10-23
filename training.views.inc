<?php

/**
 * Implements hook_views_data().
 */
function training_views_data() {

  $data['training_currencies']['table']['group'] = t('Currency courses');

  $data['training_currencies']['table']['base'] = array(
    'field' => 'c_id', // This is the identifier field for the view.
    'title' => t('Currency courses'),
    'help' => t('Example table contains example content and can be related to nodes.'),
    'weight' => -10,
  );

  $data['training_currencies']['c_id'] = array(
    'title' => t('Example content'),
    'help' => t('Some example content that references a node.'),
  );


  // Example plain text field.
  $data['training_currencies']['c_char_code'] = array(
    'title' => t('Currency char code'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['training_currencies']['c_name'] = array(
    'title' => t('Currency name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['training_currencies']['c_scale'] = array(
    'title' => t('BYN'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['training_currencies']['c_rate'] = array(
    'title' => t('Bank sells'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );


  // Example timestamp field.
  $data['training_currencies']['c_updated_at'] = array(
    'title' => t('Updated'),
    'help' => t('Just a timestamp field.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}