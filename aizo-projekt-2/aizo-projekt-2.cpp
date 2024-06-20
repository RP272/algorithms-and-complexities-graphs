// aizo-projekt-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <fstream>
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
	int number_of_vertices, density, starting_vertex, end_vertex;
	std::string filename;
	GraphCollection* graph_collection = new GraphCollection(10, 0, false);
	GraphFromFile* r;
	while (main_menu != 4)
	{
		sub_menu = 0;
		std::cout << std::endl;
		std::cout << "1. Minimalne drzewo rozpinajace" << std::endl;
		std::cout << "2. Najkrotsza sciezka w grafie" << std::endl;
		std::cout << "3. Testy" << std::endl;
		std::cout << "4. Zakoncz program" << std::endl;
		std::cout << "Wybierz problem do rozwiazania: ";
		while (!(std::cin >> main_menu) || main_menu < 1 || main_menu > 4) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Niewlasciwy wybor. Wprowadz ponownie: ";
		}
		while (sub_menu != 8 && main_menu != 4)
		{
			std::cout << std::endl;
			std::cout << "1. Wczytaj dane z pliku." << std::endl;
			std::cout << "2. Wygeneruj graf losowo." << std::endl;
			std::cout << "3. Wyswietl graf listowo i macierzowo na ekranie." << std::endl;
			if (main_menu == 1)
			{
				std::cout << "4. Algorytm Prima listowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "5. Algorytm Prima macierzowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "6. Algorytm Kruskala listowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "7. Algorytm Kruskala macierzowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "8. Powrot do glownego menu." << std::endl;
				std::cout << "Wybierz opcje z menu: ";
				while (!(std::cin >> sub_menu) || sub_menu < 1 || sub_menu > 8) {
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
					int vertices_len = graph_collection->get_adjacency_list()->get_vertices_len();
					if (starting_vertex < 0 || starting_vertex >= vertices_len) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					Prim* prim = new Prim(*graph_collection->get_adjacency_list());
					prim->run(*graph_collection->get_adjacency_list(), starting_vertex);
					prim->show_mst(vertices_len);
				}
				break;
				case 5:
				{
					std::cout << "Podaj wierzcholek startowy: ";
					std::cin >> starting_vertex;
					int vertices_len = graph_collection->get_adjacency_list()->get_vertices_len();
					if (starting_vertex < 0 || starting_vertex >= vertices_len) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					Prim* prim = new Prim(*graph_collection->get_incidence_matrix());
					prim->run(*graph_collection->get_adjacency_list(), starting_vertex);
					prim->show_mst(vertices_len);
					break;
				}
				case 6:
				{
					Kruskal* kruskal = new Kruskal(*graph_collection->get_adjacency_list());
					kruskal->run(*graph_collection->get_adjacency_list());
					kruskal->show_mst();
				}
				case 7:
				{
					Kruskal* kruskal = new Kruskal(*graph_collection->get_incidence_matrix());
					kruskal->run(*graph_collection->get_adjacency_list());
					kruskal->show_mst();
				}
				break;
				case 8:
					break;
				}
			}
			else if (main_menu == 2)
			{
				std::cout << "4. Algorytm Dijkstry listowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "5. Algorytm Dijkstry macierzowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "6. Algorytm Bellmana-Forda listowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "7. Algorytm Bellmana-Forda macierzowo z wyswietlaniem wynikow." << std::endl;
				std::cout << "8. Powrot do glownego menu." << std::endl;
				std::cout << "Wybierz opcje z menu: ";
				while (!(std::cin >> sub_menu) || sub_menu < 1 || sub_menu > 8) {
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
					graph_collection = new GraphCollection(r, true);
					std::cout << "Graf zostal zapisany w pamieci." << std::endl;
				}
				break;
				case 2:
				{
					std::cout << "Podaj ilosc wierzcholkow: ";
					std::cin >> number_of_vertices;
					std::cout << std::endl << "Podaj gestosc grafu: ";
					std::cin >> density;
					graph_collection = new GraphCollection(number_of_vertices, density, true);
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
					std::cout.flush();
					std::cout << "Podaj wierzcholek koncowy: ";
					std::cin >> end_vertex;
					if (end_vertex < 0 || end_vertex >= graph_collection->get_adjacency_list()->get_vertices_len()) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					Dijkstra* dijkstra = new Dijkstra(*graph_collection->get_adjacency_list());
					dijkstra->run(*graph_collection->get_adjacency_list(), starting_vertex);
					dijkstra->show_path(starting_vertex, end_vertex);
				}
				break;
				case 5:
				{
					std::cout << "Podaj wierzcholek startowy: ";
					std::cin >> starting_vertex;
					if (starting_vertex < 0 || starting_vertex >= graph_collection->get_incidence_matrix()->get_vertices_len()) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					std::cout.flush();
					std::cout << "Podaj wierzcholek koncowy: ";
					std::cin >> end_vertex;
					if (end_vertex < 0 || end_vertex >= graph_collection->get_incidence_matrix()->get_vertices_len()) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					Dijkstra* dijkstra = new Dijkstra(*graph_collection->get_incidence_matrix());
					dijkstra->run(*graph_collection->get_incidence_matrix(), starting_vertex);
					dijkstra->show_path(starting_vertex, end_vertex);
				}
				break;
				case 6:
				{
					std::cout << "Podaj wierzcholek startowy: ";
					std::cin >> starting_vertex;
					if (starting_vertex < 0 || starting_vertex >= graph_collection->get_incidence_matrix()->get_vertices_len()) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					std::cout << "Podaj wierzcholek koncowy: ";
					std::cin >> end_vertex;
					if (end_vertex < 0 || end_vertex >= graph_collection->get_incidence_matrix()->get_vertices_len()) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					BellmanFord* bellmanFord = new BellmanFord(*graph_collection->get_adjacency_list());
					bellmanFord->run(*graph_collection->get_adjacency_list(), starting_vertex);
					bellmanFord->show_path(starting_vertex, end_vertex);
				}
				break;
				case 7:
				{
					std::cout << "Podaj wierzcholek startowy: ";
					std::cin >> starting_vertex;
					if (starting_vertex < 0 || starting_vertex >= graph_collection->get_adjacency_list()->get_vertices_len()) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					std::cout << "Podaj wierzcholek koncowy: ";
					std::cin >> end_vertex;
					if (end_vertex < 0 || end_vertex >= graph_collection->get_adjacency_list()->get_vertices_len()) {
						std::cout << "Numer wierzcholka poza zakresem." << std::endl;
						break;
					}
					BellmanFord* bellmanFord = new BellmanFord(*graph_collection->get_incidence_matrix());
					bellmanFord->run(*graph_collection->get_incidence_matrix(), starting_vertex);
					bellmanFord->show_path(starting_vertex, end_vertex);
				}
				break;
				case 8:
					break;
				}
			}
			else if (main_menu == 3)
			{
				// Testowanie
				std::ofstream MyFile("wyniki.txt");
				float prim_adj_sum, prim_inc_sum, kruskal_adj_sum, kruskal_inc_sum, dijkstra_adj_sum, dijkstra_inc_sum, bellman_adj_sum, bellman_inc_sum;
				std::chrono::high_resolution_clock::time_point t1, t2;
				std::chrono::duration<float, std::micro> adjacency;
				std::chrono::duration<float, std::micro> incidence;
				int sizes[7] = { 25, 50, 75, 100, 125, 150, 175 };
				int densities[3] = { 25, 50, 99 };
				for (int i = 0; i < 7; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						prim_adj_sum = 0.0;
						prim_inc_sum = 0.0;
						kruskal_adj_sum = 0.0;
						kruskal_inc_sum = 0.0;
						dijkstra_adj_sum = 0.0;
						dijkstra_inc_sum = 0.0;
						bellman_adj_sum = 0.0;
						bellman_inc_sum = 0.0;
						MyFile << sizes[i] << " " << densities[j] << std::endl;
						for (int n = 0; n < 50; n++)
						{
							std::cout << i << " " << j << " " << n << std::endl;
							graph_collection = new GraphCollection(sizes[i], densities[j], false);
							Prim* prim = new Prim(*graph_collection->get_adjacency_list());
							t1 = std::chrono::high_resolution_clock::now();
							prim->run(*graph_collection->get_adjacency_list(), 0);
							t2 = std::chrono::high_resolution_clock::now();
							adjacency = t2 - t1;
							prim_adj_sum += adjacency.count();
							delete prim;
							
							prim = new Prim(*graph_collection->get_incidence_matrix());
							t1 = std::chrono::high_resolution_clock::now();
							prim->run(*graph_collection->get_incidence_matrix(), 0);
							t2 = std::chrono::high_resolution_clock::now();
							incidence = t2 - t1;
							prim_inc_sum += incidence.count();
							delete prim;

							Kruskal* kruskal = new Kruskal(*graph_collection->get_adjacency_list());
							t1 = std::chrono::high_resolution_clock::now();
							kruskal->run(*graph_collection->get_adjacency_list());
							t2 = std::chrono::high_resolution_clock::now();
							adjacency = t2 - t1;
							kruskal_adj_sum += adjacency.count();
							delete kruskal;

							kruskal = new Kruskal(*graph_collection->get_incidence_matrix());
							t1 = std::chrono::high_resolution_clock::now();
							kruskal->run(*graph_collection->get_incidence_matrix());
							t2 = std::chrono::high_resolution_clock::now();
							incidence = t2 - t1;
							kruskal_inc_sum += incidence.count();
							delete kruskal;
							delete graph_collection;

							graph_collection = new GraphCollection(sizes[i], densities[j], true);
							Dijkstra* dijkstra = new Dijkstra(*graph_collection->get_adjacency_list());
							t1 = std::chrono::high_resolution_clock::now();
							dijkstra->run(*graph_collection->get_adjacency_list(), 0);
							t2 = std::chrono::high_resolution_clock::now();
							adjacency = t2 - t1;
							dijkstra_adj_sum += adjacency.count();
							delete dijkstra;

							dijkstra = new Dijkstra(*graph_collection->get_incidence_matrix());
							t1 = std::chrono::high_resolution_clock::now();
							dijkstra->run(*graph_collection->get_incidence_matrix(), 0);
							t2 = std::chrono::high_resolution_clock::now();
							incidence = t2 - t1;
							dijkstra_inc_sum += incidence.count();
							delete dijkstra;

							BellmanFord* bellman_ford = new BellmanFord(*graph_collection->get_adjacency_list());
							t1 = std::chrono::high_resolution_clock::now();
							bellman_ford->run(*graph_collection->get_adjacency_list(), 0);
							t2 = std::chrono::high_resolution_clock::now();
							adjacency = t2 - t1;
							bellman_adj_sum += adjacency.count();
							delete bellman_ford;

							bellman_ford = new BellmanFord(*graph_collection->get_incidence_matrix());
							t1 = std::chrono::high_resolution_clock::now();
							bellman_ford->run(*graph_collection->get_incidence_matrix(), 0);
							t2 = std::chrono::high_resolution_clock::now();
							incidence = t2 - t1;
							bellman_inc_sum += incidence.count();
							delete bellman_ford;
							delete graph_collection;
						}
						MyFile << prim_adj_sum/50.0 << "," << prim_inc_sum/50.0 << std::endl;
						MyFile << kruskal_adj_sum/50.0 << "," << kruskal_inc_sum/50.0 << std::endl;
						MyFile << dijkstra_adj_sum/50.0 << "," << dijkstra_inc_sum/50.0 << std::endl;
						MyFile << bellman_adj_sum/50.0 << "," << bellman_inc_sum/50.0 << std::endl;
					}
				}
				main_menu = 4;
				MyFile.close();
			}
		}
	}
}