#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "../graph/Graph.h"

class Kruskal
{	
private:
	int* parent;
	int* rank;
	bool* MST;
	EdgeCollection* edge_collection;
public:
	Kruskal(Graph& graph);
	void run(Graph& graph);
	void MakeSet(int v);
	int FindSet(int v);
	void Union(int u, int v);
	bool* get_MST();
	EdgeCollection* get_edge_collection();
};

#endif