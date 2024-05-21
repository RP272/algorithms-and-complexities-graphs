#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <vector>
#include <unordered_map>
#include "../graph/Graph.h"
#include "../heap/HeapNode.h"

class Dijkstra
{
private:
	HeapNode* dijkstra_nodes;
	int* p;
	std::unordered_map<int, int> map;
public:
	Dijkstra(Graph &graph);
	void run(Graph &graph, int starting_index);
	HeapNode* get_dijkstra_nodes();
	int* get_p();
	std::unordered_map<int, int> get_map();
};

#endif