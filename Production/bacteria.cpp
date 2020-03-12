#include "bacteria.h"

Bacteria::Bacteria()
: Organism(OrganismType::bacteria, 4, 20, 2)
{
	
}

Bacteria::~Bacteria()
{
}

void Bacteria::take_action(std::vector<std::vector<std::shared_ptr<Organism> > > &ecosystem, tuple_int position)
{
	touched = true;
	if(is_alive())
	{
		age++;
		
		auto neigh = search_for_neighbourhood(position, std::tuple<int,int>(ecosystem.size(), ecosystem[0].size())); 
		
		if(is_hungry())
		{
			if(neighbourdhood_has_type(neigh, ecosystem, OrganismType::alga))
			{
				filter_neighbourhood_type(neigh,ecosystem,OrganismType::alga);
			}
			else
			{
				filter_neighbourhood_type(neigh,ecosystem,OrganismType::bacteria);
			}
			
			try_to_eat_other_organism(neigh, ecosystem);
		}
		else
		{
			filter_neighbourhood_type(neigh,ecosystem,OrganismType::none);
			
			if(neigh.size() > 0)
			{
				int n = 0;
				if(neigh.size() > 1)
				{
					bound_random_generator(neigh.size());
					n = generator(rng);
				}
				
				ecosystem[std::get<0>(neigh[n])][std::get<1>(neigh[n])] = std::make_shared<Bacteria>();
				food_level -= duplicate_cost;
			}
		}
	}
}
