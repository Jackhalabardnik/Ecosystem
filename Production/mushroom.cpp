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
	if(is_alive())
	{
		age++;

		auto neigh = search_for_neighbourhood(position, std::tuple<int,int>(ecosystem.size(), ecosystem[0].size())); 
			
		if(is_hungry())
		{
			bool has_eat = false;
			for(int i=0;i<neigh.size();i++)
			{
				if(ecosystem[std::get<0>(neigh[i])][std::get<1>(neigh[i])]->is_alive() == false)
				{
					has_eat = true;
				}
			}
			
			if(has_eat)
			{
				neigh.erase(std::remove_if(neigh.begin(), neigh.end(),
									[ecosystem](std::tuple<int,int> t)
									{
										return ecosystem[std::get<0>(t)][std::get<1>(t)]->is_alive() == true;
									}),
									neigh.end());
				if(neigh.size() > 0)
				{
					int n = 0;
					if(neigh.size() > 1)
					{
						bound_random_generator(neigh.size());
						n = generator(rng);
					}
					
					ecosystem[std::get<0>(neigh[n])][std::get<1>(neigh[n])] = std::make_shared<Organism>();
					food_level++;
				}
			}
			else
			{
				neigh.erase(std::remove_if(neigh.begin(), neigh.end(),
									[ecosystem](std::tuple<int,int> t)
									{
										return ecosystem[std::get<0>(t)][std::get<1>(t)]->get_type() != OrganismType::none;
									}),
									neigh.end());
				if(neigh.size() > 0)
				{
					int n = 0;
					if(neigh.size() > 1)
					{
						bound_random_generator(neigh.size());
						n = generator(rng);
					}
					
					
					*ecosystem[std::get<0>(neigh[n])][std::get<1>(neigh[n])] = *ecosystem[std::get<0>(position)][std::get<1>(position)];
					ecosystem[std::get<0>(position)][std::get<1>(position)] = std::make_shared<Organism>();
				}
			}
		}
		else
		{
			neigh.erase(std::remove_if(neigh.begin(), neigh.end(),
								[ecosystem](std::tuple<int,int> t)
								{
									return ecosystem[std::get<0>(t)][std::get<1>(t)]->get_type() != OrganismType::none;
								}),
								neigh.end());
			if(neigh.size() > 0)
			{
				int n = 0;
				if(neigh.size() > 1)
				{
					bound_random_generator(neigh.size());
					n = generator(rng);
				}
				
				ecosystem[std::get<0>(neigh[n])][std::get<1>(neigh[n])] = std::make_shared<Mushroom>();
				food_level -= duplicate_cost;
			}
		}
	}
}
