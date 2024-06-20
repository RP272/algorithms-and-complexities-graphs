#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include "../graph/Graph.h"

class BellmanFord
{
private:
	int* d;
	int* p;

public:
	BellmanFord(Graph& graph);
	~BellmanFord();
	void run(Graph& graph, int starting_index);
	int* get_d();
	int* get_p();
	void show_path(int starting_vertex, int destination_vertex);
};

#endif