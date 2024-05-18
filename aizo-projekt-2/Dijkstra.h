#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include "DijkstraVertex.h"

class Graph{
public:
	int vertices_len;
};

class Dijkstra
{
private:
	DijkstraVertex* vertex_array;
	int len;
public:
	Dijkstra(Graph graph);
	void run(Graph graph, int starting_index);
};

#endif