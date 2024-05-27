#ifndef INCIDENCEMATRIXNEIGHBORCOLLECTION_H
#define INCIDENCEMATRIXNEIGHBORCOLLECTION_H
#include "../neighbor/IterableNeighborCollection.h"
#include "../neighbor/Neighbor.h"

class IncidenceMatrixNeighborCollection : public IterableNeighborCollection
{
private:
	Neighbor* array;
	int len;
public:
	IncidenceMatrixNeighborCollection();
	NeighborIterator& createIterator() override;
	void add_neighbor(int vertex_id, int edge_weight);
	Neighbor* get_array();
	int get_len();
};

#endif