<?php

function training_theme_list() {
  $list = [
    'items' => ['List', 'Table', 'Image', 'Access', ],
    'title' => 'List of links to themes',
    'type'  => 'ol',
    'attributes' => [],
  ];

  foreach ($list['items'] as &$item){
    $item = theme_link([
      'text' => $item,
      'path' => 'training/theme/' . strtolower($item),
      'options' => [
        'attributes' => [],
        'html' => [],
      ],
    ]);
  }

  return theme_item_list($list);
}

function training_theme_table() {
  $table = [
    'header' => [
      'header 1', 'header 2', '', 'header 3',
    ],
    'rows' => [
      [ 'data' => ['1', 'Ivan', '334-342-4334'], ],
      [ 'data' => ['2', 'Antuan', '134-372-5543'], ],
      [ 'data' => ['3', 'Abram', '098-134-5554'], ],
      [ 'data' => ['3', 'Abram', '098-134-5554'], ],
    ],
    'attributes' => [],
    'caption' => 'Theme table sample',
    'colgroups' => [],
    'sticky' => FALSE,
    'empty' => NULL,
  ];

  foreach ($table['rows'] as &$row){
    $row['class'] = ['rowClass'];

    $length = count($row['data']);
    for ($i = 0; $i < $length; $i++){
      if (1 == $i) {
        $row['data'][$i] = ['data' => $row['data'][$i], 'colspan' => 2];
      }
    }
  }

  return theme_table($table);
}

function training_theme_image() {
  $list = [
    'items' => [],
    'title' => 'List of image styles',
    'type'  => 'ul',
    'attributes' => [],
  ];

  $params = [
    'path' => 'modules/image/sample.png',
    'attributes' => [
      'class' => 'simple-image',
    ],
    'width' =>  '',
    'height' => '',
  ];

  $list['items'] []= theme_image($params);
  foreach (array_keys(image_styles()) as $style) {
    $params['style_name'] = $style;
    $list['items'] []= theme_image_style($params);
  }


  return theme_item_list($list);
}

function training_theme_access() {
  if (user_access('access protected content')) {
    return 'Custom access for rendered content';
  }
  else {
    return 'Custom access inversed for rendered content';
  }
}

