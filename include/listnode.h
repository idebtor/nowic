//  listnode.h
//  Created by idebtor@gmail.com on December 12, 2018.
//  This header file contains a simple linked list of nodes.

#ifndef LISTNODE_H
#define LISTNODE_H

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

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p);	// free linked nodes and returns nullptr

pNode last(pNode p);	// returns the last node
bool empty(pNode p);	// true if empty, otherwise false
int size(pNode p);		// returns size in the list

// inserts a new node with val at the beginning of the list and 
// returns the new first node.
// This effectively increases the list size by one.
pNode push_front(pNode p, int x);	

// inserts a new node with val at the end of the list and 
// returns the first node.
// This effectively increases the container size by one.
pNode push_back(pNode p, int x);	

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list. 
// This effectively increases the container size by one.
pNode push(pNode p, int val, int x);

// adds N number of new nodes at the end of the list, O(n)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
// Since it simply calls push_back() repeatedly, it is O(N^2).
pNode push_backN(pNode p, int N);	

pNode pop_front(pNode p);			// deletes the first node in the list
pNode pop_back(pNode p);			// deletes the last node in the list, O(n)
pNode pop(pNode p, int val);	    // deletes the node with the val
pNode pop_backN(pNode p, int N = 0);// deletes N nodes from the end, O(N^2)
                                    // deletes all nodes by default (N = 0)

void show(pNode p, bool all = true);// shows values of nodes in list
#endif
