#include "Dijkstra.h"
#include "Heap.h"
#include <iostream>

Dijkstra::Dijkstra(Graph &graph)
{
	this->dijkstra_nodes = new HeapNode[graph.get_vertices().size()];
	this->p = new int[graph.get_vertices().size()];
	for (int i = 0; i < graph.get_vertices().size(); i++)
	{
		this->map[i] = i;
	}
}

void Dijkstra::run(Graph &graph, int starting_vertex)
{
	int n = graph.get_vertices().size();
	for (int i = 0; i < n; i++) {
		this->dijkstra_nodes[i].set_vertex_id(i);
		this->dijkstra_nodes[i].set_dist(2147483647);
		this->p[i] = -1;
	}
	this->dijkstra_nodes[0].set_dist(0);

	MinHeap* queue = new MinHeap(this->dijkstra_nodes, n, map);
	while (queue->get_len() > 0) {
		int u = queue->extract_min(this->dijkstra_nodes, map).get_vertex_id();
		std::vector<int> neighbors = graph.adjacent(u);
		for (int j = 0; j < neighbors.size(); j++) {
			int v = neighbors[j];
			int new_dist = this->dijkstra_nodes[map[u]].get_dist() + graph.weight(u, v);
			if (this->dijkstra_nodes[map[v]].get_dist() > new_dist)
			{
				this->p[v] = u;
				queue->change_key(this->dijkstra_nodes, v, new_dist, map);
			}
		}

	}
};