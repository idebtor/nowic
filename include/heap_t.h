/*
* Files: heap_t.cpp, heap_t.h, heap_tDriver.cpp, heap_tprint.cpp, treeprint_t.cpp
*  implements a max/min heap that is used to represent a priority queue.
*
*  It supports the usual insert and delete - the - maximum operations,
*  along with methods for peeking at the maximum key, testing if the
*  heap is empty, and iterating through the keys. It uses an array
*  structure to store in a complete binary tree structure.
*  The insert and delete - the - maximum operations take logarithmic
*  amortized time.The max, capa, and empty operations take
*  constant time.
*
*  Heap construction takes time proportional to the specified capacity
*  or the number of items used to initialize the data structure.
*  It uses successive doulbing to increase the memory as the number
*  of nodes increases. Similarly, it deallocates its memory dynamically
*  as the nodes get removed. A one - based and one dimensional array
*  is used to simplify parent and child calculations.
*
*  @author Youngsup Kim, idebtor@gmail.com
*  2014/04/01	Creation
*  2016/05/05	Added heapprint(), treeprint(), growN, trimN()
*  2016/11/15	command-line arguments available for initial heap
*  2016/11/20	use function pointer to handle minheap and maxheap
*/
#ifndef HEAPT_H
#define HEAPT_H

#include <vector>
#include "nowic.h"

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

template <class T>
struct Heap {							// heap or min/max priority queue
	vector<int> nodes[;					// an array of nodes

	bool (*comp)(Heap<T>*, int, int);   // less() for maxheap, more() for minheap
	bool intType;						// true if T is int

	Heap<T>(bool dataType = true) {
		nodes.push_back(0);
		comp = nullptr;
		intType = dataType;
	};

	~Heap<T>() {};
};
template <typename T> using heap = Heap<T>*;

template <typename T> void setHeapType(heap<T>, bool maxType);  // maxheap or minheap
template <typename T> void clear(heap<T> p);                // deallocate heap
template <typename T> int size(heap<T> p);					// returns number of nodes in heap
template <typename T> int capacity(heap<T> p);				// returns the heap capacity
template <typename T> int height(heap<T> p);				// returns height of heap 
                      int height(int n);					// returns height based on num of nodes
template <typename T> T minimum(heap<T> p);			        // returns min key in CBT or maxheap
template <typename T> T maximum(heap<T> p);	                // returns max key in CBT or maxheap
template <typename T> void reserve(heap<T> p, int capa);	// reserves the array size (= capacity)
template <typename T> bool empty(heap<T> p);			 	// returns true/false
template <typename T> void grow(heap<T> p, T key);		    // inserts key in heap
template <typename T> void trim(heap<T> p);					// deletes root in heap

template <typename T> void replace(heap<T> p, T o, T n);    // replace a key with a new key
template <typename T> void growN(heap<T> p, int n, bool o);	// insert n number of nodes
template <typename T> void trimN(heap<T> p, int n, bool o);	// remove n number of nodes

template <typename T> void swap(heap<T> p, int i, int j);	// swaps two nodes
template <typename T> void swim(heap<T> p, int k);			// bubbles up
template <typename T> void sink(heap<T> p, int k);			// tickles down
template <typename T> bool less(heap<T> p, int i, int j);	// for maxheap
template <typename T> bool more(heap<T> p, int i, int j);	// for minheap

template <typename T> bool heapOrderedAt(heap<T> p, int k); // is heap-ordered at node k?
template <typename T> bool heapOrdered(heap<T> p);			// is heap-ordered?
template <typename T> void heapsort(heap<T> p);				// sorts heap data structure
template <typename T> void heapify(heap<T> p);				// converts a CBT into a heap

template <typename T> heap<T> newCBT(T *a, int size);		// makes a complete binary tree
template <typename T> void growCBT(heap<T> p, T key);		// grows a node next to the last
template <typename T> void trimCBT(heap<T> p);				// trims a node at the last

template <typename T> void heapprint(heap<T> p);
template <typename T> void heapprint_level(heap<T> p);
#endif