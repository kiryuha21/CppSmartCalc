#ifndef CPP3_SMARTCALC_V2_0_1_DEPOSITVIEW_H
#define CPP3_SMARTCALC_V2_0_1_DEPOSITVIEW_H

#include <gtkmm.h>

namespace s21 {
class DepositView : public Gtk::Window {
 public:
  DepositView();

 private:
  Glib::RefPtr<Gtk::Builder> builder_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_DEPOSITVIEW_H