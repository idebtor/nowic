// quicksort.cpp by idebtor@gmail.com
// A typical recursive implementation of quick sort
// 2018.12.15

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// A utility function to swap two elements
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places the pivot element at its
correct position in sorted array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right of pivot */
int partition(int list[], int lo, int hi) {
	int x = list[hi];  // pivot
	int i = (lo - 1);  // Index of smaller element

	for (int j = lo; j <= hi - 1; j++) {
		// If current element is smaller than or equal to pivot
		if (list[j] <= x) {
			i++;    // increment index of smaller element
			swap(&list[i], &list[j]);  // Swap current element with index
		}
	}
	swap(&list[i + 1], &list[hi]);
	return (i + 1);
}

// QuickSort helper function for recursive operation
// list[]: array to be sorted, lo: Starting index, h: Ending index
// N is added only for debugging or DPRINT
void _quickSort(int *list, int lo, int hi, int N) {
	if (lo < hi) 	{
		int pi = partition(list, lo, hi); // Partitioning index
		DPRINT(for (int x = 0; x < N; x++) printf("%d ", list[x]); printf("\n");)
		_quickSort(list, lo, pi - 1, N);
		_quickSort(list, pi + 1, hi, N);
	}
}

void quickSort(int *a, int n) {
	_quickSort(a, 0, n - 1, n);  // the last argument n is added only for DPRINT()
}

#if 0
int main() {
	int list[] = { 7, 3, 4, 1, 9, 6, 5, 2, 8, 0 };
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	quickSort(list, N);

	cout << "SORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	system("pause");
}
#endif
