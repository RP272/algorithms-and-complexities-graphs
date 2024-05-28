#ifndef GRAPHFROMFILE_H
#define GRAPHFROMFILE_H
#include "../edge/EdgeCollection.h"

class GraphFromFile
{
private:
	int number_of_vertices;
	EdgeCollection* edge_collection;
public:
	GraphFromFile();
	int get_number_of_vertices();
	EdgeCollection* get_edge_collection();
	void set_number_of_vertices(int value);
	void set_edge_collection(EdgeCollection* ptr);
};

#endif