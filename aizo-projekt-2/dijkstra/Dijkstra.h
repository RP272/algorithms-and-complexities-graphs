#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "../graph/Graph.h"
#include "../heap/HeapNode.h"

class Dijkstra
{
private:
	HeapNode* dijkstra_nodes;
	int* p;
	int* map;
public:
	Dijkstra(Graph &graph);
	void run(Graph &graph, int starting_index);
	HeapNode* get_dijkstra_nodes();
	int* get_p();
	int* get_map();
};

#endif