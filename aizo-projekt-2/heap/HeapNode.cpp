#include "HeapNode.h"
int HeapNode::get_vertex_id()
{
	return this->vertex_id;
}

int HeapNode::get_value()
{
	return this->value;
}

void HeapNode::set_vertex_id(int value)
{
	this->vertex_id = value;
}

void HeapNode::set_value(int value)
{
	this->value = value;
}