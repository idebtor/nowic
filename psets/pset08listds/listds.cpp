/**
* File: listdsx.cpp, listds.h
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

#include <iostream>
#include <cassert>
#include <iomanip>
#include "listds.h"
using namespace std;

// Removes all elements from the list container(which are destroyed),
// and leaving the container with a size of 0.
void clear(pList p) {
	if (empty(p)) return;

	DPRINT(cout << "clear: ";);
	pNode curr = begin(p);
	pNode head = curr->prev;		// saved head node
	while (curr != end(p)) {
		pNode prev = curr;
		curr = curr->next;
		DPRINT(cout << prev->item << " ";);
		delete prev;
	}
	DPRINT(cout << endl;);

	p->head->next = p->tail;			// set tail at head
	p->tail->prev = p->head;			// set head at tail
	cout << "\tHappy Coding~~\n";
}

// returns the first node which List::head points to in the container.
pNode begin(pList p) {
	return p->head->next;
}

// returns the tail node referring to the past -the last- node in the list. 
// The past -the last- node is the sentinel node which is used only as a sentinel 
// that would follow the last node. It does not point to any node next, and thus
// shall not be dereferenced. Because the way we are going use during the iteration, 
// we don't want to include the node pointed by this. this function is often used 
// in combination with List::begin to specify a range including all the nodes in 
// the list. This is a kind of simulated used in STL. If the container is empty, 
// this function returns the same as List::begin.
pNode end(pList p) {
	return p->tail;          // not tail->next
}

// returns true if the list is empty, false otherwise. 
// To clear a list, see List::clear.
bool empty(pList p) {
	return begin(p) == end(p);
}

// returns the number of nodes in the list container.
int size(pList p) {
	int count = 0;
	for (pNode c = begin(p); c != end(p); c = c->next, count++);
	return count;
}

// removes from the list a single node x given.
// This effectively reduces the container by one which is destroyed.
// It is specifically designed to be efficient inserting and removing 
// a node regardless of its positions in the list such as front, back 
// or in the middle of the list.
pNode erase(pList p, pNode x) {
	if (x == nullptr) return x;
	pNode node = x->prev;
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
	return node;
}

// returns the first node with a value found, nullptr otherwise.
pNode find(pList p, int val) {
	DPRINT(cout << ">find val=" << val << endl;);
	pNode c = begin(p);
	pNode e = end(p);
	for ( ; c != e; c = c->next)
		if (c->item == val) return c;
	DPRINT(cout << "<find - not found\n";);
	return nullptr;
}

// inserts a new node with val at the position of the node x.
// The new node is actually inserted in front of the node x.
// This effectively increases the list size by one.
void insert(pList p, pNode x, int val) {
	DPRINT(cout << ">insert val=" << val << endl;);
	pNode node = new Node{ val, x->prev, x };
	x->prev = x->prev->next = node;
	DPRINT(cout << "<insert\n";);
}

// removes the first node in the list.
// This destroys the removed node, and reduces its size by one. 
void pop_front(pList p) {
	DPRINT(cout << ">pop_front\n";);
	if (!empty(p)) erase(p, begin(p));
	DPRINT(cout << "<pop_front\n";);
}

// removes the last node in the list, and reduces the list size 
// by one. This destroys the removed node.
void pop_back(pList p) {
	DPRINT(cout << ">pop_back\n";);
	if (!empty(p)) erase(p, end(p)->prev);
	DPRINT(cout << "<pop_back\n";);
}

// removes the first node with val from the list and does nothing if not found.
// Unlike member function List::erase which erases a node by its position, 
// this function removes a node by its value.  
// Unlike pop(), pop_all() removes all the nodes with the value given.
void pop(pList p, int val) {
	DPRINT(cout << ">pop val=" << val << endl;);
	cout << "your code here \n";
	DPRINT(cout << "<pop\n";);
}

// removes from the list all the nodes with the same value given.
// This calls the destructor of these objects and reduces the list size
// by the number of nodes removed.  Unlike erase(), which erases a node 
// by its position, this function removes nodes by its value. 
// Unlike pop_all(), pop() removes the first occurrence of the node with
// the value given. 
void pop_all(pList p, int val) {
	DPRINT(cout << ">pop_all val=" << val << endl;);
	cout << "your code here \n";
	DPRINT(cout << "<pop_all\n";);
}

// deletes N number of nodes, starting from the end. 
// It deletes all the nodes if N is zero which is the default or out of 
// the range of the list.
// Since it simply calls pop_back() which is O(1) repeatedly, it is O(n).
void pop_backN(pList p, int N) {
	DPRINT(cout << ">pop_backN N=" << N << endl;);
	int psize = size(p);
	if (N <= 0 || N > psize) N = psize;
	for (int i = 0; i < N; i++) {
		cout << setw(7) << "\r\tdeleting in [" << i << "]";
		pop_back(p);
	}
	cout << "\n";
	DPRINT(cout << "<pop_backN\n";);
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by one.
void push_front(pList p, int val) {		// inserts a node at front of list
	DPRINT(cout << ">push_front val=" << val << endl;);
	insert(p, begin(p), val);
	DPRINT(cout << "<push_front\n";);
}

// adds a new node with val at the end of the list and returns the 
// first node of the list. This effectively increases the list size by one.
void push_back(pList p, int val) {
	DPRINT(cout << ">push_back val=" << val << endl;);
	insert(p, end(p), val);
	DPRINT(cout << "<push_back\n";);
}

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list. 
// This effectively increases the container size by one.
void push(pList p, int val, int x) {
	DPRINT(cout << ">push val=" << val << endl;);
	cout << "your code here \n";

	DPRINT(cout << "<push\n";);
}

// adds N number of new nodes at the end of the list, O(1)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
void push_backN(pList p, int N) {
	DPRINT(cout << ">push_backN N=" << N;);

	int range = N + size(p);
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		int val = rand() % range;
		push_back(p, val);
		cout << setw(7) << "\r\tinserting in [" << i << "]=" << val;
	}
	cout << "\n";

	DPRINT(cout << "<push_backN\n";);
}

// removes extra nodes that have duplicate values from the list.
// It removes all but the last node from every consecutive group of
// equal nodes in the list. Notice that a node is only removed from
// the list if it compares equal to the node immediately preceding it. 
// Thus, this function is especially useful for sorted lists. O(n)
void unique(pList p) {
	DPRINT(cout << ">unique N=" << size(p) << endl;);
	if (size(p) <= 1) return;

	cout << "your code here \n";

	DPRINT(cout << "<unique";);
}

// reverses the order of the nodes in the list. 
// The entire operation does not involve the construction, destruction 
// or copy of any element object. Nodes are not moved, but pointers
// are moved within the list. O(n)
void reverse(pList p) {
	DPRINT(cout << ">reverse\n";);
	if (size(p) <= 1) return;

	// hint: swap prev and next in every node including head & tail  
	// then, swap head and tail.  
	// hint: use while loop, don't use begin()/end()

	cout << "your code here \n";

	DPRINT(cout << "<reverse\n";);
}

//////////////////// sort /////////////////////////////////////////////
int ascending (int a, int b) { return a - b; };
int descending(int a, int b) { return b - a; };

// returns the node of which item is greater than x firstly encountered.
// returns the tail if not found.
pNode _more(pList p, int x) {
	pNode c;
	for (c = begin(p); c != end(p); c = c->next)
		if (c->item > x) return c;
	return c;
}

// returns the node of which item is smaller than x firstly encountered
// returns the tail if not found.
pNode _less(pList p, int x) {
	pNode c;
	for (c = begin(p); c != end(p); c = c->next)
		if (c->item < x) return c;
	return c;
}

// returns true if the list is sorted according to comp() function.
// com() function may be either ascending or descending.
bool sorted(pList p, int(*comp)(int a, int b)) {
	DPRINT(cout << ">sorted?\n";);
	if (size(p) <= 1) return true;

	pNode curr = begin(p);
	int item = curr->item;
	for (curr = curr->next; curr != end(p); curr = curr->next) {
		if (comp(item, curr->item) > 0) return false;
		item = curr->item;
	}
	DPRINT(cout << "<sorted: true\n";);
	return true;
}

// returns true if the list is sorted either ascending or descending.
bool sorted(pList p) {
	DPRINT(cout << ">sorted up or dn\n";);
	cout << "your code here \n";
	return true;
}

// returns a new list of nodes sorted in ascending order if not sorted.
// If the list is already sorted, it simply reverses the list such that 
// the ascending ordered list becomes a descending order list and 
// vice versa.   O(n)
pList sort(pList p) {
	DPRINT(cout << ">sort N=" << size(p) << endl;);
	cout << "your code here\n";

	pList newp = new List;
	cout << "your code here\n";

	DPRINT(cout << "<sort N=" << size(newp) << endl;);
	return newp;
}

// inserts a new node with val in sorted order
void push_sorted(pList p, int val) {
	DPRINT(cout << "<push_sorted val=" << val << endl;);
	cout << "your code here \n";
	DPRINT(cout << "<push_sorted\n";);
}

// inserts N number of nodes in sorted order
void push_sortedN(pList p, int N) {
	DPRINT(cout << "<push_sortedN N=" << N << endl;);

	cout << "your code here \n";

	cout << "\n";
	DPRINT(cout << "<push_sortedN\n";);
}


// shows the values of all the nodes in the list if all is true or 
// the list size is less than pmax * 2. If there are more than 
// (pmax * 2) nodes, then it shows only pmax number of nodes from 
// the beginning and the end in the list.
void show(pList p, bool all) {
	DPRINT(cout << "show(" << size(p) << ")\n";);
	if (empty(p)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}
	int i;
	int pmax = 10;   // a magic number, max number of items per line
	pNode curr;
	const int N = size(p);

	if (all || N < pmax * 2) {
		for (i = 1, curr = begin(p); curr != end(p); curr = curr->next, i++) {
			cout << " -> " << curr->item;
			if (i % pmax == 0) cout << endl;
		}
		return;
	}

	// print the first pmax items
	for (i = 1, curr = begin(p); curr != end(p) && i <= pmax; curr = curr->next, i++) {
		cout << " -> " << curr->item;
	}
	cout << "\n...left out...\n";
	// print the last pmax items
	// move the pointer to the place where pmax items are left.
	for (i = 0, curr = begin(p); i < (N - pmax); i++, curr = curr->next);
	for (i = 1; curr != end(p) && i <= pmax; curr = curr->next, i++) {
		cout << " -> " << curr->item;
	}
	cout << "\n";
}
