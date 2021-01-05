// selection sort 
// 
// A selection sort algorithm - its time complexity is O(n^2).
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/02: Testing added, updated c++11 and documented
//
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 selection.cpp printList.cpp -o selection
// > ./selection
//
// To test and use DEBUG, 
// Set #if 1 to activate main() function at the bottom of the file first. 
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG selection.cpp printList.cpp -o selection
// > ./selection
// 
// To add it a static library, compile first and add it to the library
// Set #if 0 to deactivate main() function at the bottom of the file first. 
// > g++ -std=c++11 -c selection.cpp      # produce selection.o
// > ar r libsort.a selection.o           # insert or update selection.o in libsort.a
// > ar t libsort.a                       # list objects in libsort.a 
//

#include <iostream>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void selectionsort(int *list, int n) {
	DPRINT(cout << "selectionsort\n");
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		// Swap min found with the first one of unsorted
		int temp = list[i];
		list[i] = list[min];
		list[min] = temp;
		DPRINT(for (int x = 0; x < n; x++) cout << list[x] << " "; cout << endl;);
	}
}

#if 0
int main() {
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	int N = sizeof(list) / sizeof(list[0]);
	// int N = 250;
	// int* list = new int[N];
	// for (int i = 0; i < N; i++) list[i] = rand() % N;

	cout << "UNSORTED: " << endl;
	for (auto x: list) cout << x << "  ";

	selectionsort(list, N);

	cout << "\nSELECTION SORTED: " << endl;
	for (auto x: list) cout << x << "  ";
	// delete[] list;
}
#endif
