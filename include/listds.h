/**
 * File: listds.cpp, listds.h
 *       implements a doubly linked list with sentinel nodes 
 *       and test it interactively
 * Author: Youngsup Kim, idebtor@gmail.com
 *
 * 04/13/16:	Created
 * 02/10/19:	C++ conversion, doubly linked list
 *
 * 1. This implements a doubly linked list with two sentinel nodes which
 *    provide with benifits of coding consistency and easy maintenance.
 * 2. It does not implment C++ iterator (which is deprecated), but simulated
 *    most of memeber functions defined in std::List.
 */
#ifndef LISTDS_H
#define LISTDS_H

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

struct Node{
	int		item;
	Node*	prev;
	Node*	next;
	// constructor instantiates a node, sets item and next
	Node(const int d = 0, Node* p = nullptr, Node* n = nullptr) {
		item = d; 	prev = p;	next = n;
	}
	~Node() {}
};

struct List{
	Node* 	head;	// sentinel node
	Node*	tail;	// sentinel node
	// constructor instantiates a list, sets doubly-linked head and tail
	List() {
		head = new Node;		tail = new Node;
		head->prev = nullptr;   head->next = tail;
		tail->prev = head; 		tail->next = nullptr;
	}
	~List() {}
};
using pNode = Node *;
using pList = List *;

pNode begin(pList p);			// returns the first node, not header 
pNode end(pList p);				// returns the tail which is sentinel node
pNode last(pList p);			// returns the last node
pNode half(pList p);            // returns the node in the middle 
void clear(pList p);			// frees nodes, not list
bool empty(pList p);			// true if empty, false if no empty
int size(pList p);				// returns the number of nodes in the list

// returns the first node with val found
// returns the tail or end(p) node if no node with val is found.
pNode find(pList p, int val);	

//////////////////////////////////////////////////////////////////////////
/////////// Make the best use of the following two fucntions  ////////////
///////////         insert() and erase()                      ////////////
//////////////////////////////////////////////////////////////////////////
// inserts a new node with val at the position of the node x.
// The new node is actually inserted in front of the node x.
// This effectively increases the list size by one.
void insert(pNode x, int val);

// removes from the list a single node x given.
// This effectively reduces the container by one which is destroyed.
// It is specifically designed to be efficient inserting and removing 
// a node regardless of its positions in the list such as front, back 
// or in the middle of the list.
void erase(pNode x);
///////////////////////////////////////////////////////////////////////////

///////////////////////// push /////////////////////////////////////////////
// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by one.
void push_front(pList p, int val);	

// adds a new node with val at the end of the list and returns the 
// first node of the list. This effectively increases the list size by one.
void push_back(pList p, int val);		

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list. 
// This effectively increases the container size by one.
void push(pList, int val, int x);  

// adds N number of new nodes at the end of the list, O(1)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
void push_backN(pList p, int N);	// inserts N nodes at the end, O(1)

////////////////////////// pop /////////////////////////////////////////////
// removes the first node in the list.
// This destroys the removed node, and reduces its size by one. 
void pop_front(pList p);		  

// removes the last node in the list, and reduces the list size 
// by one. This destroys the removed node. O(1)
void pop_back(pList p);			

// removes the first node with val from the list and does nothing if not found.
// Unlike member function List::erase which erases a node by its position, 
// this function removes a node by its value.  
// Unlike pop(), pop_all() removes all the nodes with the value given.
void pop(pList p, int val);		

// removes from the list all the nodes with the same value given.
// This calls the destructor of these objects and reduces the list size
// by the number of nodes removed.  Unlike erase(), which erases a node 
// by its position, this function removes nodes by its value. 
// Unlike pop_all(), pop() removes the first node with the value given. 
void pop_all(pList p, int val);	  

// deletes N number of nodes, starting from the end. 
// It deletes all the nodes if N is zero which is the default or out of 
// the range of the list.
// Since it simply calls pop_back() which is O(1) repeatedly, it is O(n).
void pop_backN(pList p, int N = 0); 

/////////////////////// unique, reverse, shuffle ///////////////////////////
// removes extra nodes that have duplicate values from the list.
// It removes all but the last node from every consecutive group of
// equal nodes in the list. Notice that a node is only removed from
// the list if it compares equal to the node immediately preceding it. 
// Thus, this function is especially useful for sorted lists. O(n)
void unique(pList p);			 

// reverses the order of the nodes in the list. 
// The entire operation does not involve the construction, destruction 
// or copy of any element object. Nodes are not moved, but pointers
// are moved within the list. O(n)
void reverse(pList p);

// returns so called "perfectly shuffled" list. 
// The first half and the second half are interleaved each other. 
// The shuffled list begins with the second half of the original.
// For example, 1234567890 returns 617283940.
void shuffle(pList p); 

///////////////////////// sort /////////////////////////////////////////////
int ascending(int a, int b);
int descending(int a, int b);

// returns the node of which value is larger than x encountered firstly.
// returns the tail or end(p) node if no node is more than val x. 
pNode _more(pList p, int x);  

// returns the node of which value is smaller than x encountered firstly. 
// returns the tail or end(p) node if no node is less than val x. 
pNode _less(pList p, int x);

bool sorted(pList p);				// returns true if sorted by up or down
bool sorted(pList p, int (*comp)(int a, int b));	// using comp fp provided

void push_sorted(pList p, int val); // inserts a node with val sorted
void push_sortedN(pList p, int N);	// inserts N nodes in sorted order, O(n)

// returns a list of nodes sorted in ascending order if not sorted by default, 
// using bubble or selection sort algorithm which is O(n^2). 
// If the list is already sorted, it reverses the list such that the ascending 
// ordered list becomes a descending order list and vice versa. It is O(n).
// In the bubble sort, it checks values of two adjacent node whether they 
// are in ascending order or not, if not then we swap the value. It does this 
// until every element get its right position.  In 1st pass the largest value 
// get its right position and in 2nd pass 2nd largest value get its position 
// and in 3rd pass 3rd largest element get its position and so on. 
void sort(pList p);

// algorithm specific sort functions, refer to listsort.cpp for detail
void bubbleSort(pList p, int(*comp)(int, int) = ascending);
void bubbleSort2(pList p, int(*comp)(int, int) = ascending);
void selectionSort(pList p, int(*comp)(int, int) = ascending);
void quickSort(pList p, int(*comp)(int, int) = ascending);
////////////////////////////////////////////////////////////////////////////

///////////////////////// show /////////////////////////////////////////////
// shows the values of all the nodes in the list if all is true or 
// the list size is less than pmax * 2. If there are more than 
// (pmax * 2) nodes, then it shows only pmax number of nodes from 
// the beginning and the end in the list.
void show(pList p, bool all = false);// shows values of nodes in list

#endif // LISTDS_H
