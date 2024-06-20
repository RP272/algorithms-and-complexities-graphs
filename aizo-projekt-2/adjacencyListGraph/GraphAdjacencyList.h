#ifndef GRAPHADJACENCYLIST_H
#define GRAPHADJACENCYLIST_H
#include "../graph/Graph.h"
#include "SuccessorNode.h"
#include "../fileReader/FileReader.h"

class GraphAdjacencyList : public Graph
{
private:
	SuccessorNode** successor_list;
public:
	GraphAdjacencyList(GraphFromFile* graph, bool directed);
	~GraphAdjacencyList();
	GraphAdjacencyList(int number_of_vertices, int number_of_edges, bool directed);
	void add_edge(int u, int v, int weight) override;
	void show_graph() override;
	IterableNeighborCollection& adjacent(int vertex_id) override;
	EdgeCollection* get_edge_collection() override;
	bool edge_exists(int u, int v) override;
	SuccessorNode** get_successor_list();
};

#endif