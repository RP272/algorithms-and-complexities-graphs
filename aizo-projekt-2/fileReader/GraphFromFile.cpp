#include "GraphFromFile.h"

GraphFromFile::GraphFromFile() {};

int GraphFromFile::get_number_of_vertices()
{
	return this->number_of_vertices;
}

EdgeCollection* GraphFromFile::get_edge_collection()
{
	return this->edge_collection;
}

void GraphFromFile::set_number_of_vertices(int value)
{
	this->number_of_vertices = value;
}

void GraphFromFile::set_edge_collection(EdgeCollection* ptr)
{
	this->edge_collection = ptr;
}