/**
* File: tree.cpp, tree.h, treenode.h
* implements a binary tree and/or binary search tree(BST).* and
* AVL(Adelson-Velskii and Landis) tree.
*
* A binary search tree BST is a type of binary tree where the nodes
* are arranged in order: for each node, all elements in its left
* subtree are less to to node and all the elements in its right
* subtree are greater than the node. Many operations are the same
* either in a binary tree or in a binary search tree.
*
* - Some functions work for a binary tree and/or for a BST.
* - The code works on the node structure 'tree' that makes up the tree.
* - The algorithm, typically recursive, that iterates over the tree
* - Using a pointer to a pointer as an argument have been avoided.
*   Instead the function is to return a new root node after an
*   insertionor deletion, then it returns the root node as a
*   returned value.
*
* 04/20/2014	Creation	Youngsup Kim, idebtor@gmail.com
* 04/15/2016	treeprint() added for clearer visualization of tree
* 05/01/2016	Added AVL tree
* 10/20/2016    Switching from/to BST and AVL tree
* 11/01/2016    Added stress tests
* 04/02/2019	C++ version 
*
* Usage:
*	tree root = nullptr;
*   root = grow(root, 5); // the first node is created
*                         // it becomes the root
*   root = grow(root, 7); // a new node is added
*   root = trim(root, 5); // if first node is removed,
*                         // the new root is returned
*/
#ifndef TREET_H
#define TREET_H

#include <vector>
#include "treenode_t.h"

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// Binary Tree ADT
template <typename T> int degree(tree<T> t); // returns the degree of a node(not tree)
template <typename T> int height(tree t);						// returns the height of a tree. 
template <typename T> int size(tree t);						// returns number of nodes in tree
template <typename T> int value(tree t);						// returns the key value in the node;
template <typename T> bool empty(tree t);						// true if tree is empty
template <typename T> tree clear(tree t);						// frees all nodes in a tree

template <typename T> bool contains(tree t, int key);			// a node with the key in BST?
template <typename T> bool containsBT(tree t, int key);		// a node with the key in BT?
template <typename T> bool containsIteration(tree t, int key);// contains() using iteration 

template <typename T> tree find(tree t, int key);				// returns a node with a key given in BST
template <typename T> tree findBT(tree t, int key);			// returns a node with a key given in BT
template <typename T> tree grow(tree t, int key);				// inserts a node with key                        
template <typename T> tree trim(tree t, int key);				// deletes a node with key
template <typename T> tree trimplus(tree t, int key);			// deletes a node with key balanced a bit
template <typename T> tree minimum(tree t);					// returns the left most leaf 
template <typename T> tree maximum(tree t);					// returns the right most leaf 
template <typename T> tree pred(tree t);						// returns max node in left subtree
template <typename T> tree succ(tree t);						// returns min node in right subtree 

template <typename T> void inorder(tree t, std::vector<int>& v);	 // traverses tree in inorder & returns keys
template <typename T> void inorder(tree t, std::vector<tree>& v);	 // traverses tree in inorder & returns nodes
template <typename T> void postorder(tree t, std::vector<int>& v); // traverses tree in postorder 
template <typename T> void preorder(tree t, std::vector<int>& v);	 // traverses tree in preorder 
template <typename T> void levelorder(tree t, std::vector<int>& v);// traverses tree in level-order 

template <typename T> bool isBST(tree t);						// checks whether it is BST or not
template <typename T> bool _isBST(tree t, int min, int max);	// helper function for isBST()
template <typename T> bool isBSTinOrder(tree root);			// in testing - using inorder traversal

////////////////////// AVL Tree /////////////////////////////////////////////
template <typename T> bool isAVL(tree t);					// returns true if AVL Tree
template <typename T> bool _isAVL(tree t);				// helper function for isAVL()

template <typename T> bool balanced(tree t);				// checks the balance factor 
template <typename T> int balanceFactor(tree t);			// height diff(left - right)
tree growAVL(tree t, int key);		// inserts a node with key
tree trimAVL(tree t, int key);		// deletes a node with key
tree buildAVL(int* v, int n);		// from an array of keys sorted - recreation
tree buildAVL(tree* v, int n);		// from an array of nodes sorted - recylcing
tree rebalance(tree t);				// rebalances at a node
tree rebalanceTree(tree root);	    // rebalances a tree repeatedly

///////////////// AVL/BST Tree Testing ////////////////////////////////////
tree growN(tree t, int N, bool AVLtree);	// grow N nodes
tree trimN(tree t, int N, bool AVLtree);	// trim N nodes

// rebuilds an AVL/BST tree using a sorted list of nodes or keys
tree buildAVL(tree* v, int n);              // v:a sorted list of nodes, n:size
tree buildAVL(int* v, int n);               // v:a sorted array of keys, n:size
											  
void randomN(int *arr, int N, int start);	// returns N random ints
void shuffle(int *arr, int N);				// shuffles the array
#endif