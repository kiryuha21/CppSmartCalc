#include "MainWindow.h"

#include <iostream>

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

  expression_input_->set_can_focus(true);

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

void MainWindow::on_credit_calc_button_clicked() { CreditView calc; }

void MainWindow::on_deposit_calc_button_clicked() { DepositView calc; }

void MainWindow::on_graph_button_clicked() { GraphView graph; }

bool MainWindow::on_entry_edited(GdkEventKey* key_event) {
  if (key_event->keyval == GDK_KEY_equal) {
    try {
      std::string raw_input = expression_input_->get_text();
      std::string pure_expression = raw_input.substr(0, raw_input.size() - 1);
      std::replace(pure_expression.begin(), pure_expression.end(), '.', ',');
      std::string res = std::to_string(controller_->evaluate(pure_expression));
      std::replace(res.begin(), res.end(), ',', '.');
      result_view_->get_buffer()->set_text(res);
    } catch (std::logic_error& e) {
      result_view_->get_buffer()->set_text(e.what());
    }
  }

  return true;
}

}  // namespace s21
