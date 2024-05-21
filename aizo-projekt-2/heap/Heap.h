#ifndef HEAP_H
#define HEAP_H
#include <unordered_map>
#include "HeapNode.h"

class MinHeap
{
private:
	int len;
public:
	MinHeap(HeapNode* tab, int tab_len, int* map);
	void heap_fix_down(HeapNode* tab, int index, int n, int* map);
	void heap_fix_up(HeapNode* tab, int index, int* map);
	void swap(HeapNode* tab, int a, int b, int* map);
	HeapNode extract_min(HeapNode* tab, int* map);
	void change_key(HeapNode* tab, int key, int new_value, int* map);
	int get_len();
};

#endif