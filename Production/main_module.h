#pragma once

#include <gtkmm.h>

class MainModule
{
public:
	MainModule();

	Gtk::ApplicationWindow & get_window();

protected:
	void get_gui_from_glade();
	
	Gtk::Button m_button;
	Gtk::ApplicationWindow *app_window;
};
