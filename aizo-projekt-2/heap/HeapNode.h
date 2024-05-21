#ifndef HEAPNODE_H
#define HEAPNODE_H

class HeapNode
{
private:
	int	vertex_id;
	int dist;
public:
	int get_vertex_id();
	int get_dist();
	void set_vertex_id(int value);
	void set_dist(int value);
};

#endif