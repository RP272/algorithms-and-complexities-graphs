#ifndef HEAP_HPP
#define HEAP_HPP

template <typename T>
class MinHeap
{
private:
	int len;
public:
	MinHeap(T* tab, int tab_len);
	void heap_fix_down(T* tab, int index, int n);
	void swap(T* tab, int idx1, int idx2);
	int get_len();
	//template <typename T> T extract_min();
};

#endif