#include <gtest/gtest.h>

#include "../model/CreditModel.h"

constexpr auto EPS = 1e-7;

namespace s21 {
TEST(credit_calculation_suite, input_error_1) {
  CreditModel model;
  ASSERT_THROW(model.validate_input("aaa", "1", "1"), std::logic_error);
}

TEST(credit_calculation_suite, input_error_2) {
  CreditModel model;
  ASSERT_THROW(model.validate_input("1", "aaa", "1"), std::logic_error);
}

TEST(credit_calculation_suite, input_error_3) {
  CreditModel model;
  ASSERT_THROW(model.validate_input("1", "1", "aaa"), std::logic_error);
}

TEST(credit_calculation_suite, annuity_calculation) {
  CreditModel model;
  model.validate_input("100000", "12", "5");
  model.calculate_annuity();

  ASSERT_NEAR(model.get_annuity_monthly_payment(), 8560.7481788, EPS);
  ASSERT_NEAR(model.get_overpayment(), 2728.9781462, EPS);
  ASSERT_NEAR(model.get_total_payment(), 102728.9781462, EPS);
}

TEST(credit_calculation_suite, differentiated_calculation) {
  CreditModel model;
  model.validate_input("100000", "12", "5");
  model.calculate_differentiated();

  ASSERT_NEAR(model.get_overpayment(), 2708.3333333, EPS);
  ASSERT_NEAR(model.get_total_payment(), 102708.3333333, EPS);
}
}  // namespace s21