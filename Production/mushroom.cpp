#include "mushroom.h"

Mushroom::Mushroom()
:  Organism(OrganismType::mushroom,4, 0, 15, 0)
{
}

Mushroom::~Mushroom()
{
}

void Mushroom::take_action(std::vector<std::vector<std::shared_ptr<Organism> > > ecosystem, tuple_int position)
{
}
