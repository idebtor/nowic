/*
* Files: heap.cpp, heap.h, heapDriver.cpp, heapprint.cpp, treeprint.cpp
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
*  author: idebtor@gmail.com
*/
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "nowic.h"

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

enum showEnum { TREE_MODE, LEVEL_MODE, TASTY_MODE };

struct Heap {							// heap or min/max priority queue
	int *nodes;							// an array of nodes
	int capacity;						// array size of node
	int N;								// number of nodes in the heap
	bool (*comp)(Heap*, int, int);  	// less() for maxheap, more() for minheap

	Heap(int capa = 2) {
		capacity = capa;
		nodes = (int *)malloc(capa * sizeof(int)); // works with realloc() & free()
		//nodes = new int[capacity]; // unsafe use with realloc() & free()        
		N = 0;
		comp = nullptr;					
	};
	~Heap() {};
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
void reserve(heap p, int capa);		// reserves the array size (= capacity)
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
bool less(heap p, int i, int j);	// for maxheap
bool more(heap p, int i, int j);	// for minheap

bool heapOrderedAt(heap p, int k);// is heap-ordered at node k?
bool heapOrdered(heap p);			// is heap-ordered?
void heapsort(heap p);				// sorts heap data structure
void heapify(heap p);				// converts a CBT into a heap

heap newCBT(int *a, int size);		// makes a complete binary tree
void growCBT(heap p, int key);		// grows a node next to the last
void trimCBT(heap p);				// trims a node at the last

void heapprint(heap p, int mode = TREE_MODE);   // prints heap using treeprint fucntions
///////////////// helper functions /////////////////////////////////////////
void show_vector(std::vector<int> vec, int show_n = 20);
void randomN(int start, int N, int *arr);
#endif