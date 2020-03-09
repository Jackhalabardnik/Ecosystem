#include "bacteria.h"

Bacteria::Bacteria()
: Organism(OrganismType::bacteria, 5, 0, 10, 0)
{
	
}

Bacteria::~Bacteria()
{
}

void Bacteria::take_action(std::vector<std::vector<std::shared_ptr<Organism> > > ecosystem, tuple_int position)
{
}
