//  liststack.h
//  author: idebtor@gmail.com
//  This header file contains a stack using singly linked list of nodes.

#ifndef LISTSTACK_H
#define LISTSTACK_H

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#include <iostream>
#include <string>

using namespace std;

// Node structs contain data and a pointer to the next node.
struct Node {
	int		data;
	Node*	next;
	// constructor instantiates a node with default arguments
	Node(const int i = 0, Node* n = nullptr) {
	 	data = i, next = n;
	}
	// Node(int i, Node* n): data(i), next(n) {}
	~Node() {}
};
using pNode = Node*;

// removes all the nodes from the list (which are deallocated),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p);	// free linked nodes and returns nullptr

bool empty(pNode p);	// true if empty, otherwise false
int size(pNode p);		// returns size in the list

// sets the min and max values which are passed as references in the list
void minmax(pNode p, int& min, int& max); 

// pushes a new node with val at the beginning of the list or
// onto the top of the stack  and returns the new first node.
pNode push(pNode p, int x, int N = 1);

// removes N nodes in the list and returns the new first node.
// This deallocates the removed node, effectively reduces its size by N.
pNode pop(pNode p, int N = 1);

// returns the top node of the stack or the first node in the list
pNode top(pNode p);

// shows all the list elements, show_n items per line  if all is true.
// shows the first and the last show_n items in the list if all is false.
void show(pNode p, bool all = true, int show_n = 10);
#endif
