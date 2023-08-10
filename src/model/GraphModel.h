#ifndef CPP3_SMARTCALC_V2_0_1_GRAPHMODEL_H
#define CPP3_SMARTCALC_V2_0_1_GRAPHMODEL_H

#include <cmath>
#include <fstream>

#include "../controller/EvaluationController.h"

namespace s21 {
constexpr auto kPointsAmount = 100000;

class GraphModel {
 public:
  explicit GraphModel(EvaluationController* eval_controller);
  void generate_plot_image() const;
  void parse_limits(const std::string& min_x, const std::string& max_x,
                    const std::string& min_y, const std::string& max_y);

 private:
  void generate_datafile() const;

  double min_x_ = 0;
  double max_x_ = 0;
  double min_y_ = 0;
  double max_y_ = 0;
  EvaluationController* eval_controller_ = nullptr;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_GRAPHMODEL_H
