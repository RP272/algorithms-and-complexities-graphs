#include "AdjacencyListNeighborIterator.h"

AdjacencyListNeighborIterator::AdjacencyListNeighborIterator(SuccessorNode* ptr)
{
	this->neighbors = ptr;
}

int AdjacencyListNeighborIterator::getNext()
{
	int value = this->neighbors->successor_id;
	this->neighbors = this->neighbors->next;
	return value;
}

bool AdjacencyListNeighborIterator::hasMore()
{
	if (this->neighbors != nullptr) return true;
	return false;
}