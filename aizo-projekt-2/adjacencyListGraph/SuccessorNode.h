#ifndef SUCCESSORNODE_H
#define SUCCESSORNODE_H
#include "../neighbor/IterableNeighborCollection.h"
#include "../neighbor/Neighbor.h"

class SuccessorNode : public Neighbor, public IterableNeighborCollection
{
private:
	SuccessorNode* next;
public:
	SuccessorNode(int id, int edge_weight, SuccessorNode* next);
	NeighborIterator& createIterator() override;
	SuccessorNode* get_next();
};
#endif