#include "GraphCollection.h"
#include "../randomIntegerGenerator/RandomIntegerGenerator.h"

GraphCollection::GraphCollection(GraphFromFile* graph, bool directed)
{
	this->adjacency_list = new GraphAdjacencyList(graph, directed);
	this->incidence_matrix = new GraphIncidenceMatrix(graph, directed);
}

GraphCollection::GraphCollection(int number_of_vertices, int density_in_percentage, bool directed)
{
	int number_of_edges = (density_in_percentage * ((number_of_vertices * (number_of_vertices - 1)) / 2)) / 100;
	this->adjacency_list = new GraphAdjacencyList(number_of_vertices, number_of_edges, directed);
	this->incidence_matrix = new GraphIncidenceMatrix(number_of_vertices, number_of_edges, directed);

	int counter = 0;
	int v1, v2, weight;
	RandomIntegerGenerator random_weight(1, 1000);
	RandomIntegerGenerator random_vertex(0, number_of_vertices - 1);

	int root_index = random_vertex.generate();
	for (int i = 0; i < number_of_vertices; i++)
	{
		if (i == root_index) continue;
		weight = random_weight.generate();
		this->adjacency_list->add_edge(root_index, i, weight);
		this->incidence_matrix->add_edge(root_index, i, weight);
		counter++;
	}

	while (counter < number_of_edges)
	{
		do {
			v1 = random_vertex.generate();
			v2 = random_vertex.generate();
		} while (v1 == v2 || this->adjacency_list->edge_exists(v1, v2));
		weight = random_weight.generate();
		this->adjacency_list->add_edge(v1, v2, weight);
		this->incidence_matrix->add_edge(v1, v2, weight);
		counter++;
	}
}

GraphAdjacencyList* GraphCollection::get_adjacency_list()
{
	return this->adjacency_list;
}

GraphIncidenceMatrix* GraphCollection::get_incidence_matrix()
{
	return this->incidence_matrix;
}