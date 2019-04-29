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

pNode last(pList p) {
	return p->tail->prev;
}

// returns the first node of the second half of the list.
// If the number of nodes are odd, it returns the one at the center.
// For even numbers, it returns the first node of the second half.
// For example, for list [0, 1, 2, 3, 4, 5, 6, 7], it returns 4.
pNode half(pList p) {

	cout << "your code here. ";

	return nullptr;
}

// returns the first node with val found, the tail sentinel node 
// returned by end(p) if not found. O(n)
pNode find(pList p, int val) {
	DPRINT(cout << ">find val=" << val << endl;);
	pNode c = begin(p);
	for (; c != end(p); c = c->next)
		if (c->item == val) return c;

	DPRINT(cout << "<find - not found\n";);
	return c;
}

// Removes all elements from the list container(which are destroyed),
// and leaving the container with a size of 0.
void clear(pList p) {
	if (empty(p)) return;

	DPRINT(cout << ">clear: ";);
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
	cout << "\tAll things are cleared.\n";
}

// returns true if the list is empty, false otherwise. 
// To clear a list, see List::clear.
bool empty(pList p) {
	return begin(p) == end(p);
}

// returns the number of nodes in the list container.
int size(pList p) {
	int count = 0;
	for (pNode c = begin(p); c != end(p); c = c->next)
		count++;
	return count;
}

//////////////////////////////////////////////////////////////////////////
/////////// Make the best use of the following two fucntions  ////////////
///////////         insert() and erase()                      ////////////
//////////////////////////////////////////////////////////////////////////
// inserts a new node with val at the position of the node x.
// The new node is actually inserted in front of the node x.
// This effectively increases the list size by one. O(1)
void insert(pNode x, int val) {
	DPRINT(cout << ">insert val=" << val << endl;);
	pNode node = new Node{ val, x->prev, x };
	x->prev = x->prev->next = node;
	DPRINT(cout << "<insert\n";);
}

// removes from the list a single node x given.
// This effectively reduces the container by one which is destroyed.
// It is specifically designed to be efficient inserting and removing 
// a node regardless of its positions in the list such as front, back 
// or in the middle of the list. O(1)
void erase(pNode x) {
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}

void erase(pList p, pNode x) {	// checks if x is either tail or head
	if (x == p->tail || x == p->head || x == nullptr) return;
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}
///////////////////////////////////////////////////////////////////////////

/////////////////////// pop ///////////////////////////////////////////////
// removes the first node in the list. O(1)
void pop_front(pList p) {
	DPRINT(cout << ">pop_front\n";);
	if (!empty(p)) erase(begin(p));
	DPRINT(cout << "<pop_front\n";);
}

// removes the last node in the list. O(1)
void pop_back(pList p) {
	DPRINT(cout << ">pop_back\n";);
	if (!empty(p)) erase(end(p)->prev);
	DPRINT(cout << "<pop_back\n";);
}

// removes the first node with val and does nothing if not found.
// Unlike member function List::erase which erases a node by its 
// position. Unlike pop(), pop_all() removes all the nodes with 
// the value given.
void pop(pList p, int val) {
	DPRINT(cout << ">pop val=" << val << endl;);
	cout << "your code here\n";

	DPRINT(cout << "<pop\n";);
}

// removes all the nodes with the same value given. O(n)
// This goes through the list once, not multiple times. Unlike 
// erase(), which erases a node by its position node, this function 
// removes nodes by its value. Unlike pop_all(), pop() removes the
// first node with the value given. 
void pop_all(pList p, int val) {
	DPRINT(cout << ">pop_all val=" << val << endl;);
	cout << "your code here\n";
#if 0
	// O(n) 
	for (pNode c = begin(p); c != end(p); c = c->next) {


	}
#endif

#if 1
	// O(n^2)
	while (find(p, val) != end(p)) {
		pop(p, val);
	}
#endif
	DPRINT(cout << "<pop_all\n";);
}

// deletes N number of nodes, starting from the end. 
// It deletes all the nodes if N is zero which is the default 
// or out of the range of the list.  Since it simply calls 
// pop_back() which is O(1) repeatedly, it is O(n).
void pop_backN(pList p, int N) {
	DPRINT(cout << ">pop_backN N=" << N << endl;);
	int psize = size(p);
	if (N <= 0 || N > psize) N = psize;
	for (int i = 0; i < N; i++) {
		if (i % 10000 == 0)
			cout << setw(7) << "\r\tdeleting in [" << psize - i - 1 << "]        ";
		pop_back(p);
	}
	cout << "\n";
	DPRINT(cout << "<pop_backN\n";);
}

/////////////////////// push ///////////////////////////////////////////////
// inserts a new node with val at the beginning of the list. O(1)
void push_front(pList p, int val) {		// inserts a node at front of list
	DPRINT(cout << ">push_front val=" << val << endl;);
	insert(begin(p), val);
	DPRINT(cout << "<push_front\n";);
}

// adds a new node with val at the end of the list and returns the 
// first node of the list. O(1)
void push_back(pList p, int val) {
	DPRINT(cout << ">push_back val=" << val << endl;);
	insert(end(p), val);
	DPRINT(cout << "<push_back\n";);
}

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list. 
// This effectively increases the container size by one.
void push(pList p, int val, int x) {
	DPRINT(cout << ">push val=" << val << endl;);
	cout << "your code here\n";
	DPRINT(cout << "<push\n";);
}

// adds N number of new nodes at the end of the list. O(n)
// if val == 0, the values for new nodes are randomly generated in the 
// range of [0..(N + size(p))]. Otherwise, simply insert the same val 
// for N times.
void push_backN(pList p, int N, int val) {
	DPRINT(cout << ">push_backN N=" << N;);
	int psize = size(p);

	if (val == 0) {
		int range = N + psize;
		srand((unsigned)time(NULL));
		for (int i = 0; i < N; i++) {
			int val = (rand() * RAND_MAX + rand()) % range;
			push_back(p, val);
			if (i % 10000 == 0)
				cout << setw(7) << "\r\tinserting in [" << i + psize << "]=" << val << "        ";
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			push_back(p, val);
			if (i % 10000 == 0)
				cout << setw(7) << "\r\tinserting in [" << i + psize << "]=" << val << "        ";
		}
	}
	cout << "\n";

	DPRINT(cout << "<push_backN\n";);
}

/////////////////////// unique, reverse, shuffle ///////////////
// removes extra nodes that have duplicate values from the list.
// It removes all but the first node from every consecutive group 
// of equal nodes. Notice that a node is only removed from the 
// list if it compares equal to the node immediately preceding it. 
// Thus, this function is especially useful for sorted lists. O(n)
void unique(pList p) {
	DPRINT(cout << ">unique N=" << size(p) << endl;);
	if (size(p) <= 1) return;

	cout << "your code here\n";

	DPRINT(cout << "<unique";);
}

// reverses the order of the nodes in the list. 
// The entire operation does not involve the construction, 
// destruction or copy of any element. Nodes are not moved, 
// but pointers are moved within the list. O(n)
void reverse(pList p) {
	DPRINT(cout << ">reverse\n";);
	if (size(p) <= 1) return;

	// hint: swap prev and next in every node including head & tail  
	// then, swap head and tail.  
	// hint: use while loop, don't use begin()/end()

	cout << "your code here\n";
	
	DPRINT(cout << "<reverse\n";);
}

// returns so called "perfectly shuffled" list. 
// The first half and the second half are interleaved each other. 
// The shuffled list begins with the second half of the original p.
// For example, 1234567890 returns 6172839405.
void shuffle(pList p) {
	DPRINT(cout << ">shuffle\n";);
	if (size(p) <= 1) return;    // nothing to shuffle

	// find the mid node of the list p to split it into two lists.
	// remove 1st half from the list p, and keep it as a list "que". 
						// the que does not have sentinel nodes
						// set the last node of que terminated by null

	// set the list p head such that it points the "mid" of the list p. 
					 // the list "mid" becomes the list p.
					 // the list "mid" now has two sentinel nodes

	// interleave nodes in the "que" into "mid" in the list of p.
	// start inserting 1st node in "que" at 2nd node in "mid".

	cout << "your code here\n";

	DPRINT(cout << "<shuffle\n";);
}

///////////////////////// sort /////////////////////////////////////////////
int ascending (int a, int b) { return a - b; };
int descending(int a, int b) { return b - a; };
int more(int a, int b) { return (a - b); }
int less(int a, int b) { return (b - a); }

// returns the node of which value is larger than x found first, 
// the tail sentinel node which is returned by end(p) otherwise. 
pNode _more(pList p, int x) {
	pNode c = begin(p);
	for (; c != end(p); c = c->next)
		if (c->item > x) return c;
	return c;
}

// returns the node of which value is smaller than x found first, 
// the tail sentinel node which is returned by end(p) otherwise. 
pNode _less(pList p, int x) {
	pNode c = begin(p);
	for (; c != end(p); c = c->next)
		if (c->item < x) return c;
	return c;
}

// returns true if sorted either by either ascending or descending 
bool sorted(pList p) {
	DPRINT(cout << ">sorted up or dn\n";);
	return sorted(p, ascending) || sorted(p, descending);
}

// returns true if sorted according to comp fp provided
bool sorted(pList p, int(*comp)(int a, int b)) {
	DPRINT(cout << ">sorted?\n";);
	if (size(p) <= 1) return true;

	cout << "your code here\n";

	DPRINT(cout << "<sorted: true\n";);
	return true;
}

// inserts a node with val in sorted in the "sorted" list. O(n)
void push_sorted(pList p, int val) {
	DPRINT(cout << "<push_sorted val=" << val << endl;);
	cout << "your code here\n";
	DPRINT(cout << "<push_sorted\n";);
}

// inserts N number of nodes in sorted in the sorted list.
// If you invoke push_sort() by N times, it takes longer. Therefore, 
// don't call push_sort() N timee. But if you may follow something 
// like push_sort(), its time complexity will be O(n^2) or larger. 
// The values for new nodes are randomly generated in the range of 
// [0..(N + size(p))]. For mac users, you use rand(). For pc, use 
// (rand() * RAND_MAX + rand()) instead of rand(). 
void push_sortedN(pList p, int N) {
	DPRINT(cout << "<push_sortedN N=" << N << endl;);

	int psize = size(p);
	int range = N + psize;

	srand((unsigned)time(NULL));	// initialize random seed

	cout << "your code here\n";
#if 0
	// O(n^2) implment your code here for O(n^2)
	// Refer to push_sorted(), but don't invoke push_sorted().

#endif

#if 1
	// O(n^3) Don't implement somethig like this, but in O(n^2).
	for (int i = 0; i < N; i++) {
		int val = (rand() * RAND_MAX + rand()) % range;
		if (sorted(p, ascending)) {
			pNode node = _more(p, val);
			insert(node, val);
		}
		else {
			pNode node = _less(p, val);
			insert(node, val);
		}
	}
#endif
	DPRINT(cout << "<push_sortedN\n";);
}

// inserts N number of nodes in sorted in the sorted list.
// The goal of this function is to make it O(n log n). 
// Algorithm:
// 1. Generate N numbers to insert. Let's name this array, vals.
// 2. Sort vals using quicksort() of which time complexity 
//    is O(n log n), in ascending or descending depending on 
//    the list. .
// 3. Merge two lists. - This process is O(n).
//    Compare two values from the list and vals one by one. 
//    For example, if sorted ascending and vals is smaller, 
//    insert the vals into the list and go for the next val.
//    the list pointer does not increment. 
//    If vals is larger, then the list pointer increment, but
//    vals index does not increment. 
// 4. If the list is exhausted, then exit the loop. If vals
//    is not exhausted, insert the rest of vals at the end 
//    of the list.
//    Make sure that you go through a loop the list and vals
//    together once. This is the same concept used in the 
//    most famous "mergesort" algorithm except recursion. 
// The values for new nodes are randomly generated in the range of 
// [0..(N + size(p))]. For mac users, you use rand(). For pc, use 
// (rand() * RAND_MAX + rand()) instead of rand(). 
void push_sortedNlog(pList p, int N) {
	DPRINT(cout << "<push_sortedNlog N=" << N << endl;);

	int psize = size(p);
	int range = N + psize;
	int* vals = new int[N];

	cout << "your code here\n";

	delete[] vals;
	DPRINT(cout << "<push_sortedNlog\n";);
}

// returns a list of nodes sorted in ascending order if not 
// sorted by default, using bubble or selection sort algorithm 
// which is O(n^2). 
// If the list is already sorted, it reverses the list such that 
// the ascending ordered list becomes a descending order list and 
// vice versa. It is O(n). 
// In the bubble sort, it checks values of two adjacent node 
// whether they are in ascending order or not, if not then we 
// swap the value. It does this until every element get its right 
// position.  In 1st pass the largest value get its right position 
// and in 2nd pass 2nd largest value get its position and in 3rd 
// pass 3rd largest element get its position and so on. 
void sort(pList p) {
	DPRINT(cout << ">sort N=" << size(p) << endl;);
	if (sorted(p)) return reverse(p);
	bubbleSort(p);
}

///////////////////////// show /////////////////////////////////////////////
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
		if (N % pmax != 0) cout << endl;
		return;
	}

	// print the first pmax items
	for (i = 1, curr = begin(p); curr != end(p) && i <= pmax; curr = curr->next, i++) 
		cout << " -> " << curr->item;
	
	if (N > pmax * 2)
		cout << "\n...left out..." << half(p)->item << "...left out...\n";
	else
		cout << "\n";

	// print the last pmax items
	// move the pointer to the place where pmax items are left.
	for (i = 0, curr = begin(p); i < (N - pmax); i++, curr = curr->next);
	for (i = 1; curr != end(p) && i <= pmax; curr = curr->next, i++) 
		cout << " -> " << curr->item;
	cout << "\n";
}
