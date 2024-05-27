#include "IncidenceMatrixNeighborIterator.h"

IncidenceMatrixNeighborIterator::IncidenceMatrixNeighborIterator(IncidenceMatrixNeighborCollection* neighbors)
{
	this->neighbors = neighbors;
	idx = 0;
}

Neighbor IncidenceMatrixNeighborIterator::getNext()
{
	return this->neighbors->get_array()[(this->idx)++];
}

bool IncidenceMatrixNeighborIterator::hasMore()
{
	if (this->idx < this->neighbors->get_len()) return true;
	return false;
}