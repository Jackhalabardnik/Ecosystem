#pragma once

#include "organism.h"

class Bacteria : public Organism
{
public:
	Bacteria();
	virtual ~Bacteria();
	virtual void take_action(std::vector<std::vector<std::shared_ptr<Organism> > > &ecosystem, tuple_int position) override;
};

