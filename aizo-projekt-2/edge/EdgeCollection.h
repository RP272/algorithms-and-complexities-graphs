#ifndef EDGECOLLECTION_H
#define EDGECOLLECTION_H
#include "Edge.h"

class EdgeCollection
{
private:
	Edge* edges;
	int len;
public:
	EdgeCollection(Edge* edges, int len);
	Edge* get_edges();
	int get_len();
};

#endif
