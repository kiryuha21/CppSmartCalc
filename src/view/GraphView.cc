#include "GraphView.h"

namespace s21 {
GraphView::GraphView(BaseObjectType* obj,
                     Glib::RefPtr<Gtk::Builder> const& builder,
                     const std::string& expression,
                     EvaluationController* eval_controller)
    : Gtk::Window(obj), builder_{builder}, expression_(expression) {
  graph_controller_ = new GraphController(eval_controller);

  builder_->get_widget("min_x_entry", min_x_entry_);
  builder_->get_widget("max_x_entry", max_x_entry_);
  builder_->get_widget("min_y_entry", min_y_entry_);
  builder_->get_widget("max_y_entry", max_y_entry_);
}

GraphView::~GraphView() { delete graph_controller_; }

}  // namespace s21