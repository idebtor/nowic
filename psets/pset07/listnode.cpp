//  listnode.cpp
//  Created by idebtor@gmail.com on December 12, 2018.
/*
* Description:	This program implements a simple linked list of nodes
* without a head structure and without sentinel nodes. It simply links
* node to node. The caller is responsible for maintaining the the first
* (head) element of the list. Most functions need the first node to work
* with the list and returns the first node of the list since the first
* may be changed inside of the function.
*/
#include <iomanip>
#include <cstdlib>
#include <stack>
#include "listnode.h"

#if 0
// a basic stack functinality only provided for pedagogical purpose
// To use STL stack, just comment out this section and inclucde <stack> above.
#include <vector>
template <typename T>
struct stack {
	vector<T> data;

	bool empty() const {
		return data.empty();
	}
	auto size() const {
		return data.size();
	}
	void push(T const& item) {
		data.push_back(item);
	}
	void pop() {
		if (data.empty())
			throw out_of_range("stack<>::pop(): pop stack");
		data.pop_back();
	}
	T top() const {
		if (data.empty())
			throw out_of_range("stack<>::top(): top stack");
		return data.back();
	}
};
#endif

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p) {
	if (empty(p)) return nullptr;
	DPRINT(cout << "clear: ";);

	pNode curr = p;
	while (curr != nullptr) {
		pNode prev = curr;
		curr = curr->next;
		DPRINT(cout << prev->data << " ";);
		delete prev;
	}
	cout << "\n\tAll things are cleared. Happy Coding!\n";
	return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p) {
	if (empty(p)) return 0;
	int count = 0;
	for (pNode c = p; c != nullptr; c = c->next, count++);
	return count;
}

// returns the last node of in the list.
pNode last(pNode p) {
	if (empty(p)) return nullptr;
	while (p->next != nullptr) p = p->next;
	return p;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p) {
	return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by one.
Node* push_front(Node* p, int val) {
	DPRINT(cout << "><push_front val=" << val << endl;);
	if (empty(p)) return new Node{ val };
	return new Node{ val, p };
}

// adds a new node with val at the end of the list and returns the
// first node of the list. This effectively increases the list size by one.
pNode push_back(pNode p, int val) {
	DPRINT(cout << "><push_back val=" << val << endl;);

	cout << "your code here \n";

	return p;
}

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list.
// This effectively increases the container size by one.
pNode push(pNode p, int val, int x) {
	if (empty(p)) return push_front(p, val);
	if (p->data == x) return push_front(p, val);

	pNode curr = p;
	pNode prev = nullptr;
	cout << "your code here \n";
	return p;
}

// returns an extended random number of which the range is from 0
// to (RAND_MAX + 1)^2 - 1. // We do this since rand() returns too 
// small range [0..RAND_MAX) where RAND_MAX is usually defined as 
// 32767 in cstdlib. Refer to the following link for details
// https://stackoverflow.com/questions/9775313/extend-rand-max-range
unsigned long rand_extended(int range) {
	if (range < RAND_MAX) return rand();
	return rand() * RAND_MAX + rand();
}

// adds N number of new nodes at the front of the list, O(n)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
Node* push_frontN(Node* p, int N) {
	DPRINT(cout << ">push_front N = " << N << endl;);

	int range = N + size(p);
	srand((unsigned)time(nullptr));

	cout << "your code here \n";

	DPRINT(cout << "<push_front N = " << N << endl;);
	return p;
}

// adds N number of new nodes at the end of the list, O(n)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
// Since it simply calls push_back() repeatedly, it is O(N^2).
pNode push_backN(pNode p, int N) {
	DPRINT(cout << ">push_backN N=" << N << " RAND_MAX=" << RAND_MAX << endl;);

	int range = N + size(p);
	srand((unsigned)time(NULL));

	cout << "your code here \n";

	DPRINT(cout << "<push_backN size=" << size(p) << endl;);
	return p;
}

// adds N number of new nodes at the front or back of the list.
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))]. 
// push_fp should be either a function pointer to push_front() 
// or push_back().
Node* push_N(Node* p, int N, Node* (*push_fp)(Node*, int)) {
	DPRINT(cout << ">push_N = " << N << endl;);

	int range = N + size(p);
	srand((unsigned)time(nullptr));

	cout << "your code here \n";

	DPRINT(cout << "<push_N = " << N << endl;);
	return p;
}

// removes the first node in the list and returns the new first node.
// This destroys the removed node, effectively reduces its size by one.
pNode pop_front(pNode p) {
	DPRINT(cout << ">pop_front size=" << size(p) << endl;);

	cout << "your code here \n";

	return p;
}

// removes the last node in the list, effectively reducing the
// container size by one. This destroys the removed node.
pNode pop_back(pNode p) {
	DPRINT(cout << ">pop_back size=" << size(p) << endl;);
	if (empty(p)) return nullptr;

	cout << "your code here \n";

	DPRINT(cout << "<pop_back size=" << size(p) << endl;);
	return p;
}

// deletes N number of nodes, starting from the end.
// It deletes all the nodes if N is zero which is the default or out of
// the range of the list.
// Since it simply calls pop_back() which is O(n) repeatedly, it is O(N^2).
pNode pop_backN(pNode p, int N) {
	DPRINT(cout << ">pop_backN N=" << N << endl;);

	cout << "your code here \n";

	DPRINT(cout << "<pop_backN size=" << size(p) << endl);
	return p;
}

// deletes N number of nodes, starting from the beginning of the list. 
// It deletes all the nodes if N is zero which is the default or out of 
// the range of the list.
// Since it simply calls pop_front() which is O(1) repeatedly, it is O(n).
Node* pop_frontN(Node* p, int N) {
	DPRINT(cout << ">pop_frontN N=" << N << endl;);

	int psize = size(p);
	if (N <= 0 || N > psize) N = psize;
	for (int i = 0; i < N; i++) {
		if (i % 1000 == 0 || i < 1000)
			cout << setw(7) << "\r\tpoping[" << psize - i - 1 << "]            ";
		p = pop_front(p);
	}
	cout << "\n";
	DPRINT(cout << "<pop_backN size=" << size(p) << endl);
	return p;
}

Node* pop_N(Node* p, int N, Node* (*pop_fp)(Node*)) {
	DPRINT(cout << ">pop_N N=" << N << endl;);

	cout << "your code here \n";

	DPRINT(cout << "<pop_N size=" << size(p) << endl);
	return p;
}

// removes the first occurrence of the node with val from the list
pNode pop(pNode p, int val) {
	DPRINT(cout << ">pop val=" << val << endl;);
	if (empty(p)) return nullptr;    // nothing to delete

	if (p->data == val) return pop_front(p);

	cout << "your code here \n";

	DPRINT(cout << "<pop size=" << size(p) << endl;);
	return p;
}

// reverses a singly-linked list and returns the new head. The last node
// becomes the head node. Since it goes through the list once, the time
// complexity of this function is O(n).
pNode reverse(pNode head) {
	if (empty(head)) return nullptr;    // nothing to reverse

	pNode prev = nullptr;
	pNode curr = head;
	cout << "your code here \n";

	return nullptr;
}

// reverses a singly-linked list using stack and returns the new head. 
// The last node becomes the head node. This function pushes all of its 
// nodes onto a stack. Then top/pop stack and relink the nodes again. 
// It does not create any new node, but recycles and relink them.
// Even though it goes through the list twice and take a longer than 
// in-place reverse algorithm, its time complexity is still O(n), 
// but the space complexity is O(n). 
Node* reverse_using_stack(Node* head) {
	if (empty(head)) return nullptr;    // nothing to reverse
	stack<Node*> s;
	Node* curr = head;

	cout << "your code here \n";

	return head;
}

// reverses a singly-linked list and returns the new head. The last node
// becomes the head node. Since it goes through the list once, the time 
// complexity of this function is O(n), and the space complexity is O(1).
Node* reverse_in_place(Node* head) {
	if (empty(head)) return nullptr;    // nothing to reverse
	Node* prev = nullptr;
	Node* curr = head;

	cout << "your code here \n";

	return prev;
}

// reverses elements in sub-lists of odd numbers using stack and push_back().
// Since this uses push_back(), its time complexity becomes O(n^2). 
// Additionally, it recreates all nodes again because it is using push_back(). 
// Given a linked list that contains N integers, perform the following 
// reverse operation on the list: 
// Select all the sub groups of the list that contain only odd integers.
// For example, if the list is {1, 2, 3, 9, 7, 8, 5, 11}, then the 
// selected sub groups will be {3, 9, 7} and {5, 11}. 
// Reverse elements in the selected sub groups such as {7, 9, 3} and {11, 5}.
// Now, this function returns the original list except odd numbers reversed.
// In this example, it returns {1, 2, 7, 9, 3, 8, 11, 5}
Node* reverse_odd2(Node* head) {
	DPRINT(cout << ">reverse_odd2 begins.\n";);
	if (empty(head)) return nullptr;
	stack<int> ostack;      // odd_stack to save odds temporarily
	Node* head1 = head;     // save the original head to clear later
	Node* head2 = nullptr;  // new list of odds reversed 

	while (head != nullptr) {
		if (head->data % 2 == 1) {
			DPRINT(cout << " stack push: " << head->data << endl;);
			cout << "your code here \n";
			continue;
		}
		// an even number encountered
		// if ostack is not empty, top/pop and add it(odd) to head2
		while (!ostack.empty()) {
			DPRINT(cout << " head2 push_back(stack): " << ostack.top() << endl;);
			cout << "your code here \n";
		}
		DPRINT(cout << " head2 push_back(head): " << head->data << endl;);
		cout << "your code here \n";
	} // all scanned now
	DPRINT(cout << " original list all scanned\n";);
	DPRINT(cout << " odds stack size = " << ostack.size() << endl;);
	// get left-over at odd stack if any, and add them head2 
	cout << "your code here \n";

	// free the original list if necessay
	cout << "your code here \n";
	DPRINT(cout << "<reverse_odd2 returns.\n";);
	return head2;
}

// reverses elements in sub-lists of odd numbers using stack only.
// It does not use push_back() to achieve its time complexity of O(n).
// It does not create new nodes, but recycles the original nodes of 
// the list and relink them appropriately. It maintains the head2 node as 
// well as tail2 node such that it can relink the existing node at the 
// back(or tail) in O(1), while scanning the original list once. 
//
// Given a linked list that contains N integers, perform the following 
// reverse operation on the list: 
// Select all the sub groups of the list that contain only odd integers.
// For example, if the list is {1, 2, 3, 9, 7, 8, 5, 11}, then the 
// selected sub groups will be {3, 9, 7} and {5, 11}. 
// Reverse elements in the selected sub groups such as {7, 9, 3} and {11, 5}.
// Now, this function returns the original list except odd numbers reversed.
// In this example, it returns {1, 2, 7, 9, 3, 8, 11, 5}
Node* reverse_oddn(Node* head) {
	DPRINT(cout << ">reverse_oddn begins.\n";);
	if (empty(head)) return nullptr;

	stack<Node*> ostack;   // stack to save odds temporarily
	Node* head2 = nullptr;  // new list head of odds reversed 
	Node* tail2 = nullptr;  // the last element of head2 list

	cout << "your code here\n";

	// get left-over at odd stack if any, and add them head2

	cout << "your code here\n";

	DPRINT(cout << "<reverse_oddn returns.\n";);
	return head2;
}

// shows the values of all the nodes in the list if all is true or
// the list size is less than or equal to show_n * 2. If there are more than
// (show_n * 2) nodes, then it shows only show_n number of nodes from
// the beginning and the end in the list.
void show(pNode p, bool all, int show_n) {
	DPRINT(cout << "show(" << size(p) << ")\n";);
	if (empty(p)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}
	int i;
	pNode curr;
	const int N = size(p);

	if (all || N < show_n * 2) {
		for (i = 1, curr = p; curr != nullptr; curr = curr->next, i++) {
			cout << " -> " << curr->data;
			if (i % show_n == 0) cout << endl;
		}
		return;
	}

	// print the first show_n items
	cout << "your code here \n";

	cout << "\n...left out...\n";
	// print the last show_n items
	// move the pointer to the place where show_n items are left.

	cout << "your code here \n";

	cout << "\n";
}
