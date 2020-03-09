#include "alga.h"

Alga::Alga()
: Organism(OrganismType::alga, 3, 0, 6, 0)
{
}

Alga::~Alga()
{
}

void Alga::take_action(std::vector<std::vector<std::shared_ptr<Organism> > > ecosystem, tuple_int position)
{
}
