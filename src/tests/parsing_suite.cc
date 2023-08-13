#include <gtest/gtest.h>

#include <list>

#include "../model/EvaluationModel.h"

namespace s21 {
TEST(parsing_suite, parse_correct_unaries) {
  std::string line = "sin(10) cos(15) -tan(20) log(-30) sqrt(12) ln(27)";
  std::list<std::string> correct_res = {
      "sin", "(",  "10.0000000", ")",          "cos",        "(", "15.0000000",
      ")",   "-",  "tan",        "(",          "20.0000000", ")", "log",
      "(",   "~",  "30.0000000", ")",          "sqrt",       "(", "12.0000000",
      ")",   "ln", "(",          "27.0000000", ")"};

  EvaluationModel evaluation;
  std::list<std::string> my_res = evaluation.parse_line(line);

  ASSERT_EQ(my_res, correct_res);
}

TEST(parsing_suite, parse_wrong_unaries) {
  std::string line = "sin(10) cas(20)";

  EvaluationModel evaluation;
  ASSERT_THROW(evaluation.parse_line(line), std::logic_error);
}

TEST(parsing_suite, parse_correct_numbers) {
  std::string line = "12.1 * 13 / 14.15 + 1.0";
  std::list<std::string> correct_res = {"12.1000000", "*", "13.0000000", "/",
                                        "14.1500000", "+", "1.0000000"};

  EvaluationModel evaluation;
  std::list<std::string> my_res = evaluation.parse_line(line);

  ASSERT_EQ(my_res, correct_res);
}

TEST(parsing_suite, parse_wrong_numbers) {
  std::string line = "15.a1";

  EvaluationModel evaluation;
  ASSERT_THROW(evaluation.parse_line(line), std::logic_error);
}
}  // namespace s21