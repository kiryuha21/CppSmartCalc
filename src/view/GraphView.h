#ifndef CPP3_SMARTCALC_V2_0_1_GRAPHVIEW_H
#define CPP3_SMARTCALC_V2_0_1_GRAPHVIEW_H

#include <gtkmm.h>

#include "../controller/EvaluationController.h"
#include "../controller/GraphController.h"

namespace s21 {
class GraphView : public Gtk::Window {
 public:
  GraphView(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder,
            const std::string& expression,
            EvaluationController* eval_controller);
  ~GraphView() override;

 private:
  void on_plot_button_clicked() const noexcept;

  Glib::RefPtr<Gtk::Builder> builder_;
  std::string expression_;

  Gtk::Entry* min_x_entry_ = nullptr;
  Gtk::Entry* max_x_entry_ = nullptr;
  Gtk::Entry* min_y_entry_ = nullptr;
  Gtk::Entry* max_y_entry_ = nullptr;

  Gtk::Button* plot_button_ = nullptr;
  Gtk::Image* graph_image_ = nullptr;
  Gtk::Label* graph_label_ = nullptr;

  GraphController* graph_controller_ = nullptr;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_GRAPHVIEW_H
