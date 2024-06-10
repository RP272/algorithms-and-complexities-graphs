#ifndef PRIMA_H
#define PRIMA_H
#include "../graph/Graph.h"
#include "../heap/HeapNode.h"

class Prim
{
private:
	HeapNode* prima_nodes;
	int* p;
	int* map;
	bool* in_queue;
public:
	Prim(Graph& graph);
	void run(Graph& graph, int starting_vertex);
	HeapNode* get_prima_nodes();
	int* get_p();
	int* get_map();
	void show_mst(int vertices_len);
};

#endif