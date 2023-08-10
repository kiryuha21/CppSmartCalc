#include <gtkmm.h>

#include "view/MainWindow.h"

int main(int argc, char** argv) {
  auto app = Gtk::Application::create(argc, argv);
  auto builder = Gtk::Builder::create_from_file("ui/interface.ui");
  auto css_provider_ = Gtk::CssProvider::create();
  css_provider_->load_from_path("ui/styles.css");
  Gtk::StyleContext::add_provider_for_screen(
      Gdk::Screen::get_default(), css_provider_,
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

  s21::MainWindow* mv;
  builder->get_widget_derived("main_window", mv);

  auto res = app->run(*mv);
  delete mv;
  return res;
}