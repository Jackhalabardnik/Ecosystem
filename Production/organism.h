#pragma once

#include <vector>
#include <tuple>
#include <memory>

using tuple_int = std::tuple<int,int>;

enum OrganismType
{
	none, bacteria, mushroom, alga
};

class Organism
{
public:
	Organism(OrganismType organism_type, const int food_limit, int food_level, const int age_limit, int age);
	Organism();
	virtual ~Organism();

	bool is_alive();
	bool is_hungry();
	
	OrganismType get_type();
	
	virtual void take_action(std::vector<std::vector<std::shared_ptr<Organism> > > ecosystem, tuple_int position);

protected:	
	std::vector<tuple_int > search_for_neighbourhood(tuple_int position, tuple_int ecosystem_size);
	
	int food_level, age;
	const int food_limit, age_limit;
	OrganismType organism_type;
};

