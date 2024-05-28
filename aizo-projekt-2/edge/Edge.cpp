#include "Edge.h"

Edge::Edge() {};

Edge::Edge(int start_vertex_id, int end_vertex_id, int weight)
{
	this->start_vertex_id = start_vertex_id;
	this->end_vertex_id = end_vertex_id;
	this->weight = weight;
}

int Edge::get_start_vertex_id()
{
	return this->start_vertex_id;
}

int Edge::get_end_vertex_id()
{
	return this->end_vertex_id;
}

int Edge::get_weight()
{
	return this->weight;
}

void Edge::set_start_vertex_id(int value)
{
	this->start_vertex_id = value;
}

void Edge::set_end_vertex_id(int value)
{
	this->end_vertex_id = value;
}

void Edge::set_weight(int value)
{
	this->weight = value;
}
