#ifndef ADJACENCYLISTNEIGHBORITERATOR_H
#define ADJACENCYLISTNEIGHBORITERATOR_H
#include "NeighborIterator.h"
#include "SuccessorNode.h"
class AdjacencyListNeighborIterator : public NeighborIterator
{
public:
	AdjacencyListNeighborIterator(SuccessorNode* ptr);
	SuccessorNode* neighbors;
	Neighbor getNext() override;
	bool hasMore() override;

};
#endif