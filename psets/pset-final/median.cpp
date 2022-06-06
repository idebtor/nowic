/**
* File: median.cpp 
*	Interactively solve for the median of stream of integers using two heaps.
*   This implementation uses the heap size invariants. 
*   
* Heap size invariants:
*   Keep the size(maxhp) is always N/2.
*   Keep the size(minhp) is greater than size(maxhp) by 1 if N is odd.
*  
* We begin with two heaps: a min-heap and a max-heap. 
* Next, let's introduce a condition: 
* Keep the size of the max-heap must be (n / 2) at all times, while the size of the min-heap 
* can be either (n / 2) or (n / 2) + 1, depending on the total number of elements in the 
* two heaps. In other words, we can allow only the min-heap to have an extra element, 
* when the total number of elements is odd.
*
* With our heap size invariant, we can compute the median as the average of the root 
* elements of both heaps, if the sizes of both heaps are (n / 2). Otherwise, the root 
* element of the min-heap is the median.
* 
* When we add a new integer, we have two scenarios:
* 1. Total no. of existing elements is even
*    size(min-heap) == size(max-heap) == (n / 2)
* 2. Total no. of existing elements is odd
*    size(max-heap) == (n / 2)
*    size(min-heap) == (n / 2) + 1
* We can maintain the invariant by adding the new element to one of the heaps and 
* rebalancing every time.
* 
* The rebalancing works by moving the largest element from the max-heap to the min-heap, 
* or by moving the smallest element from the min-heap to the max-heap. This way, though 
* we're not comparing the new integer before adding it to a heap, the subsequent 
* rebalancing ensures that we honor the underlying invariant of smaller and larger halves.
*
* Time complexity: getMedian costs O(1) time, while add runs in time O(log n) with exactly 
* the same number of operations.
*
* Files: heap.h, heap.cpp, median.cpp, heapprint.cpp, treeprint.cpp
* Build: g++ median.cpp heap.cpp treeprint.cpp heapprint.cpp  \\
*            -I../../include -L../../lib -lnowic -o median
* 
* References Heap size invariant solution for the median of stream of integers using two heaps
*   https://www.baeldung.com/java-stream-integers-median-using-heap
*
* @author: Youngsup Kim, idebtor@gmail.com
*/

#include <iostream>
#include <string>
#include <cassert>
#include "nowic.h"
#include "heap.h"

using namespace std;

// returns the root of the heap, 0 if heap is empty
int peek(heap hp) {
	cout << "your core here\n";
	return 0;
}

// a helper function
string heapspecs(heap hp) {
	if (empty(hp)) return "";
	stringstream ss;
	ss << "root:" << peek(hp) << " size:" << size(hp) 
	   << " capa:" << capacity(hp) << " height:" << height(hp);
	return ss.str();
}

// When we add a new integer, we have two scenarios:
// 1. Total no. of existing elements is even, 
//    size(minhp) == size(maxhp) == (n / 2)
// 2. Total no. of existing elements is odd, 
//	  size(maxhp) == (n / 2) or size(minhp) == (n / 2) + 1
// We can maintain the invariant by adding the new element to one of the heaps and 
// rebalancing every time. The rebalancing works by moving the largest element 
// from the max-heap to the min-heap, or by moving the smallest element from the 
// min-heap to the max-heap. 
void growMedian(heap maxhp, heap minhp, int item) {
	if (size(minhp) == size(maxhp)) {
		cout << "your code here\n";
	}
	else {
		cout << "your code here\n";
	}
}

// 1. Find the max key(max) in among two heaps. Start from max=1 if heaps are empty.
// 2. Allocate a Key type array such as keys to store random keys.
// 3. Invoke randomN() function to generate keys in the range
//    [(max + 1)..(max + count)]
// 4. Invoke the function to insert keys in keys[], but one key at a time.
// 5. Don't forget freeing the array of keys you allocated in Step 2.
void growMedianN(heap maxhp, heap minhp, int count) {
	DPRINT(cout << ">growMedianN" << endl;);

	cout << "your code here\n";

	DPRINT(cout << "<growMedianN" << endl;);
}

// Remember the heap-size invariant:
// Keep the size(maxhp) is always N/2. 
// Keep the size(minhp) is either N/2 or N/e + 1.
// Keep the size(minhp) is greater than size(maxhp) by 1 if N is odd.
double getMedian(heap maxhp, heap minhp) {
	
	cout << "your code here\n";

	return 0;
}

int main(int argc, char* argv[]) {
	string showMenu[] = { "[tree]", "[level]", "[tasty]" };
	int showMode = TREE_MODE;  // by default, display both [tree] only
	int item;
	char c, n;
	DPRINT(cout << "\t>Joyful Coding\n";);

	// get an initial maxheap & minheap  
	heap maxhp = new Heap;
	setType(maxhp);
	heap minhp = new Heap; 
	setType(minhp, false);
	
	do {
		heapprint(maxhp, showMode);
		heapprint(minhp, showMode);

		cout << "\tMaxHeap: " << heapspecs(maxhp) << endl;
		cout << "\tMinHeap: " << heapspecs(minhp) << endl;
		cout << "\t Median: " << getMedian(maxhp, minhp) << endl << endl;

		cout << "\tg - grow\t\t";		cout << "t - trim\n";		
		cout << "\tx - grow N\t\t";		cout << "y - trim N\n";		
		cout << "\th - heap-ordered?";  cout << "\tc - clear\n"; 		
		cout << "\tm - show mode:" << showMenu[showMode] << endl;

		c = GetChar("\tCommand(q to quit): ");
		switch (c) {
		case 'g':  // grow
			item = GetInt("\n\tEnter a key to grow: ");
			growMedian(maxhp, minhp, item);
			break;

		case 't':  // trim - remove the median
			if (empty(minhp)) break;

			cout << "your code here\n";

			break;

		case 'h':  // heap-ordered?
			if (empty(minhp)) break;
			if (heapOrdered(maxhp)) 
				cout << "\tMaxHeap: heap-ordered" << endl;
			else
				cout << "\tMaxHeap: NOT heap-ordered" << endl;
			if (heapOrdered(minhp)) 
				cout << "\tMinHeap: heap-ordered" << endl;
			else
				cout << "\tMinHeap: NOT heap-ordered" << endl;
			break;

		case 'x':	// grow N nodes with unique random keys to the heap
			n = GetInt("\n\tEnter a number of nodes to grow: ");
			if (n <= 1) break;
			growMedianN(maxhp, minhp, n);
			break;

		case 'y':	// trim N nodes from heap  
			n = GetInt("\n\tEnter a number of nodes to trim: ");
			if (n < 1) break;

			cout << "your code here\n";

			break;

		case 'c':	// clear 
			clear(maxhp);
			clear(minhp);

			maxhp = new Heap;
			setType(maxhp);
			minhp = new Heap;
			setType(minhp, false);

			break;

		case 'm': // show mode - rollover to the next menu item
			showMode = (showMode + 1) % (sizeof(showMenu) / sizeof(showMenu[0]));
			break;
		}
	} while (c != 'q');

	clear(maxhp);
	clear(minhp);
	cout << "\tJoyful Coding^^\n";
}

