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
#include "nodelist.h"
using namespace std;

int main(int argc, char **argv) {
	char c;
	int item;
	clock_t begin;
	pNode p = nullptr;
	bool show_all = true;
	
	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdin,  NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		cout << "\n\tLinked Nodes MENU\n";
		cout << "\tf - push front O(1)\n";
		cout << "\tb - push back O(n)\n";
		cout << "\tp - pop front O(1)\n";
		cout << "\ty - pop back O(n)\n";
		cout << "\td - pop an item O(n)\n"; 
		if (show_all)
			cout << "\ts - show [ALL]\n";
		else
			cout << "\ts - show [HEAD/TAIL]\n";
		cout << "\tc - clear O(n)\n\n";
		cout << "\tT - stress test: push back, O(n)\n";
		cout << "\tY - stress test: pop  back, O(n)\n";
		c = GetChar("\tCommand[q to quit]: ");

		// execute the command
		switch (c) {
		case 'f':
		case 'b':
			item = GetInt("\tEnter a number to push: ");
			switch (c) {
			case 'f':
				p = push_front(p, item);
				break;
			case 'b':
				p = push_back(p, item);
				break;
			}
			break;

		case 'p':  // deletes the first node in the list
			if (empty(p)) break;
			p = pop_front(p);
			break;
		case 'y':  // deletes the last node in the list, O(n)
			if (empty(p)) break;
			p = pop_back(p);
			break;
		case 'd':  // deletes node by item
			if (empty(p)) break;
			item = GetInt("\tEnter a number to delete: ");
			p = remove(p, item);
			break;

		case 'c':
			if (empty(p)) break;
			p = clear(p);
			break;

		case 's':
			show_all ? show_all = false : show_all = true; 
			break;

		case 'T':
			item = GetInt("\tEnter number of nodes to push back?: ");
			begin = clock();
			p = push_backN(p, item);
			break;
		case 'Y':
			item = GetInt("\tEnter number of nodes to pop back?: ");
			begin = clock();
			p = pop_backN(p, item);
			break;
		}

		switch (c) {
		case 'T':
		case 'Y':
			cout << "\tcpu: "
				<< double(clock() - begin) / CLOCKS_PER_SEC << " sec\n";
		default:
			break;
		}
		show(p, show_all);
	} while (c != 'q');

	clear(p);
	cout << "\n\t--Happy Coding!--\n";
	return EXIT_SUCCESS;
}
