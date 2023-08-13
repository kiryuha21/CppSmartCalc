#include "EvaluationModel.h"

namespace s21 {
bool EvaluationModel::is_unary() const noexcept {
  return lexems_.empty() || lexems_.back() == "(";
}

size_t EvaluationModel::handle_lexem(const std::string& line, size_t index) {
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
    lexems_.emplace_back(to_precised_string(num));
    return ptr;
  }

  const static std::vector<std::string> functions = {
      "sin", "cos", "tan", "log", "mod", "sqrt", "asin", "acos", "atan", "ln"};
  for (const auto& function : functions) {
    if (has_prefix(line.c_str() + index, function)) {
      lexems_.emplace_back(function);
      return function.size();
    }
  }

  throw std::logic_error("Unknown symbol!");
}

std::list<std::string> EvaluationModel::parse_line(const std::string& line) {
  lexems_.clear();
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

void EvaluationModel::handle_binary(std::stack<std::string>& stack,
                                    const std::string& lexem) noexcept {
  while (!stack.empty() && (is_prefix(stack.top()) ||
                            get_priority(stack.top()) >= get_priority(lexem))) {
    polished_.push_back(stack.top());
    stack.pop();
  }
  stack.push(lexem);
}

std::list<std::string> EvaluationModel::parse_to_polish() {
  polished_.clear();

  std::stack<std::string> operations_stack;
  for (const auto& lexem : lexems_) {
    if (is_prefix(lexem) || lexem == "(") {
      operations_stack.push(lexem);
    } else if (is_num(lexem)) {
      polished_.push_back(lexem);
    } else if (lexem == ")") {
      while (!operations_stack.empty() && operations_stack.top() != "(") {
        polished_.push_back(operations_stack.top());
        operations_stack.pop();
      }

      if (operations_stack.empty()) {
        throw std::logic_error("Error while parsing to polish notation");
      }

      operations_stack.pop();
    } else {  // is binary
      handle_binary(operations_stack, lexem);
    }
  }

  while (!operations_stack.empty()) {
    polished_.push_back(operations_stack.top());
    operations_stack.pop();
  }

  return polished_;
}

double EvaluationModel::parse_variable(const std::string& str_x) const {
  if (str_x.empty()) {
    if (std::find(polished_.begin(), polished_.end(), "x") != polished_.end()) {
      throw std::logic_error("Missing variable's value!");
    }

    return 0;
  }

  return to_double(str_x);
}

double EvaluationModel::apply_binary(std::stack<double>& stack,
                                     const std::string& lexem) noexcept {
  double result;

  double first = stack.top();
  stack.pop();
  double second = stack.top();
  stack.pop();

  if (lexem == "-") {
    result = second - first;
  } else if (lexem == "+") {
    result = second + first;
  } else if (lexem == "/") {
    result = second / first;
  } else if (lexem == "^") {
    result = pow(second, first);
  } else if (lexem == "mod") {
    result = fmod(second, first);
  } else {  // lexem == *
    result = second * first;
  }

  return result;
}

double EvaluationModel::apply_prefix(std::stack<double>& stack,
                                     const std::string& lexem) noexcept {
  double result;

  double first = stack.top();
  stack.pop();

  if (lexem == "sin") {
    result = sin(first);
  } else if (lexem == "cos") {
    result = cos(first);
  } else if (lexem == "tan") {
    result = tan(first);
  } else if (lexem == "log") {
    result = log10(first);
  } else if (lexem == "sqrt") {
    result = sqrt(first);
  } else if (lexem == "ln") {
    result = log(first);
  } else if (lexem == "asin") {
    result = asin(first);
  } else if (lexem == "acos") {
    result = acos(first);
  } else if (lexem == "atan") {
    result = atan(first);
  } else {  // lexem == "~"
    result = -first;
  }

  return result;
}

double EvaluationModel::apply_polish(const std::string& str_x) const {
  double result = 0;
  std::stack<double> stack;
  for (const auto& lexem : polished_) {
    if (is_num(lexem)) {
      if (lexem == "x") {
        result = parse_variable(str_x);
      } else {
        result = std::stod(lexem);
      }
    } else if (is_binary(lexem)) {
      if (stack.size() < 2) {
        throw std::logic_error(
            "Error while applying polish notation(not enough operands)");
      }

      result = apply_binary(stack, lexem);
    } else if (is_prefix(lexem)) {  // if prefix
      if (stack.empty()) {
        throw std::logic_error(
            "Error while applying polish notation(not enough arguments)");
      }

      result = apply_prefix(stack, lexem);
    } else {
      throw std::logic_error(
          "Error while applying polish notation(unknown operation)");
    }
    stack.push(result);
  }

  if (stack.empty()) {
    throw std::logic_error("Error while applying polish notation(no result)");
  }

  result = stack.top();
  stack.pop();

  if (!stack.empty()) {
    throw std::logic_error(
        "Error while applying polish notation(extra values)");
  }

  return result;
}

}  // namespace s21
