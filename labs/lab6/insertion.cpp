// insertion sort 
// It sorts an array of elements in order by comparing each element with the prior 
// elements and moving each element accordingly. It always maintains a sorted 
// sublist in the lower positions of the list. Each new item is then “inserted” 
// back into the previous sublist such that the sorted sublist is one item larger.
// We begin by assuming that a list with one item (position 0) is already sorted. 
// On each pass, one for each item 1 through n−1, the current item is checked 
// against those in the already sorted sublist. As we look back into the already 
// sorted sublist, we shift those items that are greater to the right. When we 
// reach a smaller item or the end of the sublist, the current item can be inserted.
// Its time complexity is O(n^2).
//
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/20: comparator default argument added 
// 
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 insertion.cpp -o insertion
// > ./insertion
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG insertion.cpp -o insertion
// > ./insertion
//
// To add this function to a static library libsort.a, 
// 1. set #if 0 to deactivate main() function at the bottom of the file first. 
// 2. compile first to produce ~.o file. 
// 3. add it to libsort.a as shown below.
// > g++ -std=c++11 -c insertion.cpp         # produce insertion.o
// > ar r libsort.a insertion.o              # insert or update insertion.o in libsort.a
// > ar t libsort.a                          # show objects in libsort.a 

#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void insertionsort(int *list, int n) {
	DPRINT(cout << "INSERTION SORTING...\n");
	for (int i = 1; i < n; i++) {
		int key = list[i];
		int j = i - 1;
		// move elements of list[0..i-1], that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && key < list[j]) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
		DPRINT(for(int x = 0; x < n; x++) cout << list[x] << " "; cout << endl);
	}
}

#if 1

int main() {
	int list[] = { 7, 3, 4, 1, 9, 6, 5, 2, 8, 0};
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl << endl;

	insertionsort(list, N);
	cout << "INSERTION SORTED: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl << endl;

    // Uncomment the next line and modify the code above to make it work. 
	// insertionsort(list, N, more);
	cout << "INSERTION SORTED using more fp: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl << endl;

	cout << "Happy Coding~~";
	return 0;
}
#endif
