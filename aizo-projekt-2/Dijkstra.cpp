#include "Dijkstra.h"
#include "Heap.h"
#include "NeighborIterator.h"
#include <iostream>

Dijkstra::Dijkstra(Graph &graph)
{
	this->dijkstra_nodes = new HeapNode[graph.vertices_len];
	this->p = new int[graph.vertices_len];
	for (int i = 0; i < graph.vertices_len; i++)
	{
		this->map[i] = i;
	}
}

void Dijkstra::run(Graph &graph, int starting_vertex)
{
	int n = graph.vertices_len;
	for (int i = 0; i < n; i++) {
		this->dijkstra_nodes[i].set_vertex_id(i);
		this->dijkstra_nodes[i].set_dist(2147483647);
		this->p[i] = -1;
	}
	this->dijkstra_nodes[0].set_dist(0);

	MinHeap* queue = new MinHeap(this->dijkstra_nodes, n, map);
	while (queue->get_len() > 0) {
		int u = queue->extract_min(this->dijkstra_nodes, map).get_vertex_id();
		//std::vector<int> neighbors = graph.adjacent(u);
		IterableNeighborCollection& neighbors = graph.adjacent(u);
		NeighborIterator& iterator = neighbors.createIterator();
		while (iterator.hasMore()) {
			Neighbor neighbor = iterator.getNext();
			int new_dist = this->dijkstra_nodes[map[u]].get_dist() + neighbor.edge_weight;
			if (this->dijkstra_nodes[map[neighbor.id]].get_dist() > new_dist)
			{
				this->p[neighbor.id] = u;
				queue->change_key(this->dijkstra_nodes, neighbor.id, new_dist, map);
			}
		}
		/*for (int j = 0; j < neighbors.size(); j++) {
			int v = neighbors[j];
			int new_dist = this->dijkstra_nodes[map[u]].get_dist() + graph.weight(u, v);
			if (this->dijkstra_nodes[map[v]].get_dist() > new_dist)
			{
				this->p[v] = u;
				queue->change_key(this->dijkstra_nodes, v, new_dist, map);
			}
		}*/
	}
};