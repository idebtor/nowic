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
#include "stack.h"
using namespace std;

int main(int argc, char **argv) {
	char c;
	int val, N;
	clock_t begin;
	pNode stack = nullptr;
	pNode node;
	bool show_all = true;  // toggle the way of showing values

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdin,  NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		cout << "\n\tStack(nodes:" << size(stack) << ") MENU\n";
		cout << "\tf - push   O(1)\n";
		cout << "\tp - pop    O(1)\n";
		cout << "\tt - top    O(1)\n";
		cout << "\tc - clear  O(n)\n\n";
		if (show_all)
			cout << "\ts - show [ALL]\n";
		else
			cout << "\ts - show [HEAD/TAIL]\n";
		cout << "\tF - stress test: push N\n";
		cout << "\tP - stress test: pop  N\n";
		c = GetChar("\tCommand[q to quit]: ");

		// execute the command
		switch (c) {
		case 'f':
			val = GetInt("\tEnter a number to push: ");
			stack = push(stack, val);
			break;

		case 'p':  // pops(deletes) the top of the stack
			if (empty(stack)) break;
			stack = pop(stack);
			break;

		case 't':  // show the top of the stack
			if (empty(stack)) break;
			node = top(stack);
			cout << "Top: " << node->item;
			break;

		case 's': // toggle the way of showing
			show_all ? show_all = false : show_all = true;
			break;

		case 'c':
			if (empty(stack)) break;
			stack = clear(stack);
			break;

		case 'F':
			N = GetInt("\tEnter number of nodes to push?: ");
			begin = clock();
			stack = push(stack, 0, N);
			break;

		case 'P':
			if (empty(stack)) break;
			N = GetInt("\tEnter number of nodes to pop?: ");
			begin = clock();
			stack = pop(stack, N);
			break;
		}

		switch (c) {
		case 'F':
		case 'P':
			cout << "\tcpu: "
				<< double(clock() - begin) / CLOCKS_PER_SEC << " sec\n";
		default:
			break;
		}
		show(stack, show_all);
	} while (c != 'q');

	clear(stack);
	cout << "\n\t--Happy Coding!--\n";
	return EXIT_SUCCESS;
}
