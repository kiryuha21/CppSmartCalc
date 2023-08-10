#include <gtest/gtest.h>

#include <cmath>

#include "../model/EvaluationModel.h"

constexpr auto EPS = 1e-7;

namespace s21 {
void calculate(const std::string& expression, const std::string& input,
               double expected) {
  EvaluationModel model;
  model.parse_line(expression);
  model.parse_to_polish();
  double res = model.apply_polish(input);
  ASSERT_NEAR(res, expected, EPS);
}

void erroneous_calculate(const std::string& expression,
                         const std::string& input) {
  EvaluationModel model;
  model.parse_line(expression);
  model.parse_to_polish();
  ASSERT_THROW(model.apply_polish(input), std::logic_error);
}

TEST(calculation_suite, pure_calculation_1) { calculate("1+2/2^2", "", 1.5); }

TEST(calculation_suite, pure_calculation_2) {
  calculate("-sin(10^2 * cos(30))", "",
            -std::sin(std::pow(10, 2) * std::cos(30)));
}

TEST(calculation_suite, pure_calculation_3) {
  calculate("10 * 0.5 - 5.5", "", -0.5);
}

TEST(calculation_suite, pure_calculation_4) {
  calculate("5 mod 12 - 5.5 mod 3.5", "", 5 - std::fmod(5.5, 3.5));
}

TEST(calculation_suite, variable_calculation_1) {
  calculate("1+x/x^x", "2", 1 + 2 / std::pow(2, 2));
}

TEST(calculation_suite, variable_calculation_2) {
  calculate("-sin(10^2 * cos(x))", "30",
            -std::sin(std::pow(10, 2) * std::cos(30)));
}

TEST(calculation_suite, variable_calculation_3) {
  calculate("sin(asin(x)) + cos(acos(x)) + tan(atan(x))", "1", 3);
}

TEST(calculation_suite, variable_calculation_4) {
  calculate("sqrt(log(x)^2)", "100000", 5);
}

TEST(calculation_suite, variable_calculation_5) {
  calculate("ln x + log 10", std::to_string(std::exp(1)), 2);
}

TEST(calculation_suite, calculation_with_error_1) {
  erroneous_calculate("12 + 15 12", "");
}

TEST(calculation_suite, calculation_with_error_2) {
  erroneous_calculate("5+", "");
}

TEST(calculation_suite, calculation_with_error_3) {
  erroneous_calculate("sin()", "");
}

TEST(calculation_suite, calculation_with_error_4) {
  erroneous_calculate("12.12.1 + 5", "");
}

TEST(calculation_suite, variable_test_1) {
  erroneous_calculate("12.12 + x", "");
}

TEST(calculation_suite, variable_test_2) {
  erroneous_calculate("12.12 + x", "12.12.12");
}

TEST(calculation_suite, variable_test_3) {
  erroneous_calculate("12.12 + x", "12a");
}
}  // namespace s21