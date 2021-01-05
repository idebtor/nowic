// insertion sort 
// 
// A insertion sort algorithm - its time complexity is O(n^2).
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/02: Testing added, updated c++11 and documented
//
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 insertion.cpp -o insertion
// > ./insertion
//
// To test and use DEBUG, 
// Set #if 1 to activate main() function at the bottom of the file first. 
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG insertion.cpp -o insertion
// > ./insertion
// 
// To add it a static library, compile first and add it to the library
// Set #if 0 to deactivate main() function at the bottom of the file first. 
// > g++ -std=c++11 -c insertion.cpp      # produce insertion.o
// > ar r libsort.a insertion.o           # insert or update insertion.o in libsort.a
// > ar t libsort.a                       # list objects in libsort.a 
//

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void insertionsort(int *list, int n) {
	DPRINT(cout << "insertionsort\n");
	for (int i = 1; i < n; i++) {
		int key = list[i];
		int j = i - 1;
		// move elements of list[0..i-1], that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
		DPRINT(for (int x = 0; x < n; x++) printf("%d ", list[x]); printf("\n");)
	}
}

#if 0
int main() {
	int list[] = { 7, 3, 4, 1, 9, 6, 5, 2, 8, 0};
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (auto x: list) cout << x << "  ";

	insertionsort(list, N);

	cout << "\nINSERTION SORTED: " << endl;
	for (auto x: list) cout << x << "  ";
}
#endif
