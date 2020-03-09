#include "bacteria.h"

Bacteria::Bacteria()
: organism_type(OrganismType::Bacteria) food_limit(5), food_level(0), age_limit(10), age(0);
{
}

Bacteria::~Bacteria()
{
}

