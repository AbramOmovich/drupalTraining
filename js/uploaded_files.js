(function ($) {
  Drupal.behaviors.drawTable = {
    attach: function (context, settings) {

      if (!Drupal.settings.loaded){
        var filesTable = $('#uploaded-files-table');
        filesTable.find('tr:not(:first)').remove();
        if (typeof Drupal.settings.files !== 'undefined' && Drupal.settings.files.length > 0) {
          var odd = 'odd';
          var even = 'even';
          var i = 1;
          var row = '';
          Drupal.settings.files.forEach(function (element, index, array) {
            row += '<tr><td>' + element.fid + '</td>';
            row += '<td>' + element.uid + '</td>';
            row += '<td>' + element.uri + '</td>';
            row += '<td>' + element.status + '</td>';
            row += '<td>' + '<a href="' + element.uri + '" target="_blank">Download</a>' + '</td>';
            row += '</tr>';
            row = $(row);
            if (i % 2 !== 0) {
              row.addClass(odd);
            }
            else {
              row.addClass(even);
            }
            i++;
            if (element.uid === Drupal.settings.UID){
              row.addClass('personal-file');
            }
            filesTable.append(row);

          });
          Drupal.settings.loaded = true;
        }
      }
    }
  };
}(jQuery));