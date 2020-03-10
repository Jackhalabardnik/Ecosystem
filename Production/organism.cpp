#include "organism.h"

using tuple_int = std::tuple<int,int>;

Organism::Organism()
: organism_type(OrganismType::none), age_limit(1), food_limit(1), age(0), food_level(0), duplicate_cost(1) {}

Organism::Organism(OrganismType organism_type, const int food_limit_, const int age_limit_, const int duplicate_cost_)
: organism_type(organism_type), food_level(0), age(0), duplicate_cost(duplicate_cost_)
{
	setup_random_generator();
	food_limit = food_limit_ - 2 + generator(rng);
	age_limit = age_limit_ - 2 + generator(rng);
}

Organism::~Organism() {}


Organism& Organism::operator=(const Organism& o)
{
	organism_type = o.organism_type;
	food_level = o.food_level;
	food_limit = o.food_limit;
	age_limit = o.age_limit;
	age = o.age;
	duplicate_cost = o.duplicate_cost;
	touched = o.touched;
	
	return *this;
}

void Organism::setup_random_generator()
{
	rng = std::mt19937(dev());
	bound_random_generator(4);
}

void Organism::bound_random_generator(int n)
{
	generator = std::uniform_int_distribution<std::mt19937::result_type>(0,n);
}

void Organism::take_action(std::vector<std::vector<std::shared_ptr<Organism> > > &ecosystem, tuple_int position) {}

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

void Organism::untouch()
{
	touched = false;
}
bool Organism::was_touched()
{
	return touched;
}
