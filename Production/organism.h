#pragma once

#include <vector>
#include <algorithm>
#include <random>
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
	Organism(OrganismType organism_type, const int food_limit, const int age_limit, const int duplicate_cost_);
	Organism();
	virtual ~Organism();
	
	Organism& operator=(const Organism& o);

	bool is_alive();
	bool is_hungry();
	
	OrganismType get_type();
	
	virtual void take_action(std::vector<std::vector<std::shared_ptr<Organism> > > &ecosystem, tuple_int position);

protected:	
	std::vector<tuple_int > search_for_neighbourhood(tuple_int position, tuple_int ecosystem_size);
	
	void setup_random_generator();
	void bound_random_generator(int n);
	
	OrganismType organism_type;
	int food_level, age, food_limit, age_limit, duplicate_cost;
	
	std::random_device dev;
    std::mt19937 rng;
    std::uniform_int_distribution<std::mt19937::result_type> generator;
};

