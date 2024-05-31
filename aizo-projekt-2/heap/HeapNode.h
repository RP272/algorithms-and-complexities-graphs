#ifndef HEAPNODE_H
#define HEAPNODE_H

class HeapNode
{
private:
	int	vertex_id;
	int value;
public:
	int get_vertex_id();
	int get_value();
	void set_vertex_id(int value);
	void set_value(int value);
};

#endif