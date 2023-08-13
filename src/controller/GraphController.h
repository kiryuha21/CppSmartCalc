#ifndef CPP3_SMARTCALC_V2_0_1_GRAPHCONTROLLER_H
#define CPP3_SMARTCALC_V2_0_1_GRAPHCONTROLLER_H

#include "../model/GraphModel.h"
#include "EvaluationController.h"

namespace s21 {
class GraphController {
 public:
  GraphController(EvaluationController* controller, const std::string& function,
                  const int width, const int height);
  ~GraphController();

  void draw_plot_image(const std::string& min_x, const std::string& max_x,
                       const std::string& min_y,
                       const std::string& max_y) const;

 private:
  GraphModel* model_ = nullptr;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_GRAPHCONTROLLER_H
