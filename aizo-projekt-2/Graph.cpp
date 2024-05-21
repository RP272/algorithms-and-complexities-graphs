#include "Graph.h"
Graph::Graph() {};
Graph::Graph(std::vector<int> vertices, std::vector<std::vector<int>> weights, std::vector<std::vector<int>> neighbors)
{
	this->vertices = vertices;
	this->weights = weights;
	this->neighbors = neighbors;
}

std::vector<int> Graph::get_vertices()
{
	return this->vertices;
}

//std::vector<int> Graph::adjacent(int vertex_id)
//{
//	return neighbors[vertex_id];
//}