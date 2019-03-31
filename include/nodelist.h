//  nodelist.h
//  Created by idebtor@gmail.com on December 12, 2018.
//  This header file contains the ListLab class declarations.

#ifndef NODELIST_H
#define NODELIST_H

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
	int		item;
	Node*	next;
	// constructor instantiates a node with default arguments
	Node(const int i = 0, Node* n = nullptr) {
		item = i, next = n;
	}
	~Node() {}
};
using pNode = Node*;

pNode clear(pNode p);	// free linked nodes and returns nullptr
pNode last(pNode p);	// returns the last element
bool empty(pNode p);	// true if empty, otherwise false
int size(pNode p);		// returns size in the list

// Insert element at beginning
// Inserts a new element at the beginning of the list, right before its
// current first element.The content of val is copied(or moved) to the
// inserted element. This effectively increases the container size by one.
pNode push_front(pNode p, int x);	// inserts a node at front of list

// Add element at the end
// Adds a new element at the end of the list container, after its current
// last element. The content of val is copied (or moved) to the new element.
// This effectively increases the container size by one.
pNode push_back(pNode p, int x);	// inserts a node at back of list
pNode push_backN(pNode p, int N);	// inserts N nodes at the end, O(n)

pNode pop_front(pNode p);			// deletes the first node in the list
pNode pop_back(pNode p);			// deletes the last node in the list, O(n)
pNode pop_backN(pNode p, int N = 0);// delete N nodes from the end, O(N)
                                    // delete all nodes by default (N = 0)

pNode remove(pNode p, int item);	// deletes the node with the item

void show(pNode p, bool all = true);// shows items in list
#endif
