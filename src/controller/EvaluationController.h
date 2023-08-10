#ifndef CPP3_SMARTCALC_V2_0_1_EVALUATIONCONTROLLER_H
#define CPP3_SMARTCALC_V2_0_1_EVALUATIONCONTROLLER_H

#include "../model/EvaluationModel.h"

namespace s21 {
class EvaluationController {
 public:
  EvaluationController();
  ~EvaluationController();

  double evaluate(const std::string& line, const std::string& str_x) const;
  double evaluate_cached(const std::string& str_x) const;

 private:
  EvaluationModel* model_ = nullptr;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_EVALUATIONCONTROLLER_H
