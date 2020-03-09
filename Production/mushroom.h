#pragma once

#include "organism.h"

class Mushroom : public Organism
{
public:
	Mushroom();
	virtual ~Mushroom();
	virtual void take_action(std::vector<std::vector<std::shared_ptr<Organism> > > &ecosystem, tuple_int position) override;
};

