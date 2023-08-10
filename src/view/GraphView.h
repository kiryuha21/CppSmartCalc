#ifndef CPP3_SMARTCALC_V2_0_1_GRAPHVIEW_H
#define CPP3_SMARTCALC_V2_0_1_GRAPHVIEW_H

#include <gtkmm.h>

namespace s21 {
class GraphView : public Gtk::Window {
 public:
  GraphView();

 private:
  Glib::RefPtr<Gtk::Builder> builder_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_GRAPHVIEW_H
