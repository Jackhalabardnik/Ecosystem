#include "mushroom.h"
#include <iostream>

Mushroom::Mushroom()
:  Organism(OrganismType::mushroom,4, 30, 2)
{
}

Mushroom::~Mushroom()
{
}

void Mushroom::take_action(std::vector<std::vector<std::shared_ptr<Organism> > > &ecosystem, tuple_int position)
{
	touched = true;
	
	if(is_alive())
	{
		age++;

		auto neigh = search_for_neighbourhood(position, std::tuple<int,int>(ecosystem.size(), ecosystem[0].size())); 
			
		if(is_hungry())
		{
			if(is_whole_neighbourd_alive(neigh,ecosystem))
			{
				try_to_move(neigh, ecosystem, position, std::make_shared<Mushroom>());
			}
			else
			{
				filter_neighbourhood_alive(neigh, ecosystem, false);
				
				try_to_eat_other_organism(neigh,ecosystem);
			}
		}
		else
		{
			try_to_duplicate(neigh, ecosystem, std::make_shared<Mushroom>());
		}
	}
}
