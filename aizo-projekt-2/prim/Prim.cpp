#include "Prim.h"
#include "../heap/Heap.h"
#include <climits>
#include <iostream>

Prim::Prim(Graph& graph)
{
	this->prima_nodes = new HeapNode[graph.get_vertices_len()];
	this->p = new int[graph.get_vertices_len()];
	this->map = new int[graph.get_vertices_len()];
	this->in_queue = new bool[graph.get_vertices_len()];
}

void Prim::run(Graph& graph, int starting_vertex)
{
	int n = graph.get_vertices_len();
	int u, v, w;
	for (int i = 0; i < n; i++) {
		this->prima_nodes[i].set_vertex_id(i);
		this->prima_nodes[i].set_value(INT_MAX);
		this->p[i] = -1;
		this->map[i] = i;
		this->in_queue[i] = true;
	}
	this->prima_nodes[starting_vertex].set_value(0);

	MinHeap* queue = new MinHeap(this->prima_nodes, n, map);
	while (queue->get_len() > 0) {
		u = queue->extract_min(this->prima_nodes, map).get_vertex_id();
		this->in_queue[u] = false;
		IterableNeighborCollection& neighbors = graph.adjacent(u);
		NeighborIterator& iterator = neighbors.createIterator();
		while (iterator.hasMore()) {
			Neighbor neighbor = iterator.getNext();
			v = neighbor.get_id();
			w = neighbor.get_edge_weight();
			if (this->in_queue[v] == true && w < this->prima_nodes[map[v]].get_value())
			{
				p[v] = u;
				queue->change_key(this->prima_nodes, v, w, this->map);
			}
		}
	}
}

HeapNode* Prim::get_prima_nodes()
{
	return this->prima_nodes;
}

int* Prim::get_p()
{
	return this->p;
}

int* Prim::get_map()
{
	return this->map;
}

void Prim::show_mst(int vertices_len)
{
	int sum = 0;
	for (int i = 0; i < vertices_len; i++)
	{
		int weight = this->prima_nodes[this->map[i]].get_value();
		int p = this->p[i];
		if(p != - 1) std::cout << p << "-" << i << ":" << weight << std::endl;
		sum += weight;
	}
	std::cout << "Suma wag: " << sum << std::endl;
}