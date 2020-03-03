#pragma once

#include <gtkmm.h>
#include <sstream>
#include <regex>

class MainModule
{
public:
	MainModule();

	Gtk::ApplicationWindow & get_window();

protected:
	void get_gui_from_glade();
	
	void connect_signals();
	
	void make_grid();
	
	bool is_number(std::string s);
	
	int string_to_int(std::string s);
	
	Gtk::Button *setup_button, *sp_button, *hash_button, *restart_button;
	Gtk::Label *ecosystem_label;
	Gtk::MessageDialog * error_dialog, *setup_dialog;
	Gtk::Entry * width_entry, *height_entry;
	Gtk::RadioButton * v_quick_radio, *quick_radio, *normal_radio, *slow_radio;
	Gtk::ApplicationWindow *app_window;
};
