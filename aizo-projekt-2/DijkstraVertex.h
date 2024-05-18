#ifndef DIJKSTRAVERTEX_HPP
#define DIJKSTRAVERTEX_HPP
#include "IValue.h"

class DijkstraVertex : public IValue
{
private:
	int vertex_id;
	int d;
	int p;
public:
	DijkstraVertex();
	int get_vertex_id();
	int get_d();
	int get_p();
	void set_vertex_id(int value);
	void set_d(int value);
	void set_p(int value);
	int get_value() override;
};

#endif
