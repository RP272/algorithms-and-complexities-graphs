#ifndef SUCCESSORNODE_H
#define SUCCESSORNODE_H
#include "IterableNeighborCollection.h"

class SuccessorNode : public IterableNeighborCollection
{
public:
	int successor_id;
	int edge_weight;
	SuccessorNode* next;
	NeighborIterator& createIterator();
};
#endif