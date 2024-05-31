#include "EdgeCollection.h"

EdgeCollection::EdgeCollection(Edge* edges, int len)
{
	this->edges = edges;
	this->len = len;
}

Edge* EdgeCollection::get_edges()
{
	return this->edges;
}

int EdgeCollection::get_len()
{
	return this->len;
}

void EdgeCollection::quicksort(int l, int p) 
{
	if (l >= p) return;
	int m = partition(l, p);
	quicksort(l, m);
	quicksort(m + 1, p);
}

int EdgeCollection::partition(int left, int right)
{
	int pivot = this->edges[int((left + right) / 2)].get_weight();
	int l = left;
	int r = right;
	Edge tmp;
	while (true) {
		while (this->edges[l].get_weight() < pivot) ++l;
		while (this->edges[r].get_weight() > pivot) --r;
		if (l < r) {
			tmp = this->edges[l];
			this->edges[l] = this->edges[r];
			this->edges[r] = tmp;
			++l;
			--r;
		}
		else {
			if (r == right) r--;
			return r;
		}
	}
}