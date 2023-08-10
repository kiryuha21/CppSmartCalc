#ifndef CPP3_SMARTCALC_V2_0_1_CREDITVIEW_H
#define CPP3_SMARTCALC_V2_0_1_CREDITVIEW_H

#include <gtkmm.h>

#include "../controller/CreditController.h"

namespace s21 {
class CreditView : public Gtk::Window {
 public:
  CreditView(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder);
  ~CreditView() override;

 private:
  void on_calculate_button_clicked();

  Glib::RefPtr<Gtk::Builder> builder_;
  CreditController* controller_ = nullptr;

  Gtk::RadioButton* annuity_radio_ = nullptr;
  Gtk::Button* calculate_button_ = nullptr;

  Gtk::Entry* amount_entry_ = nullptr;
  Gtk::Entry* term_entry_ = nullptr;
  Gtk::Entry* rate_entry_ = nullptr;

  Gtk::TextView* monthly_payment_view_ = nullptr;
  Gtk::TextView* overpayment_view_ = nullptr;
  Gtk::TextView* total_payment_view_ = nullptr;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CREDITVIEW_H
