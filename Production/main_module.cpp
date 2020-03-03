#include "main_module.h"
#include <iostream>

MainModule::MainModule()  
{
	get_gui_from_glade();
	connect_signals();
}

void MainModule::get_gui_from_glade()
{
	auto builder = Gtk::Builder::create_from_file("Glade_project.glade");
	builder->get_widget("app_window", app_window);
	builder->get_widget("setup", setup_button);
	builder->get_widget("ecosystem_label", ecosystem_label);
	builder->get_widget("start_stop", sp_button);
	builder->get_widget("hash", hash_button);
	builder->get_widget("reset", restart_button);
	builder->get_widget("very_quick", v_quick_radio);
	builder->get_widget("quick", quick_radio);
	builder->get_widget("normal", normal_radio);
	builder->get_widget("slow", slow_radio);
	builder->get_widget("error_dialog", error_dialog);
	builder->get_widget("get_grid_size_dialog", setup_dialog);
	builder->get_widget("width_entry", width_entry);
	builder->get_widget("height_entry", height_entry);
}

void MainModule::connect_signals()
{
	setup_button->signal_clicked().connect(sigc::mem_fun(*this, &MainModule::make_grid));
}

void MainModule::make_grid()
{
	auto result = setup_dialog->run();
	setup_dialog->hide();

	if(result == Gtk::RESPONSE_OK)
	{
		if(is_number(width_entry->get_text()) && is_number(height_entry->get_text()))
		{
			int width = string_to_int(width_entry->get_text());
			int height = string_to_int(height_entry->get_text());
			
			std::string represenation;
			
			for(int i= 0; i< height; i++)
			{
				for (int j = 0; j< width; j++)
				{
					represenation += "@";
				}
				represenation += "\n";
			}
			
			ecosystem_label->set_text(represenation);
		}
		else
		{
			error_dialog->run();
			error_dialog->hide();
		}
	}
	
	
}

bool MainModule::is_number(std::string s)
{
	const std::regex regex("[1-4][0-9]?|50?", std::regex_constants::ECMAScript);
	std::smatch base_match;
	return std::regex_match(s, base_match, regex);
}

int MainModule::string_to_int(std::string s)
{
	std::stringstream ss;
	ss << s;
	int i;
	ss >> i;
	return i;
}

Gtk::ApplicationWindow & MainModule::get_window()
{
	return *app_window;
}

