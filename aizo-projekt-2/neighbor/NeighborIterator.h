#ifndef NEIGHBORITERATOR_H
#define NEIGHBORITERATOR_H
#include "Neighbor.h"

class NeighborIterator
{
public:
	virtual Neighbor getNext() = 0;
	virtual bool hasMore() = 0;
};

#endif