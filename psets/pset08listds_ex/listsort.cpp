// quicksort.cpp by idebtor@gmail.com
// A typical recursive implementation of quick sort
// 2018.12.15

#include <iostream>
#include "listds.h"
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
	int x = hi->item;     // set pivot as hi value
	pNode i = lo->prev;   // Index of smaller element

	for (pNode j = lo; j != hi; j = j->next) {
		// If current element is smaller than or equal to pivot
		if (comp(x, j->item) > 0) {
			i = (i == nullptr) ? lo : i->next;    // increment index of smaller element
			std::swap(i->item, j->item);          // Swap current element with index
		}
	}
	i = (i == nullptr) ? lo : i->next;
	std::swap(i->item, hi->item);
	return i;
}

// quickSort helper function for recursive operation
// list[]: array to be sorted, lo: Starting index, h: Ending index
// N is added only for debugging or DPRINT
void _quickSort(pNode lo, pNode hi, int(*comp)(int, int) = ascending) {
	if (lo != nullptr && lo != hi && lo != hi->next) {
		pNode p = partition(lo, hi, comp); // Partitioning index
		_quickSort(lo, p->prev, comp);
		_quickSort(p->next, hi, comp);
	}
}

void quickSort(pList head, int(*comp)(int, int)) {
	_quickSort(begin(head), last(head), comp);
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
			if (comp(curr->item, curr->next->item) > 0) {
				swap(curr->item, curr->next->item);
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
			if (comp(curr->item, curr->next->item) > 0) {
				swap(curr->item, curr->next->item);
				swapped = true;
			}
			curr = curr->next;
		}
		DPRINT(show(p, false););
		tail = curr;
	} while (swapped);
	DPRINT(cout << "<bubbleSort N=" << size(p) << endl;);
}

void selectionSort(pList p, int(*comp)(int, int)) {
	DPRINT(cout << ">selectionSort N=" << size(p) << endl;);

	cout << "your code here\n";

	DPRINT(cout << "<selctionSort N=" << size(p) << endl;);
}

/** for your reference 
void selectionSort(int *list, int n) {
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		// Swap min found with the first one of unsorted
		swap(list[i], list[min]);
		DPRINT(for (int x = 0; x < n; x++) cout << list[x] << " "; cout << endl;);
	}
}
*/

