#ifndef SUCCESSORNODE_HPP
#define SUCCESSORNODE_HPP

struct SuccessorNode
{
	int successor_id;
	int edge_weight;
	SuccessorNode* next;
};

#endif