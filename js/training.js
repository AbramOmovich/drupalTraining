(function ($) {
  Drupal.ajax.prototype.commands.alert_message = function (ajax, response, status) {
    alert(Drupal.t("You was registered !register_date. There are !days_remain till New Year.", {
      "!register_date" : Drupal.settings.register_date,
      "!days_remain"   : Drupal.settings.days_remain
  }));
  };

  Drupal.ajax.prototype.commands.training_insert_text = function (ajax, response, status) {
    $('#edit-text').val(Drupal.settings.safe_string);
  };
})(jQuery);