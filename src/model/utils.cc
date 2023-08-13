#include "utils.h"

namespace s21 {
bool is_solo_char(char sym) noexcept {
  return sym == '+' || sym == '-' || sym == '/' || sym == '*' || sym == '(' ||
         sym == ')' || tolower(sym) == 'x' || sym == '^';
}

bool is_prefix(const std::string& lexem) noexcept {
  static std::vector<std::string> prefixes = {
      "sin", "cos", "tan", "log", "sqrt", "ln", "asin", "acos", "atan", "~"};
  return std::find(prefixes.begin(), prefixes.end(), lexem) != prefixes.end();
}

bool is_binary(const std::string& lexem) noexcept {
  static std::vector<std::string> binaries = {"+", "*", "/", "-", "^", "mod"};
  return std::find(binaries.begin(), binaries.end(), lexem) != binaries.end();
}

bool is_num(const std::string& lexem) noexcept {
  if (lexem == "x") {
    return true;
  }

  size_t ptr = 0;
  try {
    std::stod(lexem, &ptr);
  } catch (std::invalid_argument&) {
    return false;
  }
  return true;
}

bool has_prefix(const std::string& str, const std::string& prefix) noexcept {
  return prefix.size() <= str.size() && prefix == str.substr(0, prefix.size());
}

int get_priority(const std::string& lexem) noexcept {
  if (lexem == "+" || lexem == "-") {
    return LOW_PRIORITY;
  }

  if (lexem == "*" || lexem == "/" || lexem == "mod") {
    return HIGH_PRIORITY;
  }

  if (lexem == "^") {
    return HIGHEST_PRIORITY;
  }

  return 0;
}

double to_double(const std::string& str) {
  size_t ptr = 0;
  double res = 0;

  try {
    res = std::stod(str, &ptr);
  } catch (std::invalid_argument& e) {
    throw std::logic_error("Conversion error!");
  }
  if (ptr != str.size()) {
    throw std::logic_error("Conversion error!");
  }

  return res;
}

std::string to_precised_string(double val) noexcept {
  std::stringstream ss;
  ss << std::setprecision(kDefaultPrecision) << std::fixed << val;
  return ss.str();
}

}  // namespace s21
