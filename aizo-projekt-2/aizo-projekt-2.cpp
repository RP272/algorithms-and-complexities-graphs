// aizo-projekt-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "graph/Graph.h"
#include "dijkstra/Dijkstra.h"
#include "fileReader/FileReader.h"
#include "adjacencyListGraph/GraphAdjacencyList.h"

int main()
{
	GraphFromFile r = FileReader::read("pliczek.txt");
	GraphAdjacencyList g = GraphAdjacencyList(r);
	g.show_graph();
	Dijkstra* algo = new Dijkstra(g);
	algo->run(g, 0);
	for (int i = 0; i < 6; i++) {
		std::cout << i << " d: " << algo->get_dijkstra_nodes()[algo->get_map()[i]].get_dist() << " p : " << algo->get_p()[i] << std::endl;
	}
}