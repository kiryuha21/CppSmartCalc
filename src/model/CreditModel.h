#ifndef CPP3_SMARTCALC_V2_0_1_CREDITMODEL_H
#define CPP3_SMARTCALC_V2_0_1_CREDITMODEL_H

#include <cmath>
#include <sstream>
#include <string>

#include "utils.h"

namespace s21 {
class CreditModel {
 public:
  void validate_input(const std::string& amount, const std::string& term,
                      const std::string& rate);
  void calculate_annuity() noexcept;
  void calculate_differentiated() noexcept;
  [[nodiscard]] double get_annuity_monthly_payment() const noexcept;
  [[nodiscard]] std::string get_differentiated_monthly_payment() const noexcept;
  [[nodiscard]] double get_total_payment() const noexcept;
  [[nodiscard]] double get_overpayment() const noexcept;

 private:
  double amount_ = 0;
  double term_ = 0;
  double rate_ = 0;

  double monthly_payment_ = 0;
  double total_payment_ = 0;
  double overpayment_ = 0;

  std::string diff_monthly_payment_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CREDITMODEL_H
