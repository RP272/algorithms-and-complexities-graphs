#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>

class Graph
{
private:
	std::vector<int> vertices;
	std::vector<std::vector<int>> weights;
	std::vector<std::vector<int>> neighbors;
public:
	Graph(std::vector<int> vertices, std::vector<std::vector<int>> weights, std::vector<std::vector<int>> neighbors);
	virtual std::vector<int> adjacent(int vertex_id);
	std::vector<int> get_vertices();
	int weight(int u, int v);
};

#endif