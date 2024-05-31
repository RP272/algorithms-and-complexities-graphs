#include "Kruskal.h"
#include <iostream>
Kruskal::Kruskal(Graph& graph)
{
	this->rank = new int[graph.get_vertices_len()];
	this->parent = new int[graph.get_vertices_len()];
	int len = graph.get_edges_len();
	this->MST = new bool[len];
	for (int i = 0; i < len; i++)
	{
		this->MST[i] = false;
	}
}

void Kruskal::run(Graph& graph)
{
	int n = graph.get_vertices_len();
	for (int i = 0; i < n; i++) {
		this->MakeSet(i);
	}
	Edge e;
	this->edge_collection = graph.get_edge_collection();
	this->edge_collection->quicksort(0, this->edge_collection->get_len()-1);
	for (int i = 0; i < this->edge_collection->get_len(); i++)
	{
		e = this->edge_collection->get_edges()[i];
		if (FindSet(e.get_start_vertex_id()) != FindSet(e.get_end_vertex_id()))
		{
			this->MST[i] = true;
			this->Union(e.get_start_vertex_id(), e.get_end_vertex_id());
		}
	}
}

void Kruskal::MakeSet(int v)
{
	this->rank[v] = 0;
	this->parent[v] = v;
}

void Kruskal::Union(int u, int v)
{
	int x = FindSet(u);
	int y = FindSet(v);
	if (this->rank[x] < this->rank[y]) this->parent[x] = y;
	else this->parent[y] = x;
	if (this->rank[x] == this->rank[y])
		this->rank[x]++;
}

int Kruskal::FindSet(int v)
{
	if (this->parent[v] != v)
	{
		this->parent[v] = FindSet(this->parent[v]);
	}
	return this->parent[v];
}

bool* Kruskal::get_MST()
{
	return this->MST;
}

EdgeCollection* Kruskal::get_edge_collection()
{
	return this->edge_collection;
}
