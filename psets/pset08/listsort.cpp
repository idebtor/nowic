// quicksort.cpp by idebtor@gmail.com
// A typical recursive implementation of quick sort
// 2018.12.15

#include <iostream>
#include "listdbl.h"
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// This function takes last element as pivot, places the pivot element at its
// correct position in sorted array, and places all smaller (smaller than pivot)
// to left of pivot and all greater elements to right of pivot 
pNode partition(pNode lo, pNode hi, int(*comp)(int, int) = ascending) {
	int x = hi->data;     // set pivot as hi value
	pNode i = lo->prev;   // Index of smaller element

	for (pNode j = lo; j != hi; j = j->next) {
		// If current element is smaller than or equal to pivot
		if (comp(x, j->data) > 0) {
			i = (i == nullptr) ? lo : i->next;    // increment index of smaller element
			std::swap(i->data, j->data);          // Swap current element with index
		}
	}
	i = (i == nullptr) ? lo : i->next;
	std::swap(i->data, hi->data);
	return i;
}

// quickSort helper function for recursive operation
// list[]: array to be sorted, lo: Starting index, h: Ending index
// N is added only for debugging or DPRINT
void quickSort(pNode lo, pNode hi, int(*comp)(int, int) = ascending) {
	if (lo != nullptr && lo != hi && lo != hi->next) {
		pNode p = partition(lo, hi, comp); // Partitioning index
		quickSort(lo, p->prev, comp);
		quickSort(p->next, hi, comp);
	}
}

void quickSort(pList head, int(*comp)(int, int)) {
	quickSort(begin(head), last(head), comp);
}

void bubbleSort(pList p, int(*comp)(int, int)) {
	bool swapped = true;
	DPRINT(cout << ">bubbleSort N=" << size(p) << endl;);
	if (sorted(p)) return reverse(p);

	pNode tail = end(p);
	pNode curr;
	for (pNode i = begin(p); i != end(p) && swapped; i = i->next) {
		swapped = false;
		for (curr = begin(p); curr->next != tail; curr = curr->next) {
			if (comp(curr->data, curr->next->data) > 0) {
				swap(curr->data, curr->next->data);
				swapped = true;
			}
		}
		DPRINT(show(p, false););
		tail = curr;
	}
	DPRINT(cout << "<bubbleSort N=" << size(p) << endl;);
}

void bubbleSort2(pList p, int(*comp)(int, int)) {
	bool swapped;
	DPRINT(cout << ">bubleSort2 N=" << size(p) << endl;);
	if (sorted(p)) return reverse(p);

	pNode tail = end(p);
	do {
		swapped = false;
		pNode curr = begin(p);
		while (curr->next != tail) {
			if (comp(curr->data, curr->next->data) > 0) {
				swap(curr->data, curr->next->data);
				swapped = true;
			}
			curr = curr->next;
		}
		DPRINT(show(p, false););
		tail = curr;
	} while (swapped);
	DPRINT(cout << "<bubbleSort N=" << size(p) << endl;);
}

void insertionSort(pList p, int(*comp)(int, int)) {
	DPRINT(cout << ">insertionSort N=" << size(p) << endl;);

	cout << "your code here\n";

	DPRINT(cout << "<insertionSort N=" << size(p) << endl;);
}

void selectionSort(pList p, int(*comp)(int, int)) {
	DPRINT(cout << ">selectionSort N=" << size(p) << endl;);

	cout << "your code here\n";

	DPRINT(cout << "<selctionSort N=" << size(p) << endl;);
}

