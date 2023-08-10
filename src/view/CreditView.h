#ifndef CPP3_SMARTCALC_V2_0_1_CREDITVIEW_H
#define CPP3_SMARTCALC_V2_0_1_CREDITVIEW_H

#include <gtkmm.h>

namespace s21 {
class CreditView : public Gtk::Window {
 public:
  CreditView();

 private:
  Glib::RefPtr<Gtk::Builder> builder_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CREDITVIEW_H
