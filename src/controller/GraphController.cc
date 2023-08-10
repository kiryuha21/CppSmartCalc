#include "GraphController.h"

namespace s21 {

GraphController::GraphController(s21::EvaluationController* controller) {
  model_ = new GraphModel(controller);
}

GraphController::~GraphController() { delete model_; }

void GraphController::draw_plot_image(const std::string& min_x,
                                      const std::string& max_x,
                                      const std::string& min_y,
                                      const std::string& max_y) const {
  model_->parse_limits(min_x, max_x, min_y, max_y);
  model_->generate_plot_image();
}

}  // namespace s21
