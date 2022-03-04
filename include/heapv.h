/*
* Files: heapv.h, heapv.cpp, heapDriver.cpp, heapprint.cpp, treeprint.cpp
*  implements a heap ADT that is used to represent a priority queue.
*
*  It supports the usual insert and delete - the - maximum operations,
*  along with methods for peeking at the maximum key, testing if the
*  heap is empty, and iterating through the keys. It uses an array
*  structure to store in a complete binary tree structure.
*  The insert and delete - the - maximum operations take logarithmic
*  amortized time.The max, size, and empty operations take
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
*  2016/05/05	Added heapprint(), treeprint()
*  2016/11/11	simplified and growN, trimN()
*  2016/11/15	command-line arguments available for initial heap
*  2016/11/20	use function pointer to handle minheap and maxheap
*/
#ifndef HEAPV_H
#define HEAPV_H

#include <vector>
#include "nowic.h"
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

struct Heap {						// heap or min/max priority queue
	vector<int> nodes;				// an array of nodes
	int capacity;
	bool (*comp)(Heap*, int, int);  // less() for maxheap, more() for minheap

	Heap(int capa = 2) {
		nodes.reserve(capa);		
		nodes.push_back(999);		// the first node unused
		// heap size, N = nodes.size() - 1
		// N points the last node index		
		// insertion must be done at nodes[++N], 
		// deletion  must be done at nodes[N++]	
		capacity = capa;
		comp = nullptr;
	};
	~Heap() {
		cout << "\tAll things are cleared.\n";
	};
};
using heap = Heap *;

void setType(heap, bool max = true);// set maxheap as a default
void clear(heap p);					// deallocate heap
int size(heap p);					// returns number of nodes in heap
int capacity(heap p);				// returns the heap capacity
int height(heap p);					// returns height of heap 
int height(int n);					// returns height based on num of nodes
int minimum(heap p);				// returns min key in CBT or maxheap
int maximum(heap p);				// returns max key in CBT or maxheap
void reserve(heap p, int size);		// reserves the array size (= capacity)
bool full(heap p);					// returns true/false
bool empty(heap p);					// returns true/false

void grow(heap p, int key);			// inserts key in heap
void trim(heap p);					// deletes root in heap
int  contains(heap p, int key);		// returns key index, 0 otherwise
void replace(heap p, int o, int n); // replace a key with a new key
void growN(heap p, int n, bool o);	// insert n number of nodes
void trimN(heap p, int n, bool o);	// remove n number of nodes

void swap(heap p, int i, int j);	// swaps two nodes
void swim(heap p, int k);			// bubbles up
void sink(heap p, int k);			// tickles down
void sink(heap p, int k, int N);	// tickles down, used in heapsort
bool less(heap p, int i, int j);	// for maxheap
bool more(heap p, int i, int j);	// for minheap

bool heapOrderedAt(heap p, int k);// is heap-ordered at node k?
bool heapOrdered(heap p);			// is heap-ordered?
void heapsort(heap p);				// sorts heap data structure
void heapify(heap p);				// converts a CBT into a heap

heap newCBT(int *a, int size);		// makes a complete binary tree
void growCBT(heap p, int key);		// grows a node next to the last
void trimCBT(heap p);				// trims a node at the last
#endif