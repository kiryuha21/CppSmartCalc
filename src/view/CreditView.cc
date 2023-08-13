#include "CreditView.h"

namespace s21 {
CreditView::CreditView(BaseObjectType* obj,
                       Glib::RefPtr<Gtk::Builder> const& builder)
    : Gtk::Window(obj), builder_{builder} {
  controller_ = new CreditController;

  builder_->get_widget("annuity_radio", annuity_radio_);
  builder_->get_widget("credit_label", credit_label_);
  builder_->get_widget("amount_entry", amount_entry_);
  builder_->get_widget("term_entry", term_entry_);
  builder_->get_widget("rate_entry", rate_entry_);
  builder_->get_widget("monthly_payment_view", monthly_payment_view_);
  builder_->get_widget("overpayment_view", overpayment_view_);
  builder_->get_widget("total_payment_view", total_payment_view_);
  builder_->get_widget("calculate_button", calculate_button_);

  calculate_button_->signal_clicked().connect(
      sigc::mem_fun(*this, &CreditView::on_calculate_button_clicked));
}

CreditView::~CreditView() { delete controller_; }

void CreditView::on_calculate_button_clicked() const noexcept {
  std::string amount = amount_entry_->get_text();
  std::string term = term_entry_->get_text();
  std::string rate = rate_entry_->get_text();

  try {
    if (annuity_radio_->get_active()) {
      controller_->calculate_annuity(amount, term, rate);
      monthly_payment_view_->get_buffer()->set_text(
          controller_->get_annuity_monthly_payment());
    } else {
      controller_->calculate_differentiated(amount, term, rate);
      monthly_payment_view_->get_buffer()->set_text(
          controller_->get_differentiated_monthly_payment());
    }
  } catch (std::logic_error& e) {
    credit_label_->set_text(e.what());
    return;
  }

  total_payment_view_->get_buffer()->set_text(controller_->get_total_payment());
  overpayment_view_->get_buffer()->set_text(controller_->get_overpayment());
}

}  // namespace s21
