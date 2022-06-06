/**
* File: heapprint.cpp
*	converts a heap data structure in an array into a complete
*	binary tree and invokes treeprint() in treeprint.cpp
*
* @Author	Youngsup Kim, idebtor@gmail.com
* 05/05/2016	Creation
* 05/05/2019	Simplified using std::queue
*
* Algorithm to build a binary tree(BT) from a complete binary tree(CBT).
* 0. If the CBT size is zero, return a nullptr.
* 1. initialize the tree (BT) with the first key from CBT
* 2. queue the tree root node.
* 3. Loop until the queue is empty
*    Get a next key from the CBT
*    Get the front node in the queue.
*    If the left child of this front node doesn¡¯t exist,
*        set the left child as the new node.
*	 else if the right child of this front node doesn¡¯t exist,
*        set the right child as the new node.
* 4. If the front node has both the left child and right child,
*        dequeue() it.
* 5. enqueue() the new node.
*/

#include <iostream>
#include <cassert>
#include <queue>
#include <cmath>
#include "heap.h"
#include "treenode.h"
using namespace std;

// import treeprint functions
void treeprint(tree t);
void treeprint_levelorder(tree root);
void treeprint_levelorder_tasty(tree root);

// frees all nodes while traversing the tree like postorder
tree clear(tree t) {
	if (t) {
		clear(t->left);
		clear(t->right);
		delete t;
	}
	return nullptr;
}

// build binary tree from CBT using recursion
tree buildBT(int *nodes, int i, int n) {
	DPRINT(std::cout << " buildBT i=" << i << " n=" << n << std::endl;);
	if (i > n) return nullptr;

	tree root = new TreeNode{ nodes[i] };
	root->left = buildBT(nodes, i * 2, n);
	root->right = buildBT(nodes, i * 2 + 1, n);

	return  root;
}

// build binary tree from CBT using queue
tree buildBT(heap p) {
	std::queue<tree> que;
	int N = size(p);
	tree root = new TreeNode{ p->nodes[1] };
	que.push(root);

	for (int i = 2; i <= N; i++) {
		tree node = new TreeNode{ p->nodes[i] };
		tree front = que.front();
		if (front->left == nullptr)		  // if left is empty, set the node at left 
			front->left = node;
		else if (front->right == nullptr) // if right is emoty, set the node at right
			front->right = node;

		if (front->left && front->right)  // if full, pop it since it's done!
			que.pop();

		que.push(node);                   // enqueue the node to insert later
	}
	return root;
}

// print a heap using treeprint() - must build a tree to call treeprint() functions
void heapprint(heap p, int mode) {
	DPRINT(cout << ">heapprint\n";);
	if (empty(p)) return;
	tree root = nullptr;

	if (size(p) % 2 == 0) {
		cout << "\t[Tree built using recursion]\n";
		root = buildBT(p->nodes, 1, size(p));  // using recursion
	}
	else {
		cout << "\t[Tree built using iteration]\n";
		root = buildBT(p);						// using iteration
	}

	if (size(p) >= 1000) {  // a magic number
		cout << "\tThere are 1,000 nodes and more, the print mode goes into ...\n";
		mode = TASTY_MODE;
	}

	// TASTY_MODE: show just the first and last three levels each 
	if ((height(p) + 1) < 7 && mode == TASTY_MODE) // height + 1 = level, 
		mode = LEVEL_MODE;

	switch (mode) {
	case TREE_MODE:
		treeprint(root);
		break;
	case LEVEL_MODE:
		treeprint_levelorder(root);
		break;
	default: // TASTY_MODE: show just the first and last three levels each
		treeprint_levelorder_tasty(root);
		cout << endl;
	}

	clear(root);
	DPRINT(cout << "<heapprint\n";);
}


/*****
void heapprint_level(heap p) {
	DPRINT(std::cout << ">heapprint_level\n";);
	if (empty(p)) return;
	int N = size(p);                   // number of nodes, N is the last index
	int max_level = height(N);         // total number of levels, starting at 1
	int i = 1;
	while (i <= N) {
		for (int level = 0; level < max_level; level++) {
			int n = (int)pow(2, level);            // n is max nodes per level
			std::cout << "[" << i << "] ";
			for (int k = 0; k < n && i <= N; k++)   // display one level
				std::cout << p->nodes[i++] << " ";
			std::cout << std::endl;
		}
	}
	DPRINT(std::cout << "<heapprint_level\n";);
}
******/

