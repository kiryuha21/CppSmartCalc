#ifndef CPP3_SMARTCALC_V2_0_1_EVALUATIONCONTROLLER_H
#define CPP3_SMARTCALC_V2_0_1_EVALUATIONCONTROLLER_H

#include "../model/EvaluationModel.h"

namespace s21 {
class EvaluationController {
 public:
  EvaluationController();
  ~EvaluationController();

  [[nodiscard]] double evaluate(const std::string& line, double x = 0) const;

 private:
  EvaluationModel* model_ = nullptr;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_EVALUATIONCONTROLLER_H
