#include "organism.h"

using tuple_int = std::tuple<int,int>;

Organism::Organism()
: organism_type = OrganismType::None
{
}

Organism::~Organism()
{
}

void Organism::take_action(std::vector<std::vector<std::shared_ptr<Organism> > > ecosystem, tuple_int position)
{
	
}

OrganismType Organism::get_type()
{
	return organism_type;
}

bool Organism::is_alive()
{
	return age < age_limit;
}

bool Organism::is_hungry()
{
	return food_level < food_limit;
}

std::vector<tuple_int > Organism::search_for_neighbourhood(tuple_int position, tuple_int ecosystem_size)
{
	std::vector<tuple_int > vec;
	
	if(std::get<0>(position) != 0)
	{
		vec.push_back(tuple_int(std::get<0>(position) -1 , std::get<1>(position)));
		
		if(std::get<1>(position) != std::get<1>(ecosystem_size) -1)
		{
			vec.push_back(tuple_int(std::get<0>(position) - 1 , std::get<1>(position)+1));
		}
		
		if(std::get<1>(position) != 0)
		{
			vec.push_back(tuple_int(std::get<0>(position)-1, std::get<1>(position)-1));
		}
	}
	
	if(std::get<0>(position) != std::get<0>(ecosystem_size) -1)
	{
		vec.push_back(tuple_int(std::get<0>(position) + 1 , std::get<1>(position)));
		
		if(std::get<1>(position) != std::get<1>(ecosystem_size) -1)
		{
			vec.push_back(tuple_int(std::get<0>(position) + 1 , std::get<1>(position)+1));
		}
		
		if(std::get<1>(position) != 0)
		{
			vec.push_back(tuple_int(std::get<0>(position)+1, std::get<1>(position)-1));
		}
	}
	
	if(std::get<1>(position) != std::get<1>(ecosystem_size) -1)
	{
		vec.push_back(tuple_int(std::get<0>(position), std::get<1>(position)+1));
	}
	
	if(std::get<1>(position) != 0)
	{
		vec.push_back(tuple_int(std::get<0>(position), std::get<1>(position)-1));
	}
	
	return vec;
}

