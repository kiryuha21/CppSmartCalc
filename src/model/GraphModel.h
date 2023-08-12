#ifndef CPP3_SMARTCALC_V2_0_1_GRAPHMODEL_H
#define CPP3_SMARTCALC_V2_0_1_GRAPHMODEL_H

#include <gnuplot-iostream.h>

#include <cmath>
#include <fstream>
#include <iomanip>

#include "../controller/EvaluationController.h"

namespace s21 {

constexpr auto kPointsAmount = 100000;
constexpr auto kPointsFileName = "points.txt";
constexpr auto kGraphFileName = "plot.png";

class GraphModel {
 public:
  explicit GraphModel(EvaluationController* eval_controller,
                      const std::string& function, const int width,
                      const int height);
  void generate_plot_image() const;
  void parse_limits(const std::string& min_x, const std::string& max_x,
                    const std::string& min_y, const std::string& max_y);

 private:
  void generate_datafile() const;

  EvaluationController* eval_controller_ = nullptr;

  std::string function_;
  int width_ = 0;
  int height_ = 0;

  double min_x_ = 0;
  double max_x_ = 0;
  double min_y_ = 0;
  double max_y_ = 0;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_GRAPHMODEL_H
