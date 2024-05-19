// aizo-projekt-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"
#include "FileReader.h"

int main()
{
	/*std::vector<int> vertices;
	for (int i = 0; i < 6; i++)
		vertices.push_back(i);

	std::vector<std::vector<int>> weights;
	std::vector<int> zero;
	zero.push_back(0);
	zero.push_back(2);
	zero.push_back(0);
	zero.push_back(5);
	weights.push_back(zero);

	std::vector<int> one;
	one.push_back(0);
	one.push_back(0);
	one.push_back(1);
	one.push_back(0);
	one.push_back(4);
	weights.push_back(one);

	std::vector<int> two;
	two.push_back(0);
	two.push_back(0);
	two.push_back(0);
	two.push_back(1);
	two.push_back(3);
	weights.push_back(two);

	std::vector<int> three;
	three.push_back(0);
	three.push_back(0);
	three.push_back(0);
	three.push_back(0);
	three.push_back(0);
	three.push_back(3);
	weights.push_back(three);

	std::vector<int> four;
	four.push_back(0);
	four.push_back(0);
	four.push_back(0);
	four.push_back(0);
	four.push_back(0);
	four.push_back(3);
	weights.push_back(four);

	std::vector<std::vector<int>> neighbors;
	std::vector<int> z;
	z.push_back(1);
	z.push_back(3);
	neighbors.push_back(z);

	std::vector<int> o;
	o.push_back(2);
	o.push_back(4);
	neighbors.push_back(o);

	std::vector<int> t;
	t.push_back(3);
	t.push_back(4);
	neighbors.push_back(t);

	std::vector<int> threee;
	threee.push_back(5);
	neighbors.push_back(threee);

	std::vector<int> f;
	f.push_back(5);
	neighbors.push_back(f);

	std::vector<int> five;
	neighbors.push_back(five);

	Graph g(vertices, weights, neighbors);
	Dijkstra* algo = new Dijkstra(g);
	algo->run(g, 0);

	for (int i = 0; i < 6; i++) {
		std::cout << i << " d: " << algo->dijkstra_nodes[algo->map[i]].get_dist() << " p : " << algo->p[i] << std::endl;
	}*/

	GraphFromFile r = FileReader::read("pliczek.txt");
	std::cout << r.number_of_vertices << std::endl;
	std::cout << r.number_of_edges << std::endl;
	for (int i = 0; i < r.number_of_edges; i++)
	{
		std::cout << r.edges[i].u << " " << r.edges[i].v << " " << r.edges[i].weight << std::endl;
	}
}