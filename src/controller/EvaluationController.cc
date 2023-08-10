#include "EvaluationController.h"

namespace s21 {
EvaluationController::EvaluationController() { model_ = new EvaluationModel(); }

EvaluationController::~EvaluationController() { delete model_; }

double EvaluationController::evaluate(const std::string& line, double x) const {
  model_->parse_line(line);
  model_->parse_to_polish();
  return model_->apply_polish(x);
}
}  // namespace s21
