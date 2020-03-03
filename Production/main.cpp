#include "main_module.h"

int main ()
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create();

  MainModule main_module;

  return app->run(main_module.get_window());
}