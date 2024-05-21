#ifndef GRAPHADJACENCYLIST_H
#define GRAPHADJACENCYLIST_H
#include "Graph.h"
#include "SuccessorNode.h"
#include "FileReader.h"

class GraphAdjacencyList : public Graph
{
private:
	SuccessorNode** successor_list;
public:
	GraphAdjacencyList(GraphFromFile graph);
	void add_edge(int u, int v, int weight) override;
	void show_graph() override;
	IterableNeighborCollection& adjacent(int vertex_id) override;
	std::vector<int> get_vertices() override;
};

#endif