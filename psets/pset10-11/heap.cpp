/*
* Files: heap.cpp, heap.h, driver.cpp - min/maxheap 
*  implements a max/min heap that is used to represent a priority queue.
*
*  It implements both max-heap and min-heap while swapping
*  the compare functions. The compare function for max-heap to use
*  is less() while more() is used for min-heap.
*  The heap structure carries this compare function as a function
*  pointer. It can be changed anytime, it can be re-evalaute the
*  heap and convert any binary tree or CBT into min-heap or max-heap.
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
*  author: idebtor@gmail.com
*/

#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include "heap.h"
using namespace std;

// sets the compare function less() for maxheap, more() for minheap.
void setType(heap p, bool maxType) {
	p->comp = maxType ? ::less : more;
}

// deallocates a heap.
void clear(heap p) {
	if (empty(p)) return;
	// delete[] p->nodes;
	free(p->nodes);
	return;
}

// returns the number of items in heap
int size(heap p) {
	return empty(p) ? 0 : p->N;
}

int capacity(heap p) {
	return p->capacity;
}
int height(int n) {
	cout << "your code here \n";
	return 0;
}
int height(heap p) {
	return height(size(p));
}

int minimum(heap p) {
	int key = p->nodes[1];
	for (int i = 2; i <= p->N; i++) {
		if (key > p->nodes[i]) key = p->nodes[i];
	}
	return key;
}

int maximum(heap p) {
	int key = p->nodes[1];

	for (int i = 2; i <= p->N; i++) {
		if (key < p->nodes[i]) key = p->nodes[i];
	}
	return key;
}

// resizes the node array in heap
void reserve(heap p, int capa) {
	DPRINT(cout << ">reserve old=" << p->capacity << "  new=" << capa << endl;);
	// realloc() : The contents of the block are unchanged up to the shorter
	// of the new and old sizes, although the new block can be in a different location.
	int *nodes = (int *)realloc(p->nodes, capa * sizeof(int));
	assert(nodes != nullptr);
	p->nodes = nodes;
	p->capacity = capa;
	DPRINT(cout << "<reserve capacity=" << capa << endl;);
}

// inserts a new key to the max-heap or min-heap.
void grow(heap p, int key) {
	DPRINT(cout << ">grow key=" << key << endl;);
	
	cout << "your code here\n";

	DPRINT(cout << "<grow N=" << p->N << endl;);
	return;
}

// removes the root key in maxheap or minheap.
void trim(heap p) {
	if (empty(p)) return;
	DPRINT(cout << ">trim\n";);

	cout << "your code here\n";

	DPRINT(cout << "<trim N=" << p->N << endl;);
}


// returns true(or index of the heap) if the key exists, false otherwise.
// In C/C++, 0 is treated as false, all other numbers treated as true.
int contains(heap p, int key) {
	if (empty(p)) return 0;

	cout << "your code here\n";

	return 0;
}

// replaces a key with a new key and keeps heap-ordered if it is a heap.
// if it is not a heap, simply replace a key with a new value.(CBT)
void replace(heap p, int oldKey, int newKey) {
	if (empty(p)) return;
	DPRINT(cout << ">replace " << oldKey << " --> " << newKey << endl;);

	bool heap_ordered = heapOrdered(p);
	for (int i = 1; i <= p->N; i++) {
		if (oldKey == p->nodes[i]) {
			p->nodes[i] = newKey;
			if (heap_ordered) {
				swim(p, i);
				sink(p, i);
			}
			break;
		}
	}
	DPRINT(cout << "<replace";);
}

// Is this heap empty?
bool empty(heap p) {
	return p == NULL || p->N == 0 ? true : false;
}

// is this heap full?
bool full(heap p) {
	return p && (p->N == p->capacity - 1) ? true : false;
}

/////// helper functions to restore the heap invariant ///////
bool more(heap p, int i, int j) {
	return p->nodes[i] > p->nodes[j];
}

bool less(heap p, int i, int j) {
	return p->nodes[i] < p->nodes[j];
}

void swap(heap p, int i, int j) {
	swap(p->nodes[i], p->nodes[j]);  // using std::swap()
}

void swim(heap p, int k) {
	DPRINT(cout << " swim key=" << p->nodes[k] << " k=" << k << " N=" << p->N << endl;);
	cout << "your code here\n";
}

void sink(heap p, int k) {
	DPRINT(cout << " sink key=" << p->nodes[k] << " k=" << k << " N=" << p->N << endl;);

	cout << "your code here\n";

#ifdef DEBUG
	cout << "\tafter sink N=" << p->N << " k=" << endl;
	for (k = 1; k <= p->N; k++)
		cout << p->nodes[k] << " ";
	cout << endl;
#endif
}

/*************************************************************************
*  Check integrity of heap data structure
*************************************************************************/

// is it heap-ordered at a node k? 
bool heapOrderedAt(heap p, int k) {
	if (k > p->N) return true; // check it upto the last internal node.

	int left  = 2 * k;
	int right = 2 * k + 1;

	if ((left  <= p->N) && p->comp(p, k, left))  return false;
	if ((right <= p->N) && p->comp(p, k, right)) return false;

	return heapOrderedAt(p, left) && heapOrderedAt(p, right);
}

// is it heap-ordered? 
bool heapOrdered(heap p) {
	if (empty(p)) return false;
	return heapOrderedAt(p, 1);
}

// sorts using min/maxheap
// if maxheap, it sorts them in ascending order
// if minheap, it sorts them in descending order
void heapsort(heap p) {
	DPRINT(cout << ">heapsort N=" << p->N << endl;);

	cout << "your code here\n";

	std::cout << "\n\tSorted: ";
	for (int i = 1; i <= p->N; i++)
		std::cout << p->nodes[i] << " ";
	std::cout << std::endl;
	DPRINT(cout << "<heapsort N=" << p->N << endl;);
}

/////////////////// Complete Binary Tree //////////////////////////
// instantiates a complete binary tree with given data and its size.
heap newCBT(int *a, int n) {
	DPRINT(cout << ">newCBT n=" << n << endl;);
	int capacity = (int) exp2((double)height(n) + 1);  // bug fixed: +1 
	heap p = new Heap{ capacity };
	p->N = n;
	for (int i = 0; i < n; i++)
		p->nodes[i + 1] = a[i];

	DPRINT(cout << "<newCBT " << endl;);
	return p;
}

// inserts a new key to the tree.
// if the size reaches the capacity, double the array size.
void growCBT(heap p, int key) {
	DPRINT(cout << ">growCBT key=" << key << endl;);

	cout << "your code here\n";

	DPRINT(cout << "<growCBT N=" << p->N << endl;);
}

// removes the last node on the heap
// if the size becomes 1/4 of the capacity, reserve it in half.
void trimCBT(heap p) {
	DPRINT(cout << ">trimCBT " << endl;);
	
	cout << "your code here\n";

	DPRINT(cout << "<trimCBT N=" << p->N << endl;);
}

// restores the max/min heap property -
// parent is larger/smaller than its children)
void heapify(heap p) {
	DPRINT(cout << ">heapify" << endl;);
	// start at the last internal node(or parent of the last node)
	// since leaf nodes already satisfy the max/min priority property
	// This is O(n) algorithm

	cout << "your code here\n";

	DPRINT(cout << "<heapify" << endl;);
}

// returns an extended random number of which the range is from 0
// to (RAND_MAX + 1)^2 - 1. // We do this since rand() returns too 
// small range [0..RAND_MAX) where RAND_MAX is usually defined as 
// 32767 in cstdlib. Refer to the following link for details
// https://stackoverflow.com/questions/9775313/extend-rand-max-range
unsigned long rand_extended(int range) {
	if (range < RAND_MAX) return rand();
	return rand() * RAND_MAX + rand();
}

// returns an int array that has randomly mixed numbers
// between start to start + N
void randomN(int start, int N, int* arr) {
	if (N <= 1) return;
	for (int i = 0; i < N; i++) arr[i] = start + i;
	// shuffle the array contents
	for (int i = 0; i < N; i++) {
		int x = rand_extended(N) % (N - 1);
		int t = arr[i];
		arr[i] = arr[x];
		arr[x] = t;
	}
#ifdef DEBUG
	cout << "randomN: ";
	for (int i = 0; i < N; i++) cout << arr[i] << " ";
	cout << endl;
#endif
}

// 1. Find the max key(max) in heap or CBT.
// 2. Set a function pointer to the function to insert a node
// 3. Allocate a Key type array such as keys to store random keys.
// 4. Invoke randomN() function to generate keys in the range
//    [(max + 1)..(max + count)]
// 5. Invoke the function to insert keys in keys[], but one key at a time.
// 6. Print the heap if DEBUG is defined whenever a node is inserted.
// 7. Don't forget freeing the array of keys you allocated in Step 3.
void growN(heap p, int count, bool heapOrdered) {
	DPRINT(cout << ">growN" << endl;);

	cout << "your code here\n";

	// int max = empty(p) ? 1 : maximum(p) + 1;
	// void(*insertFunc)(heap h, int key) = heapOrdered ? grow : growCBT;
	
	DPRINT(cout << "<growN" << endl;);
}

// 1. If the node count to delete is larger than the heap size,
//    set the node count to the heap size.
// 2. Set a function pointer to the function to delete a node
// 3. Invoke the function to delete the node one by one.
// (4. Print the heap if DEBUG is defined whenever a node is deleted.)
void trimN(heap p, int count, bool heapOrdered) {
	DPRINT(cout << ">trimN" << endl;);

	cout << "your code here\n";

	DPRINT(cout << "<trimN" << endl;);
}

///////////////////// helper functions /////////////////////////////////
// prints elements present in a vector in a line, show_n items per line 
void show_vector(vector<int> vec, int show_n) {
	int size = (int) vec.size();
	if (size < show_n)
		for (auto i : vec) cout << i << " ";
	else {
		for (int i = 0; i < show_n / 2; ++i)
			cout << vec[i] << " ";
		cout << "... ";
		for (int i = size - show_n / 2; i < size; ++i)
			cout << vec[i] << " ";
	}
}
