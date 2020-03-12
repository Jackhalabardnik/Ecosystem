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
				filter_neighbourhood_type(neigh, ecosystem, OrganismType::none);
				
				if(neigh.size() > 0)
				{
					int n = 0;
					if(neigh.size() > 1)
					{
						bound_random_generator(neigh.size()-1);
						n = generator(rng);
					}
					
					ecosystem[std::get<0>(neigh[n])][std::get<1>(neigh[n])] = std::make_shared<Mushroom>();
					*ecosystem[std::get<0>(neigh[n])][std::get<1>(neigh[n])] = *ecosystem[std::get<0>(position)][std::get<1>(position)];
					ecosystem[std::get<0>(position)][std::get<1>(position)] = std::make_shared<Organism>();
				}
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
