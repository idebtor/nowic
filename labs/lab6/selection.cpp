// selection sort 
// The selection sort improves on the bubble sort by making only one exchange 
// for every pass through the list. In order to do this, a selection sort 
// looks for the largest value as it makes a pass and, after completing the 
// pass, places it in the proper location. As with a bubble sort, after the 
// first pass, the largest item is in the correct place. After the second pass, 
// the next largest is in place. This process continues and requires n−1 passes 
// to sort n items, since the final item must be in place after the (n−1)st pass.
// Its time complexity is O(n^2).
//
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/20: comparator default argument added 
// 
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 selection.cpp -o selection
// > ./selection
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG selection.cpp -o selection
// > ./selection
//
// To add this function to a static library libsort.a, 
// 1. set #if 0 to deactivate main() function at the bottom of the file first. 
// 2. compile first to produce ~.o file. 
// 3. add it to libsort.a as shown below.
// > g++ -std=c++11 -c selection.cpp         	# produce selection.o
// > ar r libsort.a selection.o              	# insert or update selection.o in libsort.a
// > ar t libsort.a                         	# show objects in libsort.a 

#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void selectionsort(int *list, int n) {
	DPRINT(cout << "selectionsort...\n");
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (list[j] < list[min]) 
				min = j;
		}
		swap(list[i], list[min]);
		DPRINT(for (int x = 0; x < n; x++) cout << list[x] << " "; cout << endl;);
	}
}

#if 1
// two comparator functions 
// The value returned indicates whether the element passed as first argument
// is considered to go before the second in the specific ordering.
// more() and less() are equivalent to greater<int>() and less<int>() in STL. 
bool more(int x, int y) { return x > y; }   // for descending order
bool less(int x, int y) { return x < y; }   // for ascending order 

int main() {
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl << endl;

	selectionsort(list, N);
	cout << "SELECTION SORTED: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl;

    // Uncomment the next line and modify the code above to make it work. 
    // selectionsort(list, N, more);   
	cout << "SELECTION SORTED using more fp: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl  << endl;

  	cout << "Happy Coding~~";
	return 0;
}
#endif
