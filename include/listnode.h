//  
// listnode.h
// contains structures and functions for a simply-linked list of nodes.
// 
// 2018.12.12 Created by idebtor@gmail.com 
// 2020.04.15 Added reverse functions and push_N()

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

// Node struct contains data and a pointer to the next node.
struct Node {
	int		data;
	Node*	next;
	// constructor with default arguments
	Node(int i = 0, Node* n = nullptr) { 
		data = i, next = n;
	}
	/* initializer list /////////////////////
	Node() : data(0), next(nullptr) {};
	Node(int i) : data(i), next(nullptr) {};
	Node(int i, Node* n): data(i), next(n) {};
	*////////////////////////////////////////
	~Node() {}
};

using pNode = Node*;

Node* clear(Node* p);	// free linked nodes and returns nullptr
Node* last(Node* p);	// returns the last node
bool empty(Node* p);	// true if empty, otherwise false
int size(Node* p);		// returns size in the list

Node* push_front(Node* p, int x);	// pushes a new node at the front
Node* push_back(Node* p, int x);	// pushes a new node at the back
Node* push(Node* p, int val, int x);// pushes a new node at the position x
Node* push_backN(Node *p, int N);	// pushes N nodes to the back, O(n^2)
Node* push_frontN(Node* p, int N);  // pushes N nodes to the front, O(n)
// pushes N nodes using either push_back or push_front function pointer.
Node* push_N(Node* p, int N, Node* (*push_fp)(Node *, int));

Node* pop_front(Node* p);			// pops the first node in the list
Node* pop_back(Node* p);			// pops the last node in the list, O(n)
Node* pop(Node* p, int val);	    // pops the node with the val
Node* pop_backN(Node* p, int N);    // pops N nodes from the end, O(n^2)
Node* pop_frontN(Node* p, int N);   // pops N nodes from the front, O(n)
// pops N nodes using either pop_back or pop_front function pointer.
Node* pop_N(Node* p, int N, Node* (*pop_fp)(Node*));

Node* reverse_using_stack(Node* p); // reverses list using stack, O(n), O(n)
Node* reverse_in_place(Node* p);	// reverses list in-place, O(n), O(1)
Node* reverse_odd2(Node* p);		// reverses nodes in subgroups of odds in O(n^2)
Node* reverse_oddn(Node* p);		// reverses nodes in subgroups of odds in O(n)

// if all is true, show all nodes; otherwise, show_n * 2 nodes from front & back. 
void show(Node* p, bool all = true, int show_n = 12);  // 12: a default magic number
#endif
