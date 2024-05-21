#include "GraphAdjacencyList.h"

GraphAdjacencyList::GraphAdjacencyList(GraphFromFile graph)
{
	this->vertices_len = graph.number_of_vertices;
	this->successor_list = new SuccessorNode*[graph.number_of_vertices];
	for (int i = 0; i < graph.number_of_vertices; i++)
	{
		SuccessorNode* null_node = new SuccessorNode(-1, -1, nullptr);
		this->successor_list[i] = null_node;
	}

	for (int i = 0; i < graph.number_of_edges; i++)
	{
		this->add_edge(graph.edges[i].u, graph.edges[i].v, graph.edges[i].weight);
	}
}

void GraphAdjacencyList::add_edge(int u, int v, int weight)
{
	SuccessorNode* node = new SuccessorNode(v, weight, this->successor_list[u]);
	this->successor_list[u] = node;
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