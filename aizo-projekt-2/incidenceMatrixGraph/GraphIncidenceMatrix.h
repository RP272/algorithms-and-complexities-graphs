#ifndef GRAPHINCIDENCEMATRIX_H
#define GRAPHINCIDENCEMATRIX_H
#include "../graph/Graph.h"
#include "../fileReader/FileReader.h"

class GraphIncidenceMatrix : public Graph
{
private:
	int edges_counter;
	int** incidence_matrix;
	int* weights;
public:
	GraphIncidenceMatrix(GraphFromFile* graph, bool directed);
	~GraphIncidenceMatrix();
	GraphIncidenceMatrix(int number_of_vertices, int number_of_edges, bool directed);
	void add_edge(int u, int v, int weight) override;
	void show_graph() override;
	IterableNeighborCollection& adjacent(int vertex_id) override;
	EdgeCollection* get_edge_collection() override;
	bool edge_exists(int u, int v) override;
};

#endif