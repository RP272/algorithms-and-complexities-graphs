#ifndef NEIGHBORITERATOR_H
#define NEIGHBORITERATOR_H

class NeighborIterator
{
public:
	virtual int getNext() = 0;
	virtual bool hasMore() = 0;
};

#endif