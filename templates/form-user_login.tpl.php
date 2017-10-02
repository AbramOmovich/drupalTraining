<table>
  <caption><?php print t('User login form') ?></caption>
  <tbody>
  <tr class="rowClass odd"> <td><?php print render($form['name']); ?></td></tr>
  <tr class="rowClass even"><td><?php print render($form['pass']); ?></td></tr>
  <tr class="rowClass odd"> <td><?php print render($form['secret_key']); ?></td></tr>
  </tbody>

</table>
<?php print drupal_render_children($form); ?>