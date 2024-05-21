#include "HeapNode.h"
int HeapNode::get_vertex_id()
{
	return this->vertex_id;
}

int HeapNode::get_dist()
{
	return this->dist;
}

void HeapNode::set_vertex_id(int value)
{
	this->vertex_id = value;
}

void HeapNode::set_dist(int value)
{
	this->dist = value;
}