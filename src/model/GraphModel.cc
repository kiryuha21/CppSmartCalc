#include "GraphModel.h"

namespace s21 {
GraphModel::GraphModel(EvaluationController *eval_controller,
                       const std::string &function, const int width,
                       const int height)
    : eval_controller_(eval_controller),
      function_(function),
      width_(width),
      height_(height) {}

void GraphModel::generate_datafile() const {
  std::fstream fs(kPointsFileName, std::ios::out);
  if (!fs.is_open()) {
    throw std::logic_error("File opening error!");
  }

  double diff = max_x_ - min_x_;
  double delta = diff / kPointsAmount;
  for (int i = 0; i < kPointsAmount; ++i) {
    double x = min_x_ + delta * i;
    double y = eval_controller_->evaluate_cached(std::to_string(x));
    if (!std::isnan(y) && !std::isinf(y)) {
      fs << x << " " << y << "\n";
    }
  }

  fs.close();
}

void GraphModel::parse_limits(const std::string &min_x,
                              const std::string &max_x,
                              const std::string &min_y,
                              const std::string &max_y) {
  if (min_x.empty() || max_x.empty() || min_y.empty() || max_y.empty()) {
    throw std::logic_error("All fields should be filled!");
  }

  min_x_ = to_double(min_x);
  max_x_ = to_double(max_x);
  min_y_ = to_double(min_y);
  max_y_ = to_double(max_y);

  if (max_x_ - min_x_ <= 0 || max_y_ - min_y_ <= 0) {
    throw std::logic_error("Invalid range!");
  }
}

void GraphModel::generate_plot_image() const {
  generate_datafile();

  Gnuplot gp;
  gp << "set terminal pngcairo size " << width_ << "," << height_ << "\n"
     << "set output '" << kGraphFileName << "'\n"
     << "set xlabel \"X-axis\"\n"
     << "set ylabel \"Y-axis\"\n"
     << "set xrange [" << min_x_ << ":" << max_x_ << "]\n"
     << "set yrange [" << min_y_ << ":" << max_y_ << "]\n"
     << "plot \"" << kPointsFileName << "\" title \"" << function_ << " "
     << "with scale " << std::setprecision(7) << std::fixed
     << (max_y_ - min_y_) / (max_x_ - min_x_) << "\" ps 0.7\n";
}

}  // namespace s21