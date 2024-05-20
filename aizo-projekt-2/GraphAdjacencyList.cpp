#include "GraphAdjacencyList.h"

GraphAdjacencyList::GraphAdjacencyList(GraphFromFile graph)
{
	this->vertices_len = graph.number_of_vertices;
	this->successor_list = new SuccessorNode*[graph.number_of_vertices];
	for (int i = 0; i < graph.number_of_vertices; i++)
	{
		this->successor_list[i] = nullptr;
	}

	for (int i = 0; i < graph.number_of_edges; i++)
	{
		this->add_edge(graph.edges[i].u, graph.edges[i].v, graph.edges[i].weight);
	}
}

void GraphAdjacencyList::add_edge(int u, int v, int weight)
{
	SuccessorNode* node = new SuccessorNode;
	node->successor_id = v;
	node->edge_weight = weight;
	node->next = this->successor_list[u];
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
			std::cout << "(" << successor->successor_id << ":" << successor->edge_weight << ") -> ";
			successor = successor->next;
		}
		std::cout << "nullptr" << std::endl;
	} 
}

IterableNeighborCollection& GraphAdjacencyList::adjacent(int vertex_id) 
{
	return *(this->successor_list[vertex_id]);
};

std::vector<int> GraphAdjacencyList::get_vertices() 
{
	std::vector<int> r;
	return r;
};
int GraphAdjacencyList::weight(int u, int v) { return 0; };
