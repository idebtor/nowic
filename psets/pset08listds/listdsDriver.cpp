/**
Name        : llistDriver.cpp
Author      : Youngsup Kim, idebtor@gmail.com

04/13/16:	Created
10/20/18:	Added: O(1) options
04/10/18:	added stress test functions more completely
02/10/19:	doubly linked list with sentinel nodes

Description :
: This implements a doubly linked list with two sentinel nodes
: including interactive stress test options.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include "nowic.h"
#include "listds.h"
using namespace std;

int main(int argc, char **argv) {
	char c;
	int val, x;
	clock_t start = 0;
	bool show_all = false;  // toggle the way of showing values 
	pList p = new List;		// create an empty list with two sentinel nodes

	do {
		cout << "\n\tDoubly Linked List(N=" << size(p) << ")\n";
		cout << "\tf - push front   O(1)\t";		cout << "\tp - pop front   O(1)\n";		
		cout << "\tb - push back    O(1)\t"; 		cout << "\ty - pop back    O(1)\n";		
		cout << "\ti - push         O(n)\t"; 		cout << "\td - pop         O(n)\n";
		cout << "\tz - push sorted* O(n)\t";		cout << "\te - pop vals*   O(n)\n";
		cout << "\n";
		cout << "\ts - sort*        O(n^2)\t";		cout << "\tu - unique*     O(n)\n";
		cout << "\tr - reverse**    O(n)\t"; 		cout << "\tx - shuffle***  O(n)\n";
		cout << "\tc - clear        O(n)\t";
		if (show_all)
			cout << "\tt - show [ALL]\n";
		else
			cout << "\tt - show [HEAD/TAIL]\n";
		cout << endl;
		cout << "\tB - push backN   O(n)\t";  		cout << "\tS - push sortedN O(nlogn)\n";
		cout << "\tY - pop  backN   O(n)\n";
		c = GetChar("\tCommand[q to quit]: ");
		
		switch (c) {	// execute the command
		case 'f':
		case 'b':
		case 'i':
		case 'z':
			val = GetInt("\tEnter a number to push: ");
			switch (c) {
			case 'f':
				push_front(p, val);
				break;
			case 'b':
				push_back(p, val);
				break;
			case 'i':
				x = GetInt("\tChoose a position node: ");
				push(p, val, x);
				break;
			case 'z':
				if (!empty(p) && !sorted(p)) {
					cout << "\t Run sort first and try it again\n";
					break;
				}
				push_sorted(p, val);
				break;
			}
			break;

		case 'p':  // deletes the first node in the list
			if (empty(p)) break;
			pop_front(p);
			break;
		case 'y':  // deletes the last node in the list, O(n)
			if (empty(p)) break;
			pop_back(p);
			break;
		case 'd':  // deletes one node with the value
			if (empty(p)) break;
			val = GetInt("\tEnter a number to pop: ");
			pop(p, val);
			break;
		case 'e':  // deletes all the nodes with the value given
			if (empty(p)) break;
			val = GetInt("\tEnter a number to pop all: ");
			pop_all(p, val);
			break;
		case 's':
			if (empty(p)) break;
			start = clock();
			if (sorted(p)) 
				reverse(p);
			else {
				char ch = GetChar("\tEnter b for bubble, q for quick, s for selection sort: ");
				switch(ch) {
				case 'b': bubbleSort(p); break;
				case 'q': quickSort(p); break;
				case 's': selectionSort(p); break;
				}
			}
			break;
		case 'u':
			if (empty(p)) break;
			if (!sorted(p)) {
				cout << "\t*****sort first and try it again****\n";
				break;
			}
			start = clock();
			unique(p);
			break;

		case 'r':
			if (empty(p)) break;
			start = clock();
			reverse(p);
			break;

		case 'x':
			if (empty(p)) break;
			start = clock();
			shuffle(p);
			break;

		case 't': // toggle the way of showing
			show_all ? show_all = false : show_all = true;
			break;		
		
		case 'c':
			if (empty(p)) break;
			start = clock();
			clear(p);
			break;

		case 'S':
			val = GetInt("\tEnter number of nodes to push sorted?: ");
			start = clock();
			push_sortedN(p, val);
			break;
		case 'B':
			val = GetInt("\tEnter number of nodes to push back?: ");
			start = clock();
			push_backN(p, val);
			break;
		case 'Y':
			if (empty(p)) break;
			val = GetInt("\tEnter number of nodes to pop back?: ");
			start = clock();
			pop_backN(p, val);
			break;
		}

		switch (c) {
		case 'c':
		case 's':
		case 'u':
		case 'r':
		case 'S':
		case 'B':
		case 'Y':
			if (empty(p)) break;
			cout << "\tcpu: "
				 << ((clock_t) clock() - start) / CLOCKS_PER_SEC << " sec\n";
		default:
			break;
		}
		show(p, show_all);
	} while (c != 'q');

	clear(p);
	cout << "\n\tJoyful Coding!\n";
	return EXIT_SUCCESS;
}
