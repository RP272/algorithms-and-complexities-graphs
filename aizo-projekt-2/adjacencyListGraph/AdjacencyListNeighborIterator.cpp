#include "AdjacencyListNeighborIterator.h"

AdjacencyListNeighborIterator::AdjacencyListNeighborIterator(SuccessorNode* ptr)
{
	this->neighbors = ptr;
}

Neighbor AdjacencyListNeighborIterator::getNext()
{
	Neighbor n = *(this->neighbors);
	this->neighbors = this->neighbors->get_next();
	return n;
}

bool AdjacencyListNeighborIterator::hasMore()
{
	if (this->neighbors->get_id() != -1) return true;
	return false;
}