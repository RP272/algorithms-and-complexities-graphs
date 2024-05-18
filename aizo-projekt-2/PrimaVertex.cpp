#include "PrimaVertex.h"

PrimaVertex::PrimaVertex()
{
	this->vertex_id = 0;
	this->key = 0;
	this->p = 0;
};

int PrimaVertex::get_vertex_id()
{
	return this->vertex_id;
}

int PrimaVertex::get_key()
{
	return this->key;
}

int PrimaVertex::get_p()
{
	return this->p;
}

void PrimaVertex::set_vertex_id(int value)
{
	this->vertex_id = value;
}

void PrimaVertex::set_key(int value)
{
	this->key = value;
}

void PrimaVertex::set_p(int value)
{
	this->p = value;
}

int PrimaVertex::get_value()
{
	return this->get_key();
}