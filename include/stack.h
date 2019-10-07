//  stack.h
//  Created by idebtor@gmail.com on Oct.7, 2019.
//  This header file contains a stack using singly-linked list of nodes.

#ifndef STACK_H
#define STACK_H

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
bool empty(pNode p);	// true if empty, otherwise false
int size(pNode p);		// returns size in the list

// pushes a new node with val at the beginning of the list or
// onto the top of the stack  and returns the new first node.
pNode push(pNode p, int x, int N = 1);

// deletes the top at the stack and
// returns the new pointer to the top of the stack
pNode pop(pNode p, int N = 1);

// returns the top node of the stack or the first node in the list
pNode top(pNode p);

// shows values of nodes in list.
// prints pmax * 2 items if all is false.
// prints all items in p if all is true.
void show(pNode p, bool all = true, int pmax = 10);
#endif
