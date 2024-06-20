#include "SuccessorNode.h"
#include "AdjacencyListNeighborIterator.h"

SuccessorNode::SuccessorNode(int id, int edge_weight, SuccessorNode* next) : Neighbor(id, edge_weight)
{
	this->next = next;
}

NeighborIterator& SuccessorNode::createIterator()
{
	AdjacencyListNeighborIterator* iterator = new AdjacencyListNeighborIterator(this);
	return *iterator;
}

SuccessorNode* SuccessorNode::get_next()
{
	return this->next;
}

void SuccessorNode::destroy() {};