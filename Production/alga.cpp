#include "alga.h"

Alga::Alga()
: Organism(OrganismType::alga, 3, 10, 1)
{
}

Alga::~Alga()
{
}

void Alga::take_action(std::vector<std::vector<std::shared_ptr<Organism> > > &ecosystem, tuple_int position)
{
	touched = true;
	
	if(is_alive())
	{
		age++;
		
		if(is_hungry())
		{
			food_level++;
		}
		else
		{
			auto neigh = search_for_neighbourhood(position, std::tuple<int,int>(ecosystem.size(), ecosystem[0].size())); 
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
				
				ecosystem[std::get<0>(neigh[n])][std::get<1>(neigh[n])] = std::make_shared<Alga>();
				food_level -= duplicate_cost;
			}
		}
	}
}
