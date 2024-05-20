#ifndef GRAPHADJACENCYLIST_HPP
#define GRAPHADJACENCYLIST_HPP
#include "Graph.h"
#include "SuccessorNode.h"
#include "FileReader.h"

class GraphAdjacencyList : Graph
{
private:
	SuccessorNode** successor_list;
public:
	GraphAdjacencyList(GraphFromFile graph);
	void add_edge(int u, int v, int weight) override;
	void show_graph() override;
	std::vector<int> adjacent(int vertex_id) override;
	std::vector<int> get_vertices() override;
	int weight(int u, int v) override;
};

#endif