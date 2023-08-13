#ifndef CPP3_SMARTCALC_V2_0_1_EVALUATIONMODEL_H
#define CPP3_SMARTCALC_V2_0_1_EVALUATIONMODEL_H

#include <algorithm>
#include <cmath>
#include <list>
#include <stack>
#include <stdexcept>

#include "utils.h"

namespace s21 {
class EvaluationModel {
 public:
  EvaluationModel() = default;
  ~EvaluationModel() = default;

  std::list<std::string> parse_line(const std::string& line);
  std::list<std::string> parse_to_polish();
  double apply_polish(const std::string& str_x) const;

 private:
  bool is_unary() const noexcept;
  size_t handle_lexem(const std::string& line, size_t index);

  void handle_binary(std::stack<std::string>& stack,
                     const std::string& lexem) noexcept;

  double parse_variable(const std::string& str_x) const;
  static double apply_binary(std::stack<double>& stack,
                             const std::string& lexem) noexcept;
  static double apply_prefix(std::stack<double>& stack,
                             const std::string& lexem) noexcept;

  std::list<std::string> lexems_ = {};
  std::list<std::string> polished_ = {};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_EVALUATIONMODEL_H
