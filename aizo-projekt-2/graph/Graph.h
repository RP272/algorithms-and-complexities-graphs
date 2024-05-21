#ifndef GRAPH_H
#define GRAPH_H

#include "../neighbor/IterableNeighborCollection.h"
#include <vector>

class Graph
{
protected:
	int vertices_len;
public:
	virtual IterableNeighborCollection& adjacent(int vertex_id) = 0;
	virtual void add_edge(int u, int v, int weight) = 0;
	virtual void show_graph() = 0;
	int get_vertices_len();
};

#endif