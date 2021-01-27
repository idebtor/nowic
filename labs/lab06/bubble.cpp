// bubble sort by idebtor@gmail.com
// The bubble sort makes multiple passes through a list. It compares adjacent 
// items and exchanges those that are out of order. Each pass through the list 
// places the next largest value in its proper place.  It is important to note 
// that once the largest value in the list is part of a pair, it will continually 
// be moved along until the pass is complete.In essence, each item “bubbles” up 
// to the location where it belongs. Its time complexity is O(n^2).
// 
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/20: comparator default argument added 
// 
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 bubble.cpp -o bubble
// > ./bubble
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG bubble.cpp -o bubble
// > ./bubble
//
// To add this function to a static library libsort.a, 
// 1. set #if 0 to deactivate main() function at the bottom of the file first. 
// 2. compile first to produce ~.o file. 
// 3. add it to libsort.a as shown below.
// > g++ -std=c++11 -c bubble.cpp         # produce bubble.o
// > ar r libsort.a bubble.o              # insert or update bubble.o in libsort.a
// > ar t libsort.a                       # list objects in libsort.a 

#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// bubblesort using a comparator function passed as a function pointer.
void bubblesort(int *list, int n, bool (*comp)(int, int)) {
  DPRINT(std::cout << "BUBBLE SORTING...\n");
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) { // last i element is already in place
      if (comp(list[j + 1], list[j])) {
        swapped = true;
        swap(list[j + 1], list[j]);
      }
    }
    DPRINT(for(int x = 0; x < n; x++) cout << list[x] << " "; cout << endl);
    if (!swapped) break;
  }
}

#if 1
// two comparator functions 
// The value returned indicates whether the element passed as first argument
// is considered to go before the second in the specific ordering.
// more() and less() are equivalent to greater<int>() and less<int>() in STL. 
bool more(int x, int y) { return x > y; }   // for descending order
bool less(int x, int y) { return x < y; }   // for ascending order 

void bubblesort(int *list, int n, bool (*comp)(int x, int y) = ::less);

int main() {
	int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8 };
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl << endl;

	bubblesort(list, N);
	cout << "BUBBLE SORTED: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl  << endl;

  	bubblesort(list, N, more);   
	cout << "BUBBLE SORTED using more fp: " << endl;
	for (auto x: list) cout << x << "  "; 
	cout << endl  << endl;

  	cout << "Happy Coding~~";
  	return 0;
}
#endif