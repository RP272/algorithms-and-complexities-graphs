#ifndef GRAPHCOLLECTION_H
#define GRAPHCOLLECTION_H
#include "../adjacencyListGraph/GraphAdjacencyList.h"
#include "../incidenceMatrixGraph/GraphIncidenceMatrix.h"

class GraphCollection
{
private:
	GraphAdjacencyList* adjacency_list;
	GraphIncidenceMatrix* incidence_matrix;
public:
	GraphCollection() {};
	GraphCollection(GraphFromFile* graph, bool directed);
	GraphCollection(int number_of_vertices, int density_in_percentage, bool directed);
	GraphAdjacencyList* get_adjacency_list();
	GraphIncidenceMatrix* get_incidence_matrix();
};
#endif