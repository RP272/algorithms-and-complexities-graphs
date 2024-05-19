// aizo-projekt-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"

int main()
{
	std::vector<int> vertices;
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
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
