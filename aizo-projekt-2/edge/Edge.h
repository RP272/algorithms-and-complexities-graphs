#ifndef EDGE_H
#define EDGE_H

class Edge
{
private:
	int start_vertex_id;
	int end_vertex_id;
	int weight;
public:
	Edge();
	Edge(int start_vertex_id, int end_vertex_id, int weight);
	int get_start_vertex_id();
	int get_end_vertex_id();
	int get_weight();
	void set_start_vertex_id(int value);
	void set_end_vertex_id(int value);
	void set_weight(int value);
};

#endif