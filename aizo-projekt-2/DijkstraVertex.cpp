#include "DijkstraVertex.h"

DijkstraVertex::DijkstraVertex() 
{
	this->vertex_id = 0;
	this->d = 0;
	this->p = 0;
};

int DijkstraVertex::get_vertex_id()
{
	return this->vertex_id;
}

int DijkstraVertex::get_d()
{
	return this->d;
}

int DijkstraVertex::get_p()
{
	return this->p;
}

void DijkstraVertex::set_vertex_id(int value)
{
	this->vertex_id = value;
}

void DijkstraVertex::set_d(int value)
{
	this->d = value;
}

void DijkstraVertex::set_p(int value)
{
	this->p = value;
}

int DijkstraVertex::get_value() 
{
	return this->get_d();
}