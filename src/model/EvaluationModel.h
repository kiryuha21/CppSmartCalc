#ifndef CPP3_SMARTCALC_V2_0_1_EVALUATIONMODEL_H
#define CPP3_SMARTCALC_V2_0_1_EVALUATIONMODEL_H

#include <algorithm>
#include <cmath>
#include <list>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

namespace s21 {
class EvaluationModel {
 public:
  std::list<std::string> parse_line(const std::string& line);
  std::list<std::string> parse_to_polish();
  double apply_polish(double x);

 private:
  enum Priorities { LOW_PRIORITY = 1, HIGH_PRIORITY, HIGHEST_PRIORITY };

  static bool is_solo_char(char sym) noexcept;
  static bool has_prefix(const std::string& str,
                         const std::string& prefix) noexcept;
  [[nodiscard]] bool is_unary() const noexcept;
  size_t handle_lexem(const std::string& line, size_t index);

  static bool is_prefix(const std::string& lexem) noexcept;
  static bool is_binary(const std::string& lexem) noexcept;
  static int get_priority(const std::string& lexem) noexcept;
  void handle_binary(std::stack<std::string>& stack, const std::string& lexem);

  static double apply_binary(std::stack<double>& stack,
                             const std::string& lexem);
  static double apply_prefix(std::stack<double>& stack,
                             const std::string& lexem);

  std::list<std::string> lexems_ = {};
  std::list<std::string> polished_ = {};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_EVALUATIONMODEL_H
