// bubble sort 
// 
// A bubble sort algorithm - its time complexity is O(n^2).
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/02: Testing added, updated c++11 and documented
//
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 bubble.cpp -o bubble
// > ./bubble
//
// To test and use DEBUG, 
// Set #if 1 to activate main() function at the bottom of the file first. 
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG bubble.cpp -o bubble
// > ./bubble
// 
// To add it a static library, compile first and add it to the library
// Set #if 0 to deactivate main() function at the bottom of the file first. 
// > g++ -std=c++11 -c bubble.cpp         # produce bubble.o
// > ar r libsort.a bubble.o              # insert or update bubble.o in libsort.a
// > ar t libsort.a                       # list objects in libsort.a 
//

#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void bubblesort(int *list, int n) {
  	DPRINT(cout << "bubblesort\n");
	for (int i = 0; i < n - 1; i++) {
		// last i elements are already in place
		for (int j = 0; j < n - i - 1; j++)
			if (list[j] > list[j + 1]) {
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		DPRINT(for (int x = 0; x < n; x++) cout << list[x] << " "; cout << endl;);
	}
}

#if 0
int main() {
	int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8};
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (auto x: list) cout << x << "  ";

	bubblesort(list, N);

	cout << "\nBUBBLE SORTED: " << endl;
	for (auto x: list) cout << x << "  ";
}
#endif
