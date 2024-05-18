#include "Dijkstra.h"
#include "Heap.h"

Dijkstra::Dijkstra(Graph graph)
{
	this->vertex_array = new DijkstraVertex[graph.vertices_len];
	this->len = graph.vertices_len;
}

void Dijkstra::run(Graph graph, int starting_vertex)
{
	for (int i = 0; i < this->len; i++) {
		this->vertex_array[i].set_vertex_id(i);
		this->vertex_array[i].set_d(2147483647);
		this->vertex_array[i].set_p(-1);
	}
	this->vertex_array[starting_vertex].set_d(0);

	MinHeap<DijkstraVertex>* queue = new MinHeap<DijkstraVertex>(this->vertex_array, this->len);
	while (queue->get_len() > 0) {
		//DijkstraVertex u = queue->extract_min();
		
	}

};