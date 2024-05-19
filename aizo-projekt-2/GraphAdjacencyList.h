#ifndef GRAPHADJACENCYLIST_HPP
#define GRAPHADJACENCYLIST_HPP
#include "Graph.h"
#include "SuccessorNode.h"
#include "FileReader.h"

class GraphAdjacencyList : Graph
{
private:
	SuccessorNode** successor_list;
public:
	GraphAdjacencyList(GraphFromFile graph);
};

#endif