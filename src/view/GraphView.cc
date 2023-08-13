#include "GraphView.h"

namespace s21 {
GraphView::GraphView(BaseObjectType* obj,
                     Glib::RefPtr<Gtk::Builder> const& builder,
                     const std::string& expression,
                     EvaluationController* eval_controller)
    : Gtk::Window(obj), builder_{builder}, expression_(expression) {
  builder_->get_widget("min_x_entry", min_x_entry_);
  builder_->get_widget("max_x_entry", max_x_entry_);
  builder_->get_widget("min_y_entry", min_y_entry_);
  builder_->get_widget("max_y_entry", max_y_entry_);
  builder_->get_widget("plot_button", plot_button_);
  builder_->get_widget("graph_image", graph_image_);
  builder_->get_widget("graph_label", graph_label_);

  plot_button_->signal_clicked().connect(
      sigc::mem_fun(*this, &GraphView::on_plot_button_clicked));

  graph_controller_ = new GraphController(eval_controller, expression,
                                          graph_image_->get_allocated_width(),
                                          graph_image_->get_allocated_height());
}

GraphView::~GraphView() { delete graph_controller_; }

void GraphView::on_plot_button_clicked() const noexcept {
  try {
    graph_controller_->draw_plot_image(
        min_x_entry_->get_text(), max_x_entry_->get_text(),
        min_y_entry_->get_text(), max_y_entry_->get_text());
  } catch (std::logic_error& e) {
    graph_label_->set_text(e.what());
    return;
  }
  graph_image_->set(kGraphFileName);
  graph_image_->queue_draw();
}

}  // namespace s21