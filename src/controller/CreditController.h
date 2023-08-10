#ifndef CPP3_SMARTCALC_V2_0_1_CREDITCONTROLLER_H
#define CPP3_SMARTCALC_V2_0_1_CREDITCONTROLLER_H

#include "../model/CreditModel.h"

namespace s21 {
class CreditController {
 public:
  CreditController();
  ~CreditController();

  void calculate_annuity(const std::string& amount, const std::string& term,
                         const std::string& rate);
  void calculate_differentiated(const std::string& amount,
                                const std::string& term,
                                const std::string& rate);
  std::string get_annuity_monthly_payment();
  std::string get_differentiated_monthly_payment();
  std::string get_total_payment();
  std::string get_overpayment();

 private:
  CreditModel* model_ = nullptr;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CREDITCONTROLLER_H
