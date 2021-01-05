// quicksort algorithm
// 
// A quicksort algorithm - its time complexity is O(n^2).
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/02: Testing added, updated c++11 and documented
//
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 quicksort.cpp -o quicksort
// > ./quicksort
//
// To test and use DEBUG, 
// Set #if 1 to activate main() function at the bottom of the file first. 
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG quicksort.cpp -o quicksort
// > ./quicksort
// 
// To add it a static library, compile first and add it to the library
// Set #if 0 to deactivate main() function at the bottom of the file first. 
// > g++ -std=c++11 -c quicksort.cpp      # produce quicksort.o
// > ar r libsort.a quicksort.o           # insert or update quicksort.o in libsort.a
// > ar t libsort.a                       # list objects in libsort.a 
//

#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int ascending(int a, int b) { return a - b; };
int descending(int a, int b) { return b - a; };

// This function takes last element as pivot, places the pivot element at its
// correct position in sorted array, and places all smaller (smaller than pivot)
// to left of pivot and all greater elements to right of pivot.
int partition(int list[], int lo, int hi, int(*comp)(int, int)) {
	int x = list[hi];  // pivot
	int i = (lo - 1);  // Index of smaller element

	for (int j = lo; j <= hi - 1; j++) {
		// If current element is smaller than or equal to pivot
		if (comp(x, list[j]) > 0) {
			i++;                          // increment index of smaller element
			std::swap(list[i], list[j]);  // swap current element with index
		}
	}
	std::swap(list[i + 1], list[hi]);
	return (i + 1);
}

// quicksort helper function for recursive operation
// list[]: array to be sorted, lo: starting index, h: ending index
// N is added only for debugging or DPRINT
void quicksort(int *list, int lo, int hi, int N, int(*comp)(int, int)) {
	if (lo < hi) 	{
		int pi = partition(list, lo, hi, comp); // Partitioning index
		DPRINT(for (int x = 0; x < N; x++) cout << list[x] << " "; cout << endl;);
		quicksort(list, lo, pi - 1, N, comp);
		quicksort(list, pi + 1, hi, N, comp);
	}
}

void quicksort(int *a, int n) {
	DPRINT(cout << "quicksort\n");
	quicksort(a, 0, n - 1, n, ascending);
}

void quicksort(int *a, int n, int(*comp)(int, int)) {
	DPRINT(cout << "quicksort\n");
	quicksort(a, 0, n - 1, n, comp);
}

#if 0
int main() {
	int list[] = { 7, 3, 4, 1, 9, 6, 5, 2, 8, 0 };
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (auto x: list) cout << x << "  ";

	quicksort(list, N);
	cout << "\nQUICKSORTED: " << endl;
	for (auto x: list) cout << x << "  ";

	quicksort(list, N, descending);
	cout << "\nQUICKSORTED: descending " << endl;
	for (auto x: list) cout << x << "  ";
}
#endif
