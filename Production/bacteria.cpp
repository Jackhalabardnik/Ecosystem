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
				try_to_eat_other_organism(neigh, ecosystem);
			}
			else if(neighbourdhood_has_type(neigh, ecosystem, OrganismType::bacteria))
			{
				filter_neighbourhood_type(neigh,ecosystem,OrganismType::bacteria);
				try_to_eat_other_organism(neigh, ecosystem);
			}
			else
			{
				try_to_move(neigh, ecosystem, position, std::make_shared<Bacteria>());
			}
		}
		else
		{
			try_to_duplicate(neigh, ecosystem, std::make_shared<Bacteria>());
		}
	}
}
