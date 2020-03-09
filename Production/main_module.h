#pragma once

#include <gtkmm.h>

#include <sstream>
#include <regex>

#include <bacteria.h>
#include <mushroom.h>
#include <alga.h>

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
	std::string int_to_string(int i);
	
	void work();
	
	bool v_quick_tick();
	bool quick_tick();
	bool normal_tick();
	bool slow_tick();
	
	void start_pause();
	void hash();
	void restart();
	
	void copy_ecosystems();
	
	void update_screen();
	
	Gtk::Button *setup_button, *sp_button, *hash_button, *restart_button;
	Gtk::Label *ecosystem_label, *dead_label, *mushroom_label, *bacteria_label, *alga_label, *step_label, *free_label;
	Gtk::MessageDialog * error_dialog, *setup_dialog;
	Gtk::Entry * width_entry, *height_entry;
	Gtk::RadioButton * v_quick_radio, *quick_radio, *normal_radio, *slow_radio;
	Gtk::ApplicationWindow *app_window;

	const int default_width = 10, default_height = 10;
	int width, height, step_counter;
	bool is_running;
	
	std::vector<std::vector<std::shared_ptr<Organism> > > ecosystem, backup;
	
	std::random_device dev;
    std::mt19937 rng;
    std::uniform_int_distribution<std::mt19937::result_type> generator;
};
