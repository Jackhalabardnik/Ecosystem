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
	if(is_alive())
	{
		age++;
		
		auto neigh = search_for_neighbourhood(position, std::tuple<int,int>(ecosystem.size(), ecosystem[0].size())); 
		
		if(is_hungry())
		{
			bool has_algas = false;
			for(int i=0;i<neigh.size();i++)
			{
				if(ecosystem[std::get<0>(neigh[i])][std::get<1>(neigh[i])]->get_type() == OrganismType::alga)
				{
					has_algas = true;
				}
			}
			
			if(has_algas)
			{
				neigh.erase(std::remove_if(neigh.begin(), neigh.end(),
								[ecosystem](std::tuple<int,int> t)
								{
									return ecosystem[std::get<0>(t)][std::get<1>(t)]->get_type() != OrganismType::alga;
								}),
								neigh.end());
			}
			else
			{
				neigh.erase(std::remove_if(neigh.begin(), neigh.end(),
								[ecosystem](std::tuple<int,int> t)
								{
									return ecosystem[std::get<0>(t)][std::get<1>(t)]->get_type() != OrganismType::bacteria;
								}),
								neigh.end());
			}
			
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
				
				ecosystem[std::get<0>(neigh[n])][std::get<1>(neigh[n])] = std::make_shared<Bacteria>();
				food_level -= duplicate_cost;
			}
		}
	}
}
