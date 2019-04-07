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
	pNode p = nullptr;
	bool show_all = true;  // toggle the way of showing values 
	
	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdin,  NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		cout << "\n\tLinked List of Nodes(" << size(p) << ") MENU\n";
		cout << "\tf - push front O(1)\n";
		cout << "\tb - push back  O(n)\n";
		cout << "\ti - push*      O(n)\n";
		cout << "\tp - pop front  O(1)\n";
		cout << "\ty - pop back   O(n)\n";
		cout << "\td - pop*       O(n)\n"; 
		cout << "\tc - clear      O(n)\n\n";			
		if (show_all)
			cout << "\tt - show* [ALL]\n";
		else
			cout << "\tt - show* [HEAD/TAIL]\n";
		cout << "\tB - stress test: push back O(n^2)\n";
		cout << "\tY - stress test: pop  back O(n^2)\n";
		c = GetChar("\tCommand[q to quit]: ");

		// execute the command
		switch (c) {
		case 'f':
		case 'b':
		case 'i':
			val = GetInt("\tEnter a number to push: ");
			switch (c) {
			case 'f':
				p = push_front(p, val);
				break;
			case 'b':
				p = push_back(p, val);
				break;
			case 'i':
				int x = GetInt("\tChoose a position node: ");
				p = push(p, val, x);
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
		case 'd':  // deletes the first node with val
			if (empty(p)) break;
			val = GetInt("\tEnter a number to delete: ");
			p = pop(p, val);
			break;


		case 't': // toggle the way of showing
			show_all ? show_all = false : show_all = true; 
			break;		
		case 'c':
			if (empty(p)) break;
			p = clear(p);
			break;

		case 'B':
			val = GetInt("\tEnter number of nodes to push back?: ");
			begin = clock();
			p = push_backN(p, val);
			break;
		case 'Y':
			if (empty(p)) break;
			val = GetInt("\tEnter number of nodes to pop back?: ");
			begin = clock();
			p = pop_backN(p, val);
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
		show(p, show_all);
	} while (c != 'q');

	clear(p);
	cout << "\n\t--Happy Coding!--\n";
	return EXIT_SUCCESS;
}
