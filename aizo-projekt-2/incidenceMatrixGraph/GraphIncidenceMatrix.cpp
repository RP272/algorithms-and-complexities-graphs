#include "GraphIncidenceMatrix.h"
#include "IncidenceMatrixNeighborCollection.h"
#include "../adjacencyListGraph/SuccessorNode.h"
#include <iomanip>
#include <iostream>

GraphIncidenceMatrix::GraphIncidenceMatrix(GraphFromFile* graph)
{
	this->vertices_len = graph->get_number_of_vertices();
	this->edges_counter = 0;
	this->weights = new int[this->edges_len];
	this->incidence_matrix = new int* [this->vertices_len];
	for (int i = 0; i < this->vertices_len; i++)
	{
		this->incidence_matrix[i] = new int[this->edges_counter];
	}

	for (int a = 0; a < graph->get_edge_collection()->get_len(); a++)
	{
		Edge e = graph->get_edge_collection()->get_edges()[a];
		this->add_edge(e.get_start_vertex_id(), e.get_end_vertex_id(), e.get_weight());
	}
}

void GraphIncidenceMatrix::add_edge(int u, int v, int weight) 
{
	int** matrix_copy = new int* [this->vertices_len];
	for (int i = 0; i < this->vertices_len; i++)
	{
		matrix_copy[i] = new int[this->edges_counter];
		for (int j = 0; j < this->edges_counter; j++)
			matrix_copy[i][j] = this->incidence_matrix[i][j];
	}
	int* weights_copy = new int[this->edges_counter];
	for(int i = 0; i < this->edges_counter; i++)
	{
		weights_copy[i] = this->weights[i];
	}
	delete[] this->weights;

	for (int i = 0; i < this->vertices_len; i++)
	{
		delete[] this->incidence_matrix[i];
	}
	
	this->edges_counter++;
	for (int i = 0; i < this->vertices_len; i++)
	{
		this->incidence_matrix[i] = new int[this->edges_counter];
		for (int j = 0; j < this->edges_counter-1; j++)
			this->incidence_matrix[i][j] = matrix_copy[i][j];
		this->incidence_matrix[i][this->edges_counter-1] = 0;
	}
	this->incidence_matrix[u][this->edges_counter - 1] = -1;
	this->incidence_matrix[v][this->edges_counter - 1] = 1;

	this->weights = new int[this->edges_counter];
	for (int i = 0; i < this->edges_counter-1; i++)
	{
		this->weights[i] = weights_copy[i];
	}
	this->weights[this->edges_counter-1] = weight;

	for (int i = 0; i < this->vertices_len; i++)
	{
		delete[] matrix_copy[i];
	}
	delete[] matrix_copy;
	delete[] weights_copy;
};
void GraphIncidenceMatrix::show_graph()
{
	std::cout << "Incidence Matrix:" << std::endl;
	for (int i = 0; i < this->vertices_len; i++)
	{
		std::cout << i << ": ";
		for (int j = 0; j < this->edges_counter; j++)
		{
			std::cout << std::setw(3) << this->incidence_matrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "Weights:" << std::endl << "   ";
	for (int i = 0; i < this->edges_counter; i++)
	{
		std::cout << std::setw(3) << this->weights[i];
	}
	std::cout << std::endl;
};

IterableNeighborCollection& GraphIncidenceMatrix::adjacent(int vertex_id) 
{
	IncidenceMatrixNeighborCollection* neighbors = new IncidenceMatrixNeighborCollection();
	for (int i = 0; i < this->edges_counter; i++)
	{
		if (this->incidence_matrix[vertex_id][i] == -1) {
			for (int j = 0; j < this->edges_counter; j++) {
				if (this->incidence_matrix[j][i] == 1) {
					neighbors->add_neighbor(j, this->weights[i]);
					break;
				}
			}
		}
	}
	return *neighbors;
};

EdgeCollection* GraphIncidenceMatrix::get_edge_collection()
{
	Edge* edges = new Edge[this->edges_counter];
	for (int i = 0; i < this->edges_counter; i++)
	{
		for (int j = 0; j < this->vertices_len; j++)
		{
			if (this->incidence_matrix[j][i] == -1) edges[i].set_start_vertex_id(j);
			else if (this->incidence_matrix[j][i] == 1) edges[i].set_end_vertex_id(j);
		}
		edges[i].set_weight(this->weights[i]);
	}
	return new EdgeCollection(edges, this->edges_counter);
}
