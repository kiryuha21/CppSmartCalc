#include "MainWindow.h"

namespace s21 {

MainWindow::MainWindow(BaseObjectType* obj,
                       Glib::RefPtr<Gtk::Builder> const& builder)
    : Gtk::Window(obj), builder_{builder} {
  controller_ = new EvaluationController();

  builder_->get_widget("credit_calc_button", credit_calc_button_);
  builder_->get_widget("deposit_calc_button", deposit_calc_button_);
  builder_->get_widget("graph_button", graph_button_);
  builder_->get_widget("expression_input", expression_input_);
  builder_->get_widget("variable_input", variable_input_);
  builder_->get_widget("result_view", result_view_);

  credit_calc_button_->signal_clicked().connect(
      sigc::mem_fun(*this, &MainWindow::on_credit_calc_button_clicked));
  deposit_calc_button_->signal_clicked().connect(
      sigc::mem_fun(*this, &MainWindow::on_deposit_calc_button_clicked));
  graph_button_->signal_clicked().connect(
      sigc::mem_fun(*this, &MainWindow::on_graph_button_clicked));
  expression_input_->signal_key_release_event().connect(
      sigc::mem_fun(*this, &MainWindow::on_entry_edited));
}

MainWindow::~MainWindow() { delete controller_; }

void MainWindow::on_credit_calc_button_clicked() const noexcept {
  CreditView* credit = nullptr;
  auto builder = Gtk::Builder::create_from_file("ui/credit.ui");
  builder->get_widget_derived("credit_window", credit);
}

void MainWindow::on_deposit_calc_button_clicked() const noexcept {
  DepositView* deposit = nullptr;
  auto builder = Gtk::Builder::create_from_file("ui/deposit.ui");
  builder->get_widget_derived("deposit_window", deposit);
}

void MainWindow::on_graph_button_clicked() const noexcept {
  std::string raw_input = expression_input_->get_text();
  try {
    controller_->evaluate(raw_input, "0");

    GraphView* graph = nullptr;
    auto builder = Gtk::Builder::create_from_file("ui/graph.ui");
    builder->get_widget_derived("graph_window", graph, raw_input, controller_);
  } catch (std::logic_error& e) {
    result_view_->get_buffer()->set_text(e.what());
  }
}

bool MainWindow::on_entry_edited(GdkEventKey* key_event) const noexcept {
  if (key_event->keyval != GDK_KEY_equal) {
    return true;
  }

  try {
    std::string raw_input = expression_input_->get_text();
    std::string pure_expression = raw_input.substr(0, raw_input.size() - 1);

    double res =
        controller_->evaluate(pure_expression, variable_input_->get_text());
    result_view_->get_buffer()->set_text(to_precised_string(res));
  } catch (std::logic_error& e) {
    result_view_->get_buffer()->set_text(e.what());
  }

  return true;
}

}  // namespace s21
