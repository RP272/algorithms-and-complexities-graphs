#include "Dijkstra.h"
#include "../heap/Heap.h"
#include "../neighbor/NeighborIterator.h"
#include <iostream>

Dijkstra::Dijkstra(Graph &graph)
{
	this->dijkstra_nodes = new HeapNode[graph.get_vertices_len()];
	this->p = new int[graph.get_vertices_len()];
	this->map = new int[graph.get_vertices_len()];
}

Dijkstra::~Dijkstra()
{
	delete[] this->dijkstra_nodes;
	delete[] this->p;
	delete[] this->map;
}

void Dijkstra::run(Graph &graph, int starting_vertex)
{
	// In this case HeapNode's value is distance from starting vertex
	int n = graph.get_vertices_len();
	for (int i = 0; i < n; i++) {
		this->dijkstra_nodes[i].set_vertex_id(i);
		this->dijkstra_nodes[i].set_value(INT_MAX);
		this->p[i] = -1;
		this->map[i] = i;
	}
	this->dijkstra_nodes[starting_vertex].set_value(0);

	MinHeap* queue = new MinHeap(this->dijkstra_nodes, n, map);
	while (queue->get_len() > 0) {
		int u = queue->extract_min(this->dijkstra_nodes, map).get_vertex_id();
		if (this->dijkstra_nodes[map[u]].get_value() == INT_MAX) continue;
		IterableNeighborCollection& neighbors = graph.adjacent(u);
		NeighborIterator& iterator = neighbors.createIterator();
		while (iterator.hasMore()) {
			Neighbor neighbor = iterator.getNext();
			int new_dist = this->dijkstra_nodes[map[u]].get_value() + neighbor.get_edge_weight();
			if (this->dijkstra_nodes[map[neighbor.get_id()]].get_value() > new_dist)
			{
				this->p[neighbor.get_id()] = u;
				queue->change_key(this->dijkstra_nodes, neighbor.get_id(), new_dist, map);
			}
		}
		neighbors.destroy();
		delete& iterator;
	}
	delete queue;
};


HeapNode* Dijkstra::get_dijkstra_nodes() 
{
	return this->dijkstra_nodes;
}

int* Dijkstra::get_p()
{
	return this->p;
}

int* Dijkstra::get_map()
{
	return this->map;
}

void Dijkstra::show_path(int starting_vertex, int destination_vertex)
{
	int sum = this->dijkstra_nodes[this->map[destination_vertex]].get_value();
	if (sum == INT_MAX)
	{
		std::cout << "Brak sciezki" << std::endl;
		return;
	}
	int idx = destination_vertex;
	std::cout << destination_vertex << " <- ";
	while (this->p[idx] != -1)
	{
		std::cout << this->p[idx];
		if (this->p[idx] != starting_vertex) std::cout << " <- ";
		idx = this->p[idx];
	}
	std::cout << std::endl << "Suma wag: " << sum << std::endl;
}