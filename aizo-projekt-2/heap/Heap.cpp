#include "Heap.h"

MinHeap::MinHeap(HeapNode* tab, int tab_len, int* map)
{
	this->len = tab_len;
	for (int i = (tab_len - 2) / 2; i >= 0; --i) {
		heap_fix_down(tab, i, tab_len, map);
	}
}

void MinHeap::heap_fix_down(HeapNode* tab, int index, int n, int* map)
{
	int l = 2 * index + 1;
	int r = 2 * index + 2;
	int minimum = index;
	if (l < n && tab[l].get_value() < tab[minimum].get_value()) {
		minimum = l;
	}
	if (r < n && tab[r].get_value() < tab[minimum].get_value()) {
		minimum = r;
	}
	if (minimum != index) {
		this->swap(tab, minimum, index, map);
		heap_fix_down(tab, minimum, n, map);
	}
}

void MinHeap::heap_fix_up(HeapNode* tab, int index, int* map)
{
	int p = (index - 1) / 2;
	if (index > 0 && tab[index].get_value() < tab[p].get_value())
	{
		this->swap(tab, index, p, map);
		heap_fix_up(tab, p, map);
	}
}

void MinHeap::swap(HeapNode* tab, int a, int b, int* map)
{
	HeapNode tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
	map[tab[a].get_vertex_id()] = a;
	map[tab[b].get_vertex_id()] = b;
}

HeapNode MinHeap::extract_min(HeapNode* tab, int* map)
{
	HeapNode min = tab[0];
	this->swap(tab, 0, this->len - 1, map);
	this->len--;
	this->heap_fix_down(tab, 0, this->len, map);
	return min;
}

void MinHeap::change_key(HeapNode* tab, int vertex_id, int new_value, int* map)
{
	int index_in_heap = map[vertex_id];
	tab[index_in_heap].set_value(new_value);
	heap_fix_up(tab, index_in_heap, map);
}

int MinHeap::get_len()
{
	return this->len;
}