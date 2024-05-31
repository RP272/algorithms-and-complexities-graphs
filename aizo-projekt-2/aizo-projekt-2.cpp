// aizo-projekt-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "graph/Graph.h"
#include "dijkstra/Dijkstra.h"
#include "fileReader/FileReader.h"
#include "adjacencyListGraph/GraphAdjacencyList.h"
#include "incidenceMatrixGraph/GraphIncidenceMatrix.h"
#include "bellmanFord/BellmanFord.h"
#include "prim/Prim.h"
#include "kruskal/Kruskal.h"

int main()
{
	GraphFromFile* r = FileReader::read("pliczek.txt");
	GraphIncidenceMatrix g = GraphIncidenceMatrix(r, false);
	//GraphAdjacencyList g = GraphAdjacencyList(r, false);
	g.show_graph();
	//Prim* algo = new Prim(g);
	//algo->run(g, 3);
	//for (int i = 0; i < 6; i++) {
	//	int weight = algo->get_prima_nodes()[algo->get_map()[i]].get_value();
	//	int p = algo->get_p()[i];
	//	if(p != - 1) std::cout << i << "-" << p << ":" << weight << std::endl;
	//}
	Kruskal* algo = new Kruskal(g);
	algo->run(g);
	Edge e;
	for (int i = 0; i < algo->get_edge_collection()->get_len(); i++)
	{
		if (algo->get_MST()[i] == true)
		{
			e = algo->get_edge_collection()->get_edges()[i];
			std::cout << e.get_start_vertex_id() << "-" << e.get_end_vertex_id() << ":" << e.get_weight() << std::endl;
		}
	}

	//Dijkstra* algo = new Dijkstra(g);
	//algo->run(g, 0);
	//for (int i = 0; i < 6; i++) {
	//	std::cout << i << " d: " << algo->get_dijkstra_nodes()[algo->get_map()[i]].get_value() << " p : " << algo->get_p()[i] << std::endl;
	//}
	/*BellmanFord* bellmanFord = new BellmanFord(g);
	bellmanFord->run(g, 0);
	for (int i = 0; i < 6; i++) {
		std::cout << i << " d: " << bellmanFord->get_d()[i] << " p : " << bellmanFord->get_p()[i] << std::endl;
	}*/
	/*GraphAdjacencyList g = GraphAdjacencyList(r);
	g.show_graph();
	
	std::cout << "############################" << std::endl;
	algo->run(g, 1);
	for (int i = 0; i < 6; i++) {
		std::cout << i << " d: " << algo->get_dijkstra_nodes()[algo->get_map()[i]].get_dist() << " p : " << algo->get_p()[i] << std::endl;
	}*/
}