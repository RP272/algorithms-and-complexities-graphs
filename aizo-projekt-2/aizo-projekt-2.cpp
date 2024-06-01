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
#include "graph/GraphCollection.h"

int main()
{
	int main_menu = 0, sub_menu;
	int number_of_vertices, density, starting_vertex;
	std::string filename;
	GraphCollection* graph_collection = new GraphCollection(10, 0, false);
	GraphFromFile* r;
	while (main_menu != 3)
	{
		sub_menu = 0;
		std::cout << std::endl;
		std::cout << "1. Minimalne drzewo rozpinajace" << std::endl;
		std::cout << "2. Najkrotsza sciezka w grafie" << std::endl;
		std::cout << "3. Zakoncz program" << std::endl;
		std::cout << "Wybierz problem do rozwiazania: ";
		while (!(std::cin >> main_menu) || main_menu < 1 || main_menu > 3) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Niewlasciwy wybor. Wprowadz ponownie: ";
		}
		while (sub_menu != 6 && main_menu != 3)
		{
			std::cout << std::endl;
			std::cout << "1. Wczytaj dane z pliku." << std::endl;
			std::cout << "2. Wygeneruj graf losowo." << std::endl;
			std::cout << "3. Wyswietl graf listowo i macierzowo na ekranie." << std::endl;
			if (main_menu == 1)
			{
				std::cout << "4. Algorytm Prima macierzowo i listowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "5. Algorytm Kruskala macierzowo i listowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "6. Powrot do glownego menu." << std::endl;
				std::cout << "Wybierz opcje z menu: ";
				while (!(std::cin >> sub_menu) || sub_menu < 1 || sub_menu > 6) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Niewlasciwy wybor. Wprowadz ponownie: ";
				}
				switch (sub_menu)
				{
				case 1:
				{
					std::cout << "Podaj nazwe pliku: ";
					std::cin >> filename;
					r = FileReader::read(filename);
					graph_collection = new GraphCollection(r, false);
					std::cout << "Graf zostal zapisany w pamieci." << std::endl;
				}
				break;
				case 2:
				{
					std::cout << "Podaj ilosc wierzcholkow: ";
					std::cin >> number_of_vertices;
					std::cout << std::endl << "Podaj gestosc grafu: ";
					std::cin >> density;
					graph_collection = new GraphCollection(number_of_vertices, density, false);
					std::cout << "Graf zostal zapisany w pamieci." << std::endl;
				}
				break;
				case 3:
				{
					graph_collection->get_adjacency_list()->show_graph();
					graph_collection->get_incidence_matrix()->show_graph();
				}
				break;
				case 4:
				{
					std::cout << "Podaj wierzcholek startowy: ";
					std::cin >> starting_vertex;
					if (starting_vertex < 0 || starting_vertex >= graph_collection->get_adjacency_list()->get_vertices_len()) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					Prim* prim = new Prim(*graph_collection->get_adjacency_list());
					prim->run(*graph_collection->get_adjacency_list(), 0);
				}
				break;
				case 5:
				{
					std::cout << "Podaj wierzcholek startowy: ";
					std::cin >> starting_vertex;
					if (starting_vertex < 0 || starting_vertex >= graph_collection->get_adjacency_list()->get_vertices_len()) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					BellmanFord* bellmanFord = new BellmanFord(*graph_collection->get_adjacency_list());
					bellmanFord->run(*graph_collection->get_adjacency_list(), 0);
				}
				break;
				case 6:
					break;
				}
			}
			else if (main_menu == 2)
			{
				std::cout << "4. Algorytm Dijkstry macierzowo i listowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "5. Algorytm Bellmana-Forda macierzowo i listowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "6. Powrot do glownego menu." << std::endl;
				std::cout << "Wybierz opcje z menu: ";
				while (!(std::cin >> sub_menu) || sub_menu < 1 || sub_menu > 6) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Niewlasciwy wybor. Wprowadz ponownie: ";
				}
				switch (sub_menu)
				{
				case 1:
				{
					std::cout << "Podaj nazwe pliku: ";
					std::cin >> filename;
					GraphFromFile* r = FileReader::read(filename);
					graph_collection = new GraphCollection(r, false);
					std::cout << "Graf zostal zapisany w pamieci." << std::endl;
				}
				break;
				case 2:
				{
					std::cout << "Podaj ilosc wierzcholkow: ";
					std::cin >> number_of_vertices;
					std::cout << std::endl << "Podaj gestosc grafu: ";
					std::cin >> density;
					graph_collection = new GraphCollection(number_of_vertices, density, false);
					std::cout << "Graf zostal zapisany w pamieci." << std::endl;
				}
				break;
				case 3:
				{
					graph_collection->get_adjacency_list()->show_graph();
					graph_collection->get_incidence_matrix()->show_graph();
				}
				break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				}
			}
		}
		
	}

	

	//GraphFromFile* r = FileReader::read("pliczek.txt");
	//GraphCollection* gcol = new GraphCollection(10, 25, true);
	//gcol->get_adjacency_list()->show_graph();
	//gcol->get_incidence_matrix()->show_graph();
	//GraphIncidenceMatrix g = GraphIncidenceMatrix(r, false);
	//GraphAdjacencyList g = GraphAdjacencyList(r, true);
	//GraphAdjacencyList g = GraphAdjacencyList(600, 99, true);
	//GraphIncidenceMatrix g = GraphIncidenceMatrix(100, 99, true);
	//g.show_graph();
	//Prim* algo = new Prim(g);
	//algo->run(g, 3);
	//for (int i = 0; i < 6; i++) {
	//	int weight = algo->get_prima_nodes()[algo->get_map()[i]].get_value();
	//	int p = algo->get_p()[i];
	//	if(p != - 1) std::cout << i << "-" << p << ":" << weight << std::endl;
	//}
	/*Kruskal* algo = new Kruskal(g);
	algo->run(g);
	Edge e;
	for (int i = 0; i < algo->get_edge_collection()->get_len(); i++)
	{
		if (algo->get_MST()[i] == true)
		{
			e = algo->get_edge_collection()->get_edges()[i];
			std::cout << e.get_start_vertex_id() << "-" << e.get_end_vertex_id() << ":" << e.get_weight() << std::endl;
		}
	}*/

	/*Dijkstra* algo = new Dijkstra(g);
	algo->run(g, 0);*/
	//for (int i = 0; i < 6; i++) {
	//	std::cout << i << " d: " << algo->get_dijkstra_nodes()[algo->get_map()[i]].get_value() << " p : " << algo->get_p()[i] << std::endl;
	//}
	//BellmanFord* bellmanFord = new BellmanFord(g);
	//bellmanFord->run(g, 0);
	//for (int i = 0; i < 6; i++) {
	//	std::cout << i << " d: " << bellmanFord->get_d()[i] << " p : " << bellmanFord->get_p()[i] << std::endl;
	//}
	/*GraphAdjacencyList g = GraphAdjacencyList(r);
	g.show_graph();
	
	std::cout << "############################" << std::endl;
	algo->run(g, 1);
	for (int i = 0; i < 6; i++) {
		std::cout << i << " d: " << algo->get_dijkstra_nodes()[algo->get_map()[i]].get_dist() << " p : " << algo->get_p()[i] << std::endl;
	}*/
}