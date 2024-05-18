#ifndef PRIMAVERTEX_HPP
#define PRIMAVERTEX_HPP
#include "IValue.h"

class PrimaVertex : public IValue
{
private:
	int vertex_id;
	int key;
	int p;
public:
	PrimaVertex();
	int get_vertex_id();
	int get_key();
	int get_p();
	void set_vertex_id(int value);
	void set_key(int value);
	void set_p(int value);
	int get_value() override;
};

#endif
