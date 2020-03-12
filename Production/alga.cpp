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

			try_to_duplicate(neigh, ecosystem, std::make_shared<Alga>());
		}
	}
}
