#ifndef CPP3_SMARTCALC_V2_0_1_MAINWINDOW_H
#define CPP3_SMARTCALC_V2_0_1_MAINWINDOW_H

#include "../controller/EvaluationController.h"
#include "CreditView.h"
#include "DepositView.h"
#include "GraphView.h"

namespace s21 {
class MainWindow : public Gtk::Window {
 public:
  explicit MainWindow(BaseObjectType *obj,
                      Glib::RefPtr<Gtk::Builder> const &builder);
  ~MainWindow() override;

 private:
  void on_credit_calc_button_clicked() const noexcept;
  void on_deposit_calc_button_clicked() const noexcept;
  void on_graph_button_clicked() const noexcept;
  bool on_entry_edited(GdkEventKey *key_event) const noexcept;

  Glib::RefPtr<Gtk::Builder> builder_;

  Gtk::Button *credit_calc_button_ = nullptr;
  Gtk::Button *deposit_calc_button_ = nullptr;
  Gtk::Button *graph_button_ = nullptr;

  Gtk::Entry *expression_input_ = nullptr;
  Gtk::Entry *variable_input_ = nullptr;
  Gtk::TextView *result_view_ = nullptr;

  EvaluationController *controller_ = nullptr;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MAINWINDOW_H
