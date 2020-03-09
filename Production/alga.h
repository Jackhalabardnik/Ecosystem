#pragma once

#include "organism.h"

class Alga : public Organism
{
public:
	Alga();
	virtual ~Alga();
	virtual void take_action(std::vector<std::vector<std::shared_ptr<Organism> > > ecosystem, tuple_int position) override;
};

