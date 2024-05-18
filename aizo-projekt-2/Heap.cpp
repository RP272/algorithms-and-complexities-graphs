#include "Heap.h"
#include "DijkstraVertex.h"
#include "PrimaVertex.h"

template <typename T> MinHeap<T>::MinHeap(T* tab, int tab_len)
{
	for (int i = (tab_len - 2) / 2; i >= 0; --i) {
		heap_fix_down(tab, i, tab_len);
	}
}

template <typename T> void MinHeap<T>::heap_fix_down(T* tab, int index, int n)
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
		this->swap(tab, minimum, index);
		heap_fix_down(tab, minimum, n);
	}
}

template <typename T> void MinHeap<T>::swap(T* tab, int a, int b)
{
	T tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

template <typename T> int MinHeap<T>::get_len()
{
	return this->len;
}

template class MinHeap<DijkstraVertex>; 
template class MinHeap<PrimaVertex>;