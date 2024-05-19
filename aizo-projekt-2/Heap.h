#ifndef HEAP_HPP
#define HEAP_HPP
#include <unordered_map>
#include "HeapNode.h"

class MinHeap
{
private:
	int len;
public:
	MinHeap(HeapNode* tab, int tab_len, std::unordered_map<int, int>& map);
	void heap_fix_down(HeapNode* tab, int index, int n, std::unordered_map<int, int>& map);
	void heap_fix_up(HeapNode* tab, int index, std::unordered_map<int, int>& map);
	void swap(HeapNode* tab, int a, int b, std::unordered_map<int, int>& map);
	HeapNode extract_min(HeapNode* tab, std::unordered_map<int, int>& map);
	void decrease_key(HeapNode* tab, int key, int subtract, std::unordered_map<int, int>& map);
	int get_len();
};

#endif