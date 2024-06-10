#include "BellmanFord.h"
#include "../edge/EdgeCollection.h"
#include <climits>
#include <iostream>

BellmanFord::BellmanFord(Graph& graph)
{
	this->d = new int[graph.get_vertices_len()];
	this->p = new int[graph.get_vertices_len()];
}

void BellmanFord::run(Graph& graph, int starting_index)
{
	int n = graph.get_vertices_len();
	for (int i = 0; i < n; i++) {
		this->d[i] = INT_MAX;
		this->p[i] = -1;
	}
	this->d[starting_index] = 0;

	EdgeCollection* edge_collection = graph.get_edge_collection();
	Edge e;
	int u, v;
	bool any_updates;
	for (int i = 0; i < n; i++)
	{
		any_updates = false;
		for (int j = 0; j < edge_collection->get_len(); j++)
		{
			e = edge_collection->get_edges()[j];
			u = e.get_start_vertex_id();
			v = e.get_end_vertex_id();
			if (d[u] == INT_MAX) continue;
			if (d[v] > d[u] + e.get_weight())
			{
				any_updates = true;
				d[v] = d[u] + e.get_weight();
				p[v] = u;
;			}
		}
		if (any_updates == false) break;
	}
}

int* BellmanFord::get_d()
{
	return this->d;
}

int* BellmanFord::get_p()
{
	return this->p;
}

void BellmanFord::show_path(int starting_vertex, int destination_vertex)
{
	int sum = this->d[destination_vertex];
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