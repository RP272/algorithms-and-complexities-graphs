#ifndef ADJACENCYLISTNEIGHBORITERATOR_H
#define ADJACENCYLISTNEIGHBORITERATOR_H
#include "../neighbor/NeighborIterator.h"
#include "SuccessorNode.h"
class AdjacencyListNeighborIterator : public NeighborIterator
{
private:
	SuccessorNode* neighbors;
public:
	AdjacencyListNeighborIterator(SuccessorNode* ptr);
	~AdjacencyListNeighborIterator();
	Neighbor getNext() override;
	bool hasMore() override;
};
#endif