// quicksort algorithm
// 
// A quicksort algorithm - its time complexity is O(n^2).
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/02: Testing added, updated c++11 and documented
// 2021/01/20: partition_lo() partition_hi() added 
//             now, the pivot can be either the first or the last element.
// 2021/01/20: comparator default argument added 
// 
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 quick.cpp -o quick
// > ./quick
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG quick.cpp -o quick
// > ./quick
//
// To add this function to a static library libsort.a, 
// 1. set #if 0 to deactivate main() function at the bottom of the file first. 
// 2. compile first to produce ~.o file. 
// 3. add it to libsort.a as shown below.
// > g++ -std=c++11 -c quick.cpp         	# produce quick.o
// > ar r libsort.a quick.o              	# insert or update quick.o in libsort.a
// > ar t libsort.a                         # show objects in libsort.a 

#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// This function takes last element as pivot, places the pivot element at its
// correct position in sorted array, and places all smaller (smaller than pivot)
// to left of pivot and all greater elements to right of pivot */
int partition(int list[], int lo, int hi) {
	DPRINT(cout << "partition pivot:" << list[hi] << " ";);
	int pivot = list[hi];	// pivot value
	int i = (lo - 1);  		// Index of smaller element

	for (int j = lo; j <= hi - 1; j++) {
		if (list[j] <= pivot) { 			// if current element is <= pivot
			i++;    						// increment index of smaller element
			swap(list[j], list[i]);  		// swap current element with index
		}
	}
	swap(list[hi], list[i + 1]);
	DPRINT(cout << ".... is now in place at list[" << i + 1 << "]\n";);
	return (i + 1);  // returns the new pivot index which it is now in place or sorted.
}

// quicksort helper function for recursive operation
// list[]: array to be sorted, lo: Starting index, h: Ending index
// N is added only for debugging or DPRINT
void quicksort(int *list, int lo, int hi, int n) {
	if (lo < hi) 	{
		int pi = partition(list, lo, hi); // pi: pivot index	
		DPRINT(cout << "\npivot(" << pi << ")=" << list[pi] << "   LEFT\n";);
		quicksort(list, lo, pi - 1, n);

		DPRINT(cout << "\npivot(" << pi << ")=" << list[pi] << "   RIGHT\n";);
		quicksort(list, pi + 1, hi, n);
	}
}

void quicksort(int *a, int n) {
	DPRINT(cout << "QUICK SORTING...\n");
	quicksort(a, 0, n - 1, n);  // the last argument n is added only for DPRINT()
}

#if 1

int main() {
	int list[] = { 54, 26, 93, 17, 77, 31, 44, 55, 20 };
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl << endl;

	quicksort(list, N);
	cout << "QUICK SORTED: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl << endl;

    // Uncomment the next line and modify the code above to make it work. 
	// quicksort(list, N, more);
	cout << "QUICK SORTED using more fp: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl << endl;

	cout << "Happy Coding~~";
	return 0;
}
#endif
