#include "AdjacencyListNeighborIterator.h"

AdjacencyListNeighborIterator::AdjacencyListNeighborIterator(SuccessorNode* ptr)
{
	this->neighbors = ptr;
}

Neighbor AdjacencyListNeighborIterator::getNext()
{
	Neighbor n = *(this->neighbors);
	this->neighbors = this->neighbors->next;
	return n;
}

bool AdjacencyListNeighborIterator::hasMore()
{
	if (this->neighbors->id != -1) return true;
	return false;
}