#include "CreditModel.h"

namespace s21 {
void CreditModel::validate_input(const std::string& amount,
                                 const std::string& term,
                                 const std::string& rate) {
  amount_ = to_double(amount);
  term_ = to_double(term);
  rate_ = to_double(rate);
}

void CreditModel::calculate_annuity() noexcept {
  double monthly_rate = rate_ / 1200;
  monthly_payment_ =
      amount_ * monthly_rate / (1 - std::pow(1 + monthly_rate, -term_));
  total_payment_ = monthly_payment_ * term_;
  overpayment_ = total_payment_ - amount_;
}

void CreditModel::calculate_differentiated() noexcept {
  double monthly_rate = rate_ / 1200;
  double base_monthly_payment = amount_ / term_;
  total_payment_ = 0;
  for (int i = 0; i < term_; ++i) {
    total_payment_ += base_monthly_payment +
                      (amount_ - base_monthly_payment * i) * monthly_rate;
  }
  overpayment_ = total_payment_ - amount_;
  diff_monthly_payment_ = to_precised_string(base_monthly_payment) + " + (" +
                          to_precised_string(amount_) + " - " +
                          to_precised_string(base_monthly_payment) +
                          " * (N - 1)) * " + to_precised_string(monthly_rate);
}

double CreditModel::get_annuity_monthly_payment() const noexcept {
  return monthly_payment_;
}

std::string CreditModel::get_differentiated_monthly_payment() const noexcept {
  return diff_monthly_payment_;
}

double CreditModel::get_total_payment() const noexcept {
  return total_payment_;
}

double CreditModel::get_overpayment() const noexcept { return overpayment_; }
}  // namespace s21
