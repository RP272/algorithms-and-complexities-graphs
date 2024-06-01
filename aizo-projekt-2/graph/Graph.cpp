#include "Graph.h"
int Graph::get_vertices_len() 
{
	return this->vertices_len;
};

int Graph::get_edges_len()
{
	return this->edges_len;
};

void Graph::set_vertices_len(int value)
{
	this->vertices_len = value;
}

void Graph::set_edges_len(int value)
{
	this->edges_len = value;
}

void Graph::set_directed(bool value)
{
	this->directed = value;
}