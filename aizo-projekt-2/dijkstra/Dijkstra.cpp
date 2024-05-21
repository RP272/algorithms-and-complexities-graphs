#include "Dijkstra.h"
#include "../heap/Heap.h"
#include "../neighbor/NeighborIterator.h"
#include <iostream>

Dijkstra::Dijkstra(Graph &graph)
{
	this->dijkstra_nodes = new HeapNode[graph.get_vertices_len()];
	this->p = new int[graph.get_vertices_len()];
}

void Dijkstra::run(Graph &graph, int starting_vertex)
{
	int n = graph.get_vertices_len();
	for (int i = 0; i < n; i++) {
		this->dijkstra_nodes[i].set_vertex_id(i);
		this->dijkstra_nodes[i].set_dist(INT_MAX);
		this->p[i] = -1;
		this->map[i] = i;
	}
	this->dijkstra_nodes[starting_vertex].set_dist(0);

	MinHeap* queue = new MinHeap(this->dijkstra_nodes, n, map);
	while (queue->get_len() > 0) {
		int u = queue->extract_min(this->dijkstra_nodes, map).get_vertex_id();
		if (this->dijkstra_nodes[map[u]].get_dist() == INT_MAX) continue;
		IterableNeighborCollection& neighbors = graph.adjacent(u);
		NeighborIterator& iterator = neighbors.createIterator();
		while (iterator.hasMore()) {
			Neighbor neighbor = iterator.getNext();
			int new_dist = this->dijkstra_nodes[map[u]].get_dist() + neighbor.get_edge_weight();
			if (this->dijkstra_nodes[map[neighbor.get_id()]].get_dist() > new_dist)
			{
				this->p[neighbor.get_id()] = u;
				queue->change_key(this->dijkstra_nodes, neighbor.get_id(), new_dist, map);
			}
		}
	}
};


HeapNode* Dijkstra::get_dijkstra_nodes() 
{
	return this->dijkstra_nodes;
}

int* Dijkstra::get_p()
{
	return this->p;
}

std::unordered_map<int, int> Dijkstra::get_map()
{
	return this->map;
}