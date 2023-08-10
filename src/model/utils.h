#ifndef CPP3_SMARTCALC_V2_0_1_UTILS_H
#define CPP3_SMARTCALC_V2_0_1_UTILS_H

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

namespace s21 {
enum Priorities { LOW_PRIORITY = 1, HIGH_PRIORITY, HIGHEST_PRIORITY };

bool is_solo_char(char sym) noexcept;
bool is_prefix(const std::string& lexem) noexcept;
bool is_binary(const std::string& lexem) noexcept;
bool is_num(const std::string& lexem) noexcept;

bool has_prefix(const std::string& str, const std::string& prefix) noexcept;
int get_priority(const std::string& lexem) noexcept;
double to_double(const std::string& str);

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_UTILS_H
