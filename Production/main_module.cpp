#include "main_module.h"
#include <iostream>

MainModule::MainModule() : m_button("Hello World")  
{
	get_gui_from_glade();
}

void MainModule::get_gui_from_glade()
{
	auto builder = Gtk::Builder::create_from_file("Glade_project.glade");
	builder->get_widget("app_window", app_window);
}

Gtk::ApplicationWindow & MainModule::get_window()
{
	return *app_window;
}
