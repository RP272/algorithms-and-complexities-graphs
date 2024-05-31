#ifndef GRAPH_H
#define GRAPH_H
#include "../neighbor/IterableNeighborCollection.h"
#include "../edge/EdgeCollection.h"

class Graph
{
protected:
	int vertices_len;
	int edges_len;
	bool directed;
public:
	virtual IterableNeighborCollection& adjacent(int vertex_id) = 0;
	virtual void add_edge(int u, int v, int weight) = 0;
	virtual void show_graph() = 0;
	virtual EdgeCollection* get_edge_collection() = 0;
	int get_vertices_len();
	int get_edges_len();
};

#endif