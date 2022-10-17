//  
// listnode.h
// contains structures and functions for a simply-linked list of nodes.
// 
// author: idebtor@gmail.com 
// 

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
void minmax(Node* p, int& min, int& max); // sets min, max of the list

Node* push_front(Node* p, int x);	// pushes a new node at the front
Node* push_back(Node* p, int x);	// pushes a new node at the back
Node* push(Node* p, int val, int x);// pushes a new node at the position x
Node* push_N(Node* p, int N, Node* (*push_fp)(Node *, int)); // pushes N nodes
Node* push_sorted(Node* p, int val);// pushes a new node in sorted order ascending
Node* insertion_sort(Node* p);      // sorts and returns a new singly linked list

Node* pop_front(Node* p);			// pops the first node in the list
Node* pop_back(Node* p);			// pops the last node in the list
Node* pop(Node* p, int val);	    // pops the node with the val
Node* pop_N(Node* p, int N, Node* (*pop_fp)(Node*));  // pops N nodes

pair<Node*, Node*> cut_in_two_halves(Node* p); // cut the list in two halves
Node* keep_second_half(Node* p);	// keeps the second half
Node* reverse_using_stack(Node* p); // reverses list using stack
Node* reverse_in_place(Node* p);	// reverses list in-place
Node* zap_duplicates(Node* p);      // zap duplicates 

// if all is true, show all nodes; otherwise, show_n * 2 nodes from front & back. 
void show(Node* p, bool all = true, int show_n = 10);  // 10: a default magic number
#endif
