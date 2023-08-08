#ifndef CPP3_SMARTCALC_V2_0_1_POLISHEVALUATION_H
#define CPP3_SMARTCALC_V2_0_1_POLISHEVALUATION_H

#include <list>
#include <string>
#include <vector>
#include <stdexcept>

namespace s21 {
class PolishEvaluation {
 public:
    std::list<std::string> parse_line(const std::string& line);

private:
  static bool is_solo_char(char sym) noexcept;
  static bool has_prefix(const std::string& str, const std::string& prefix) noexcept;
  bool is_unary() const noexcept;

  size_t handle_lexem(const std::string& line, size_t index);

  std::list<std::string> lexems_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_POLISHEVALUATION_H
