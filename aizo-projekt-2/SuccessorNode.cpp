#include "SuccessorNode.h"
#include "AdjacencyListNeighborIterator.h"
NeighborIterator& SuccessorNode::createIterator()
{
	AdjacencyListNeighborIterator* iterator = new AdjacencyListNeighborIterator(this);
	return *iterator;
}