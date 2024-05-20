#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <vector>
#include <unordered_map>
#include "Graph.h"
#include "HeapNode.h"

class Dijkstra
{
public:
	HeapNode* dijkstra_nodes;
	int* p;
	std::unordered_map<int, int> map;
	Dijkstra(Graph &graph);
	void run(Graph &graph, int starting_index);
};

#endif