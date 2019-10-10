//  nodelistDriver.cpp
//  This driver is used to test the nodelist.cpp which implements
//  the basic linked list of nodes.
//  Author: Youngsup Kim, idebtor@gmail.com
//  03/13/19:	Created

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include "nowic.h"
#include "listnode.h"
using namespace std;

int main(int argc, char **argv) {
	char c;
	int val;
	clock_t begin;
	pNode head = nullptr;
	bool show_all = true;  // toggle the way of showing values 
	int pmax = 10;
	
	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdin,  NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		cout << "\n\tLinked List(nodes:" << size(head) << ", pmax:" << pmax << ") MENU\n";
		cout << "\tf - push front O(1)\n";
		cout << "\tb - push back  O(n)\n";
		cout << "\ti - push*      O(n)\n";
		cout << "\tp - pop front  O(1)\n";
		cout << "\ty - pop back   O(n)\n";
		cout << "\td - pop*       O(n)\n"; 
		cout << "\tr - reverse*   O(n)\n\n";			
		if (show_all)
			cout << "\tt - show  [ALL]\n";
		else
			cout << "\tt - show  [HEAD/TAIL]\n";
		cout << "\tB - push back O(n^2)\n";
		cout << "\tY - pop  back O(n^2)\n";
		c = GetChar("\tCommand[q to quit]: ");

		// execute the command
		switch (c) {
		case 'f':
		case 'b':
		case 'i':
			val = GetInt("\tEnter a number to push: ");
			switch (c) {
			case 'f':
				head = push_front(head, val);
				break;
			case 'b':
				head = push_back(head, val);
				break;
			case 'i':
				int x = GetInt("\tChoose a position node: ");
				head = push(head, val, x);
			}
			break;

		case 'p':  // deletes the first node in the list
			if (empty(head)) break;
			head = pop_front(head);
			break;

		case 'y':  // deletes the last node in the list, O(n)
			if (empty(head)) break;
			head = pop_back(head);
			break;

		case 'd':  // deletes the first node with val
			if (empty(head)) break;
			val = GetInt("\tEnter a number to delete: ");
			head = pop(head, val);
			break;

		case 'r':  // deletes the first node with val
			if (empty(head)) break;
			head = reverse(head);
			break;

		case 't': // toggle the way of showing
			show_all ? show_all = false : show_all = true; 
			break;		
		case 'c':
			if (empty(head)) break;
			head = clear(head);
			break;

		case 'B':
			val = GetInt("\tEnter number of nodes to push back?: ");
			begin = clock();
			head = push_backN(head, val);
			break;
		case 'Y':
			if (empty(head)) break;
			val = GetInt("\tEnter number of nodes to pop back?: ");
			begin = clock();
			head = pop_backN(head, val);
			break;
		}

		switch (c) {
		case 'B':
		case 'Y':
			cout << "\tcpu: "
				<< double(clock() - begin) / CLOCKS_PER_SEC << " sec\n";
		default:
			break;
		}
		show(head, show_all);
	} while (c != 'q');

	clear(head);
	cout << "\n\t--Happy Coding!--\n";
	return EXIT_SUCCESS;
}
