#ifndef NEIGHBOR_H
#define NEIGHBOR_H

class Neighbor
{
protected:
	int id;
	int edge_weight;
public:
	Neighbor(int id, int edge_weight);
	int get_id();
	int get_edge_weight();
	void set_id(int value);
	void set_edge_weight(int value);
};

#endif