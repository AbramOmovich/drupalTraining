<?php
  $currencies = $block['#block']->currencies;

  if (empty($currencies)) {
    print t('No currencies available');
  }
  else {
    $table = [
      'header' => [
        t('Name'), t('Scale'), t('Rate'),
      ],
      'rows' => [],
      'attributes' => [],
      'caption' => "Currencies on {$block['#block']->date}",
      'colgroups' => [],
      'sticky' => FALSE,
      'empty' => NULL,
    ];
    foreach ($currencies as $currency){
      $table['rows'] []= [ $currency['CharCode'], $currency['Scale'], $currency['Rate']];
    }
    print theme_table($table);
  }

