#ifndef SUCCESSORNODE_H
#define SUCCESSORNODE_H
#include "IterableNeighborCollection.h"
#include "Neighbor.h"

class SuccessorNode : public Neighbor, public IterableNeighborCollection
{
public:
	SuccessorNode* next;
	NeighborIterator& createIterator();
};
#endif