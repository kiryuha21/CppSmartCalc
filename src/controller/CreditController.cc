#include "CreditController.h"

namespace s21 {

CreditController::CreditController() { model_ = new CreditModel; }

CreditController::~CreditController() { delete model_; }

void CreditController::calculate_annuity(const std::string& amount,
                                         const std::string& term,
                                         const std::string& rate) const {
  model_->validate_input(amount, term, rate);
  model_->calculate_annuity();
}

void CreditController::calculate_differentiated(const std::string& amount,
                                                const std::string& term,
                                                const std::string& rate) const {
  model_->validate_input(amount, term, rate);
  model_->calculate_differentiated();
}

std::string CreditController::get_annuity_monthly_payment() const noexcept {
  return to_precised_string(model_->get_annuity_monthly_payment());
}

std::string CreditController::get_differentiated_monthly_payment()
    const noexcept {
  return model_->get_differentiated_monthly_payment();
}

std::string CreditController::get_total_payment() const noexcept {
  return to_precised_string(model_->get_total_payment());
}

std::string CreditController::get_overpayment() const noexcept {
  return to_precised_string(model_->get_overpayment());
}
}  // namespace s21
