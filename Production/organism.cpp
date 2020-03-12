#include "organism.h"

using tuple_int = std::tuple<int,int>;
using vector_t = std::vector<tuple_int >;
using vector_2D_shared_ptr_organism = std::vector<std::vector<std::shared_ptr<Organism> > >;
using std::get;

Organism::Organism()
: organism_type(OrganismType::none), food_level(0), age(0), food_limit(1), age_limit(1), duplicate_cost(1) {}

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

void Organism::take_action(vector_2D_shared_ptr_organism &ecosystem, tuple_int position) {}

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

vector_t Organism::search_for_neighbourhood(tuple_int position, tuple_int ecosystem_size)
{
	vector_t vec;
	
	if(get<0>(position) != 0)
	{
		vec.push_back(tuple_int(get<0>(position) -1 , get<1>(position)));
		
		if(get<1>(position) != get<1>(ecosystem_size) -1)
		{
			vec.push_back(tuple_int(get<0>(position) - 1 , get<1>(position)+1));
		}
		
		if(get<1>(position) != 0)
		{
			vec.push_back(tuple_int(get<0>(position)-1, get<1>(position)-1));
		}
	}
	
	if(get<0>(position) != get<0>(ecosystem_size) -1)
	{
		vec.push_back(tuple_int(get<0>(position) + 1 , get<1>(position)));
		
		if(get<1>(position) != get<1>(ecosystem_size) -1)
		{
			vec.push_back(tuple_int(get<0>(position) + 1 , get<1>(position)+1));
		}
		
		if(get<1>(position) != 0)
		{
			vec.push_back(tuple_int(get<0>(position)+1, get<1>(position)-1));
		}
	}
	
	if(get<1>(position) != get<1>(ecosystem_size) -1)
	{
		vec.push_back(tuple_int(get<0>(position), get<1>(position)+1));
	}
	
	if(get<1>(position) != 0)
	{
		vec.push_back(tuple_int(get<0>(position), get<1>(position)-1));
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

void Organism::filter_neighbourhood_alive(vector_t& neighbourhood, const vector_2D_shared_ptr_organism& ecosystem, bool wanted_alive)
{
	neighbourhood.erase(std::remove_if(neighbourhood.begin(), neighbourhood.end(),
									[ecosystem, wanted_alive](std::tuple<int,int> t)
									{
										return ecosystem[get<0>(t)][get<1>(t)]->is_alive() != wanted_alive;
									}),
									neighbourhood.end());
}

void Organism::filter_neighbourhood_type(vector_t& neighbourhood, const vector_2D_shared_ptr_organism& ecosystem, OrganismType wanted_type)
{
	neighbourhood.erase(std::remove_if(neighbourhood.begin(), neighbourhood.end(),
									[ecosystem, wanted_type](std::tuple<int,int> t)
									{
										return ecosystem[get<0>(t)][get<1>(t)]->get_type() != wanted_type;
									}),
									neighbourhood.end());
}

bool Organism::neighbourdhood_has_type(const vector_t& neighbourhood, const vector_2D_shared_ptr_organism& ecosystem, OrganismType wanted_type)
{
	for(unsigned int i=0;i<neighbourhood.size();i++)
	{
		if(ecosystem[get<0>(neighbourhood[i])][get<1>(neighbourhood[i])]->get_type() == wanted_type)
		{
			return true;
		}
	}
	return false;
}

bool Organism::is_whole_neighbourd_alive(const vector_t& neighbourhood, const vector_2D_shared_ptr_organism& ecosystem)
{
	for(unsigned int i=0;i<neighbourhood.size();i++)
	{
		if(ecosystem[get<0>(neighbourhood[i])][get<1>(neighbourhood[i])]->is_alive() == false)
		{
			return false;
		}
	}
	return true;
}

void Organism::try_to_eat_other_organism(const vector_t& neighbourhood, vector_2D_shared_ptr_organism& ecosystem)
{
	if(neighbourhood.size() > 0)
	{
		int n = 0;
		if(neighbourhood.size() > 1)
		{
			bound_random_generator(neighbourhood.size()-1);
			n = generator(rng);
		}
		
		ecosystem[get<0>(neighbourhood[n])][get<1>(neighbourhood[n])] = std::make_shared<Organism>();
		food_level++;
	}
}

void Organism::try_to_duplicate(vector_t& neighbourhood, vector_2D_shared_ptr_organism& ecosystem, std::shared_ptr<Organism> new_child)
{
	filter_neighbourhood_type(neighbourhood, ecosystem, OrganismType::none);
			
	if(neighbourhood.size() > 0)
	{
		int n = 0;
		if(neighbourhood.size() > 1)
		{
			bound_random_generator(neighbourhood.size()-1);
			n = generator(rng);
		}
		
		ecosystem[get<0>(neighbourhood[n])][get<1>(neighbourhood[n])] = new_child;
		food_level -= duplicate_cost;
	}
}

void Organism::try_to_move(vector_t& neighbourhood, vector_2D_shared_ptr_organism& ecosystem, tuple_int old_position, std::shared_ptr<Organism> guest)
{
	filter_neighbourhood_type(neighbourhood, ecosystem, OrganismType::none);
	
	if(neighbourhood.size() > 0)
	{
		int n = 0;
		if(neighbourhood.size() > 1)
		{
			bound_random_generator(neighbourhood.size()-1);
			n = generator(rng);
		}
		
		ecosystem[get<0>(neighbourhood[n])][get<1>(neighbourhood[n])] = guest;
		*ecosystem[get<0>(neighbourhood[n])][get<1>(neighbourhood[n])] = *ecosystem[get<0>(old_position)][get<1>(old_position)];
		ecosystem[get<0>(old_position)][get<1>(old_position)] = std::make_shared<Organism>();
	}
}
