#pragma once

#include <vector>
#include <tuple>
#include <memory>

using tuple_int = std::tuple<int,int>;

enum OrganismType
{
	None, Bacteria, Mushroom, Alga
};

class Organism
{
public:
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

