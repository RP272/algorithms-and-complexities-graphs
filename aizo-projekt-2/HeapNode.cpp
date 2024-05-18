#include "HeapNode.h"

HeapNode::HeapNode(int value)
{
	this->value = value;
}

int HeapNode::get_value()
{
	return this->value;
}

void HeapNode::set_value(int v)
{
	this->value = v;
}