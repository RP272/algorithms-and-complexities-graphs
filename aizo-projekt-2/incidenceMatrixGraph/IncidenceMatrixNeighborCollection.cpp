#include "IncidenceMatrixNeighborCollection.h"
#include "IncidenceMatrixNeighborIterator.h"

IncidenceMatrixNeighborCollection::IncidenceMatrixNeighborCollection() 
{
	this->array = nullptr;
	this->len = 0;
};

NeighborIterator& IncidenceMatrixNeighborCollection::createIterator()
{
	IncidenceMatrixNeighborIterator* iterator = new IncidenceMatrixNeighborIterator(this);
	return *iterator;
}

void IncidenceMatrixNeighborCollection::add_neighbor(int vertex_id, int edge_weight)
{
	Neighbor* copy = new Neighbor[this->len];
	for (int a = 0; a < this->len; a++) {
		copy[a] = this->array[a];
	}
	delete[] this->array;
	this->len++;
	this->array = new Neighbor[this->len];
	for (int a = 0; a < this->len - 1; a++) {
		this->array[a] = copy[a];
	}
	(this->array[this->len - 1]).set_id(vertex_id);
	(this->array[this->len - 1]).set_edge_weight(edge_weight);
	delete[] copy;
}

Neighbor* IncidenceMatrixNeighborCollection::get_array()
{
	return this->array;
}

int IncidenceMatrixNeighborCollection::get_len()
{
	return this->len;
}