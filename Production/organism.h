#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include <tuple>
#include <memory>

class Organism;

using tuple_int = std::tuple<int,int>;
using vector_t = std::vector<tuple_int >;
using vector_2D_shared_ptr_organism = std::vector<std::vector<std::shared_ptr<Organism> > >;

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
	
	void untouch();
	bool was_touched();
	
	OrganismType get_type();
	
	virtual void take_action(vector_2D_shared_ptr_organism &ecosystem, tuple_int position);

protected:	
	std::vector<tuple_int > search_for_neighbourhood(tuple_int position, tuple_int ecosystem_size);
	
	void filter_neighbourhood_alive(vector_t &neighbourhood, const vector_2D_shared_ptr_organism &ecosystem, bool wanted_alive);
	void filter_neighbourhood_type(vector_t &neighbourhood, const vector_2D_shared_ptr_organism &ecosystem, OrganismType wanted_type);
	
	bool neighbourdhood_has_type(const vector_t &neighbourhood, const vector_2D_shared_ptr_organism &ecosystem, OrganismType wanted_type);
	bool is_whole_neighbourd_alive(const vector_t &neighbourhood, const vector_2D_shared_ptr_organism &ecosystem);
	
	void try_to_eat_other_organism(const vector_t &neighbourhood, vector_2D_shared_ptr_organism &ecosystem);
	
	void try_to_duplicate(vector_t &neighbourhood, vector_2D_shared_ptr_organism &ecosystem, std::shared_ptr<Organism> new_child);
	
	void try_to_move(vector_t &neighbourhood, vector_2D_shared_ptr_organism &ecosystem, tuple_int old_position, std::shared_ptr<Organism> guest);
	
	void setup_random_generator();
	void bound_random_generator(int n);
	
	OrganismType organism_type;
	int food_level, age, food_limit, age_limit, duplicate_cost;
	bool touched;
	
	std::random_device dev;
    std::mt19937 rng;
    std::uniform_int_distribution<std::mt19937::result_type> generator;
};

