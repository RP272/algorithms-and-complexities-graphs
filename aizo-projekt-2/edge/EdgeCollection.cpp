#include "EdgeCollection.h"

EdgeCollection::EdgeCollection(Edge* edges, int len)
{
	this->edges = edges;
	this->len = len;
}

Edge* EdgeCollection::get_edges()
{
	return this->edges;
}

int EdgeCollection::get_len()
{
	return this->len;
}