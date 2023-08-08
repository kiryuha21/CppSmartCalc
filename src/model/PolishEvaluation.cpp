#include "PolishEvaluation.h"

namespace s21 {
bool PolishEvaluation::is_solo_char(char sym) noexcept {
  return sym == '+' || sym == '-' || sym == '/' || sym == '*' ||
         sym == '(' || sym == ')' || tolower(sym) == 'x' || sym == '^';
}

bool PolishEvaluation::has_prefix(const std::string& str, const std::string& prefix) noexcept {
  return prefix.size() <= str.size() && prefix == str.substr(0, prefix.size());
}

bool PolishEvaluation::is_unary() const noexcept {
  return lexems_.empty() || lexems_.back() == "(";
}

size_t PolishEvaluation::handle_lexem(const std::string& line, size_t index) {
  if (is_solo_char(line[index])) {
    if (line[index] == '-' && is_unary()) {
      lexems_.emplace_back("~");
    } else if (line[index] != '+' || !is_unary()) {
      lexems_.emplace_back(1, line[index]);
    }
    return 1;
  }

  if (isdigit(line[index]) || line[index] == '.') {
      size_t ptr = 0;
      double num = std::stod(line.c_str() + index, &ptr);
      lexems_.emplace_back(std::to_string(num));
      return ptr;
  }

  const std::vector<std::string> functions = {"sin", "cos", "tan", "log", "mod", "sqrt", "asin", "acos", "atan", "ln"};
  for (const auto& function : functions) {
      if (has_prefix(line.c_str() + index, function)) {
          lexems_.emplace_back(function);
          return function.size();
      }
  }

  throw std::invalid_argument("Unknown symbol!");
}

std::list<std::string> PolishEvaluation::parse_line(const std::string& line) {
  size_t line_size = line.size();
  for (size_t i = 0; i < line_size;) {
    if (line[i] != ' ') {
      i += handle_lexem(line, i);
    } else {
      ++i;
    }
  }
  return lexems_;
}
}  // namespace s21
