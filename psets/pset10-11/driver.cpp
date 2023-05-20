/**
* File: driver.cpp 
*	interactively tests the max or min priority queue that uses a heap.
* 
* Files: heap.cpp, heap.h, driver.cpp :max/minheap 
*
* author: idebtor@gmail.com
* Usage : You may specify initial keys of nodes as command-line arguments
* 
* Good references about getopt() or pgetopt()
* http://www.ibm.com/developerworks/aix/library/au-unix-getopt.html
* https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/getopt.html
*/

#include <iostream>
#include <string>
#include <cassert>
#include "nowic.h"
#include "heap.h"

using namespace std;

heap build_heap_by_args(int argc, char* argv[]) {
	DPRINT(cout << ">build_heap_by_args\n";);
	if (argc <= 1) return nullptr;

	int* bin = new (nothrow) int[argc];
	assert(bin != nullptr);

	for (int i = 0; i < (argc - 1); i++) 
		bin[i] = strtol(argv[i + 1], nullptr, 0);
	heap hp = newCBT(bin, argc - 1);
	// setType(hp, true);   // set maxheap

	delete[] bin;
	DPRINT(cout << "<build_heap_by_args\n";);
	return hp;
}

string heapspecs(heap hp) {
	if (empty(hp)) return "";
	stringstream ss;
	ss << "mn:" << minimum(hp) << " mx:" << maximum(hp) << " sz:" << size(hp)
	   << " ht:" << height(hp) << " cp:" << capacity(hp);
	return ss.str();
}

int main(int argc, char* argv[]) {
	string menuMax = "PQ(Maxheap): ";
	string menuMin = "PQ(Minheap): ";
	string menuCBT = "CBT: ";
	string menu;

	string showMenu[] = { "[tree]", "[level]", "[tasty]" };
	int showMode = TREE_MODE;  // by default, display both [tree] only
	bool maxType;
	int newKey, oldKey, item, n;
	char c;
	DPRINT(cout << "\t>Joyful Coding\n";);

	// get an initial heap from command line args if specified
	heap hp = argc <= 1 ? new Heap : build_heap_by_args(argc, argv);
	setType(hp, maxType = true);
	bool ordered = heapOrdered(hp);
	
	do {
		heapprint(hp, showMode);
		menu = ordered ? (maxType ? menuMax : menuMin) : menuCBT;
		cout << "\n\t" << menu << heapspecs(hp) << endl;
		cout << "\tg - grow\t\t";			cout << "h - heapify\n";
		cout << "\tt - trim\t\t";			cout << "s - heapsort\n";
		cout << "\tp - priority queue\t";	cout << "o - heap-ordered?\n";	
		cout << endl;
		cout << "\tx - grow N\t\t";		cout << "w - switch to CBT\n"; 
		cout << "\ty - trim N\t\t";		cout << "z - switch to [PQ:max/minheap]\n";
		cout << "\tc - clear\t\t"; 		cout << "m - show mode:" << showMenu[showMode] << endl;

		c = GetChar("\tCommand(q to quit): ");
		switch (c) {
		case 'g':  // grow
			item = GetInt("\n\tEnter a key to grow: ");
			ordered ? grow(hp, item) : growCBT(hp, item);
			break;

		case 't':  // trim
			if (empty(hp)) break;
			ordered ? trim(hp) : trimCBT(hp);
			break;

		case 'p':  // replace(priority queue)
			if (empty(hp)) break;
			if (!ordered) break;  

			while (1) {
				oldKey = GetInt("\n\tSelect a key to replace: ");
				if (contains(hp, oldKey)) break;
				cout << "\n\tNot found: Try again\n";
			}
			newKey = GetInt("\tEnter a new key: ");
			replace(hp, oldKey, newKey);
			break;

		case 'h':  // heapify
			if (empty(hp)) break;
			heapify(hp);
			ordered = true;
			break;

		case 's':	// heapsort 
			if (empty(hp)) break;
			heapsort(hp);
			maxType = maxType ? false : true;
			setType(hp, maxType);
			ordered = true;
			break;

		case 'o':	// is it heap-ordered?
			if (empty(hp)) break;
			if (heapOrdered(hp))
				cout << "\n\tYes, it is heap-ordered.\n";
			else
				cout << "\n\tNo, it is not heap-ordered.\n";
			break;

		case 'w':	// switch it to a complete binary tree 
			ordered = false;
			break;

		case 'z':   // turn into max-heap or min-heap
			if (ordered)
				maxType = maxType ? false : true;
			else
				maxType = true;
			setType(hp, maxType);
			heapify(hp);
			ordered = true;
			break;

		case 'x':	// grow N nodes with unique random keys to heap or CBT
			n = GetInt("\n\tEnter a number of nodes to grow: ");
			if (n <= 1) break;
			growN(hp, n, ordered);
			break;

		case 'y':	// trim the root N times from heap or CBT  
			n = GetInt("\n\tEnter a number of nodes to trim: ");
			if (n < 1) break;
			trimN(hp, n, ordered);
			break;

		case 'c':	// clear 
			clear(hp);
			hp = new Heap;
			setType(hp, maxType);
			break;

		case 'm': // show mode - rollover to the next menu item
			showMode = (showMode + 1) % (sizeof(showMenu) / sizeof(showMenu[0]));
			break;
		}
	} while (c != 'q');

	clear(hp);
	cout << "\tJoyful Coding^^\n";
}

