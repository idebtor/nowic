/**
* File: bstreeDriver.cpp
* tests the implementation of a binary search tree(BST).* and
* AVL(Adelson - Velskii and Landis) tree.
*
* 04/20/2014	Creation	Youngsup Kim, idebtor@gmail.com
* 04/15/2016	treeprint() added for clearer visualization of tree
* 05/01/2016	Added AVL tree
* 10/20/2016    Switching from/to BST and AVL tree
* 04/02/2019	C++ version, utilized stl::vector and stl::queue partially
*
* Usage:
*	tree root = nullptr;
*   root = grow(root, 5);	// the first node is created
*                           // it becomes the root
*   root = grow(root, 7);	// a new node is added
*   root = trim(root, 5);	// if first node is removed,
*                           // the new root is returned
*/
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include "nowic.h"
#include "tree.h"
using namespace std;

void treeprint(tree root); // print the tree on console graphically

/** returns a tree that builds from using command-line arguments */
tree build_tree_by_args(int argc, char *argv[], bool AVLtree) {
	if (argc <= 1) return nullptr;
	tree root = nullptr;

	int* bin = new (nothrow) int[argc];
	assert(bin != nullptr);

	for (int i = 0; i < argc - 1; i++)
		bin[i] = strtol(argv[i + 1], nullptr, 10);

	// using a function pointer 
	tree (*func)(tree, int) = AVLtree ? growAVL : grow;
	for (int i = 0; i < (argc - 1); i++) 
		root = func(root, bin[i]);

	delete[] bin;
	return root;
}

void print_treespecs(tree root) {
	cout << "\n\tMin: " << value(minimum(root)) << "   Max: " << value(maximum(root)) 
		 << "   Size: " << size(root) << "   Height: " << height(root) << endl;
}

int main(int argc, char **argv) {
	string menuBST = "Binary Search Tree[BST] Menu";
	string menuAVL = "Adelson-Velskii and Landis[AVL] Tree Menu";
	stringstream ss;
	tree node;
	vector<int> vec;
	bool AVLtree = false;
	int item, key;
	char c;

	tree root = argc < 2 ? nullptr : build_tree_by_args(argc, argv, AVLtree);
	treeprint(root);

	do {
		cout << "\n\t" << (AVLtree ? menuAVL : menuBST) << endl;
		cout << "\tg - grow\t"; 				
		(AVLtree ? cout << "\tb - rebalance\n": cout << "\ta - add a child(Use with caution)\n");
		cout << "\tt - trim\t"; 				cout << "\tf - find\n";
		if (!AVLtree) cout << "\t/ - trim plus\n";
		cout << "\tl - traverse\t"; 			cout << "\tm - min, max, size, height\n";
		cout << "\to - BST or AVL?\t";	 		cout << "\tp - predecessor, successor\n";
		cout << endl;
		cout << "\tx - grow N\t";				cout << "\ts - switch to [BST/AVL]\n";			 
		cout << "\ty - trim N\t";				cout << "\tc - clear\n";				
		c = GetChar("\tCommand(q to quit): ");
		switch (c) {
		case 'g': // grow
			item = GetInt("\tEnter a key to grow: ");
			root = AVLtree ? growAVL(root, item) : grow(root, item);
			break;

		case 'a': // add a child (Use with caution since it may become an invalid BST/AVL tree)
			key = GetInt("\tSelect a node(degree 0 or 1): ");
			node = findBT(root, key);
			if (node == nullptr) {
				cout << "\tEnter a key(" << key << ") is not found.\n";
				break;
			}
			
			if (degree(node) == 2) {
				cout << "\tThis subtree(" << key << ") is full.\n";
				break;
			}
		
			item = GetInt("\tEnter a key to grow: ");
			if (containsBT(root, item)) 
				cout << "\tThis key(" << item << ") is already in the tree.\n";
			else
				grow(node, item);
			break;

		case 'b':  // rebalance - only for AVL
			if (isAVL(root)) {
				cout << "\n\tIt is already an AVL Tree\n";
			}
			else {
				cout << "\tRebalancing it at root...\n";
				root = rebalanceTree(root);
			}
			break;

		case 't':  // trim
			if (empty(root)) break;
			item = GetInt("\tEnter a node to trim: ");
			root = AVLtree ? trimAVL(root, item) : trim(root, item);
			break;

		case '/':  // trim_plus
			if (empty(root)) break;
			item = GetInt("\tEnter a node to trim: ");
			root = AVLtree ? trimAVL(root, item) : trimplus(root, item);
			break;

		case 'f':  // find - contrainsBT
			if (empty(root)) break;
			item = GetInt("\tEnter a key to find: ");
			if (containsBT(root, item))
				cout << "\n\t" << item << " is found\n";
			else
				cout << "\n\t" << item << " is not found\n";
			break;

		case 'm': // min, max, size, height - BST/AVL
			if (!empty(root)) print_treespecs(root);
			break;

		case 'p': // predecessor and successor // BST/AVL
			if (empty(root)) break;
			node = pred(root);
			if (node) 
				cout << "\n\tPredecessor: " << value(node);
			else
				cout << "\n\tPredecessor: undefined";
			node = succ(root);
			if (node)
				cout << "\t\tSuccessor: " << value(node) << endl;
			else
				cout << "\t\tSucessor: undefined" << endl;
			break;

		case 'l': // list nodes // BT/BST/AVL
			cout << "\n\tinorder:    "; vec.clear(); inorder(root, vec); 
										for (int i : vec) cout << i << " "; 
			cout << "\n\tpreorder:   "; vec.clear(); preorder(root, vec); 
										for (int i : vec) cout << i << " ";
			cout << "\n\tpostorder:  "; vec.clear(); postorder(root, vec); 
										for (int i : vec) cout << i << " ";
			cout << "\n\tlevelorder: "; vec.clear(); levelorder(root, vec); 
										for (int i : vec) cout << i << " ";		
			break;
		case 'o': // BT/BST/AVL
			if (empty(root)) break;
			cout << "\n\tBST: " << (isBST(root) ? "true" : "false") << endl;
			cout << "\tAVL: " << (isAVL(root) ? "true" : "false") << endl;
			break;
		case 'c': // BT/BST/AVL
			root = clear(root);
			break;
		case 's':  // switch to[BST / AVL]
			if (AVLtree)
				AVLtree = false;
			else {
				if (!isBST(root)) {
					cout << "\n\tIt is not a BST, can not be changed to AVL tree.\n";
					break;
				}
				if (!isAVL(root)) {
					cout << "\n\tIt is unbalanced AVL Tree\n";
					cout << "\tRebalancing it at root...\n";
					root = rebalanceTree(root);
				}
				if (isAVL(root)) AVLtree = true;
			}
			break;
		case 'x':
			item = GetInt("\tEnter a number of nodes to grow: ");
			root = growN(root, item, AVLtree);
			if (!empty(root)) print_treespecs(root);
			break;

		case 'y':
			ss << "\tEnter a number of nodes to trim(max=" << size(root) << "): ";
			item = GetInt(ss.str());
			ss.str("");
			root = trimN(root, item, AVLtree);
			if (!empty(root)) print_treespecs(root);
			break;

		case 'q':
			break;
		}
		cout << endl; 
		treeprint(root);
	} while (c != 'q');

	clear(root);
	cout << "\n\tJoyful Coding!\n";
	return EXIT_SUCCESS;
}


