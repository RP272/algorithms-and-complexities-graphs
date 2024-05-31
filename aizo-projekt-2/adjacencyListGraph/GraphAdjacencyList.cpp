#include "GraphAdjacencyList.h"
#include <iostream>

GraphAdjacencyList::GraphAdjacencyList(GraphFromFile* graph, bool directed)
{
	this->vertices_len = graph->get_number_of_vertices();
	this->edges_len = graph->get_edge_collection()->get_len();
	this->successor_list = new SuccessorNode*[graph->get_number_of_vertices()];
	this->directed = directed;
	for (int i = 0; i < graph->get_number_of_vertices(); i++)
	{
		this->successor_list[i] = new SuccessorNode(-1, -1, nullptr);
	}

	for (int i = 0; i < graph->get_edge_collection()->get_len(); i++)
	{
		Edge e = graph->get_edge_collection()->get_edges()[i];
		this->add_edge(e.get_start_vertex_id(), e.get_end_vertex_id(), e.get_weight());
	}
}

void GraphAdjacencyList::add_edge(int u, int v, int weight)
{
	SuccessorNode* node = new SuccessorNode(v, weight, this->successor_list[u]);
	this->successor_list[u] = node;
	if (this->directed == false) {
		SuccessorNode* node2 = new SuccessorNode(u, weight, this->successor_list[v]);
		this->successor_list[v] = node2;
	}
}

void GraphAdjacencyList::show_graph()
{
	SuccessorNode* successor;
	for (int i = 0; i < this->vertices_len; i++)
	{
		std::cout << i << " -> ";
		successor = this->successor_list[i];
		while (successor != nullptr) {
			if (successor->get_id() == -1) {
				std::cout << "null" << std::endl;
				break;
			}
			std::cout << "(" << successor->get_id() << ":" << successor->get_edge_weight() << ") -> ";
			successor = successor->get_next();
		}
	} 
}

IterableNeighborCollection& GraphAdjacencyList::adjacent(int vertex_id) 
{
	return *(this->successor_list[vertex_id]);
};

EdgeCollection* GraphAdjacencyList::get_edge_collection()
{
	Edge* edges = new Edge[this->get_edges_len()];
	int edges_counter = 0;
	SuccessorNode* iterator;
	for (int i = 0; i < this->vertices_len; i++) {
		iterator = this->successor_list[i];
		while (iterator->get_id() != -1) {
			if (this->directed == false || (this->directed == true && i < iterator->get_id())) {
				edges[edges_counter].set_start_vertex_id(i);
				edges[edges_counter].set_end_vertex_id(iterator->get_id());
				edges[edges_counter].set_weight(iterator->get_edge_weight());
				edges_counter++;
			}
			iterator = iterator->get_next();
		}
	}
	return new EdgeCollection(edges, this->get_edges_len());
}
