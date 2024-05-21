#ifndef GRAPH_H
#define GRAPH_H

#include "IterableNeighborCollection.h"
#include <vector>

class Graph
{
public:
	int vertices_len;
	std::vector<int> vertices;
	std::vector<std::vector<int>> weights;
	std::vector<std::vector<int>> neighbors;
public:
	Graph();
	Graph(std::vector<int> vertices, std::vector<std::vector<int>> weights, std::vector<std::vector<int>> neighbors);
	virtual IterableNeighborCollection& adjacent(int vertex_id) = 0;
	virtual std::vector<int> get_vertices() = 0;
	virtual void add_edge(int u, int v, int weight) = 0;
	virtual void show_graph() = 0;
};

#endif