#ifndef INCIDENCEMATRIXNEIGHBORITERATOR_H
#define INCIDENCEMATRIXNEIGHBORITERATOR_H
#include "../neighbor/NeighborIterator.h"
#include "IncidenceMatrixNeighborCollection.h"

class IncidenceMatrixNeighborIterator : public NeighborIterator
{
private:
	int idx;
	IncidenceMatrixNeighborCollection* neighbors;
public:
	IncidenceMatrixNeighborIterator(IncidenceMatrixNeighborCollection* neighbors);
	Neighbor getNext() override;
	bool hasMore() override;
};

#endif