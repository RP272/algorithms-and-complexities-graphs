#ifndef ITERABLENEIGHBORCOLLECTION_H
#define ITERABLENEIGHBORCOLLECTION_H
#include "NeighborIterator.h"

class IterableNeighborCollection
{
public:
	virtual NeighborIterator& createIterator() = 0;
};

#endif