#include <gtest/gtest.h>

#include <list>

#include "../model/EvaluationModel.h"

namespace s21 {
void test_correct_notation(const std::string& line,
                           const std::list<std::string>& expected) {
  EvaluationModel model;
  model.parse_line(line);
  ASSERT_EQ(model.parse_to_polish(), expected);
}

TEST(polish_notation_suite, wrong_polish) {
  EvaluationModel model;
  model.parse_line("12 * 12 + 1)");
  ASSERT_THROW(model.parse_to_polish(), std::logic_error);
}

TEST(polish_notation_suite, order_test_1) {
  test_correct_notation(
      "12 + 12 / 1 ^ 5",
      {"12.000000", "12.000000", "1.000000", "5.000000", "^", "/", "+"});
}

TEST(polish_notation_suite, order_test_2) {
  test_correct_notation("12^(1+1) + 3", {"12.000000", "1.000000", "1.000000",
                                         "+", "^", "3.000000", "+"});
}

TEST(polish_notation_suite, order_test_3) {
  test_correct_notation(
      "sin(cos(12 + log(5^3)))",
      {"12.000000", "5.000000", "3.000000", "^", "log", "+", "cos", "sin"});
}

}  // namespace s21