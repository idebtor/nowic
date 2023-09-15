// quicksort algorithm
// 
// A quicksort algorithm - its time complexity is O(n^2).
// Created by idebtor@gmail.com
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
  DPRINT(cout << "partition pivot:" << list[hi] << "\n";);
  int pivot = list[hi];	     // pivot value
  int i = (lo - 1);  	     // smaller element index
  for (int j = lo; j <= hi - 1; j++) {
    if (list[j] <= pivot) {  // left side <= pivot
      i++;                   // smaller element index
      swap(list[j], list[i]);// swap two 
    }
  }
  swap(list[hi], list[i + 1]);
  return (i + 1);           // returns the new pivot index.
}

// quicksort helper function for recursive operation
// list[]: array to be sorted, lo: Starting index, h: Ending index
void quicksort(int *list, int lo, int hi) {
  if (lo < hi) {
    int pi = partition(list, lo, hi); // pi: pivot index	
    DPRINT(cout<<"  l pivot(" <<pi<<")="<<list[pi]<<"\n";);
    quicksort(list, lo, pi - 1);
    DPRINT(cout<<"  r pivot("<< pi<<")="<<list[pi]<<"\n";);
    quicksort(list, pi + 1, hi);
  }
}

void quicksort(int *a, int n) {
	quicksort(a, 0, n - 1);  
}

void quicksort(int *list, int n, bool (*comp)(int x, int y)) {
    cout << "your code here\n"; 
}

#if 0
// two comparator functions 
// The value returned indicates whether the element passed as first argument
// is considered to go before the second in the specific ordering.
// more() and less() are equivalent to greater<int>() and less<int>() in STL. 
bool more(int x, int y) { return x > y; }   // for descending order
bool less(int x, int y) { return x < y; }   // for ascending order 

// void quicksort(int *a, int n, bool (*comp)(int, int) = ::less);

int main() {
	int list[] = { 54, 26, 93, 17, 77, 31, 44, 55, 20 };
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: \n";
	for (auto x: list) cout << x << "  ";  
  cout << endl << endl;

	quicksort(list, N);
	cout << "QUICK SORTED: \n";
	for (auto x: list) cout << x << "  ";  
  cout << endl << endl;

	cout << "Decreasing order using fp: \n";
  quicksort(list, N, more);
	for (auto x: list) cout << x << "  "; 
	cout << endl << endl;

	cout << "Happy Coding~~";
	return 0;
}
#endif
