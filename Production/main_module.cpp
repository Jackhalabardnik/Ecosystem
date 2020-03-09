#include "main_module.h"
#include <iostream>


Gtk::ApplicationWindow & MainModule::get_window()
{
	return *app_window;
}

MainModule::MainModule()  
: width(10), height(10), is_running(false)
{
	rng = std::mt19937(dev());
	generator = std::uniform_int_distribution<std::mt19937::result_type>(0,3);
	
	get_gui_from_glade();
	connect_signals();
	
	hash_button->clicked();
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
	
	sp_button->signal_clicked().connect(sigc::mem_fun(*this, &MainModule::start_pause));
	
	hash_button->signal_clicked().connect(sigc::mem_fun(*this, &MainModule::hash));
	
	restart_button->signal_clicked().connect(sigc::mem_fun(*this, &MainModule::restart));
	
	Glib::signal_timeout().connect(sigc::mem_fun(*this, &MainModule::v_quick_tick), 100);
	Glib::signal_timeout().connect(sigc::mem_fun(*this, &MainModule::quick_tick), 250);
	Glib::signal_timeout().connect(sigc::mem_fun(*this, &MainModule::normal_tick), 500);
	Glib::signal_timeout().connect(sigc::mem_fun(*this, &MainModule::slow_tick), 1000);
}

void MainModule::make_grid()
{
	auto result = setup_dialog->run();
	setup_dialog->hide();

	if(result == Gtk::RESPONSE_OK)
	{
		if(is_number(width_entry->get_text()) && is_number(height_entry->get_text()))
		{
			width = string_to_int(width_entry->get_text());
			height = string_to_int(height_entry->get_text());
			
			hash_button->clicked();
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
	const std::regex regex("[1-4][0-9]?|50|[1-9]", std::regex_constants::ECMAScript);
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

void MainModule::draw()
{
	std::string represenation;	
	
	for(int i= 0; i< height; i++)
	{
		for (int j = 0; j< width; j++)
		{
			if(ecosystem[i][j]->is_alive() == false)
			{
				represenation += "+";
				continue;
			}
			
			switch (ecosystem[i][j]->get_type()) {
				case 0:
					represenation += "-";
					break;
				case 1:
					represenation += "@";
					break;
				case 2:
					represenation += "#";
					break;
				case 3:
					represenation += "*";
					break;
			}
		}
		represenation += "\n";
	}
	
	ecosystem_label->set_text(represenation);

}

bool MainModule::v_quick_tick()
{
	if(v_quick_radio->get_active() && is_running)
	{
		
	}
	return true;
}



bool MainModule::quick_tick()
{
	if(quick_radio->get_active() && is_running)
	{
		
	}
	return true;
}



bool MainModule::normal_tick()
{
	if(normal_radio->get_active() && is_running)
	{
		
	}
	return true;
}

bool MainModule::slow_tick()
{
	if(slow_radio->get_active() && is_running)
	{
		
	}
	return true;
}

void MainModule::start_pause()
{
	if(is_running)
	{
		is_running = false;
		sp_button->set_label("Start");
	}
	else
	{
		is_running = true;
		sp_button->set_label("Pause");
	}
}

void MainModule::hash()
{
	backup.erase(backup.begin(),backup.end());
	for(int i=0; i<width; i++)
	{
		std::vector<std::shared_ptr<Organism> > vec;
		for(int j=0; j<height; j++)
		{
			std::shared_ptr<Organism> ptr;
			switch (generator(rng)) {
				case 1: 
					ptr = std::make_shared<Bacteria>();
					break;
				case 2: 
					ptr = std::make_shared<Mushroom>();
					break;
				case 3: 
					ptr = std::make_shared<Alga>();
					break;
				default: 
					ptr = std::make_shared<Organism>();
					break;
			}
			vec.push_back(ptr);
		}
		backup.push_back(vec);
	}
	
	restart_button->clicked();
}

void MainModule::restart()
{
	ecosystem = backup;
	draw();
	is_running = false;
	sp_button->set_label("Start");
}
