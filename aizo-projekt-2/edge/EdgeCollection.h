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
	void quicksort(int l, int p);
	int partition(int left, int right);
};

#endif
