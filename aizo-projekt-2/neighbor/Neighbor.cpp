#include "Neighbor.h"

Neighbor::Neighbor() {};

Neighbor::Neighbor(int id, int edge_weight)
{
	this->id = id;
	this->edge_weight = edge_weight;
}

int Neighbor::get_id()
{
	return this->id;
}

int Neighbor::get_edge_weight()
{
	return this->edge_weight;
}

void Neighbor::set_id(int value)
{
	this->id = value;
}

void Neighbor::set_edge_weight(int value)
{
	this->edge_weight = value;
}