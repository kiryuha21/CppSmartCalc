#include "DepositView.h"

namespace s21 {
DepositView::DepositView(BaseObjectType* obj,
                         Glib::RefPtr<Gtk::Builder> const& builder)
    : Gtk::Window(obj), builder_{builder} {}
}  // namespace s21
