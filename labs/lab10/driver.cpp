
/// File: treeDriver.cpp
/// tests the implementation of a binary search tree(BST)./// and
/// AVL(Adelson - Velskii and Landis) tree.
///
/// author: idebtor@gmail.com
///
/// Usage:
///   tree left = new TreeNode(1);
///   tree right = new TreeNode(2);
///   tree root = new TreeNode(3, left, right);
/// or   
///   tree root = grow(nullptr, 2);
///   root = grow(root, 1);
///   root = grow(root, 3);	// a new node is added
///   root = trim(root, 5);	// if first node is removed,
///                           // the new root is returned
/// Note:
/// Creating or rebalancing tree with a lot of nodes requires a large stack.
/// For example, with 16M (or 16777216) stack, I was able to create a tree 
/// with two million nodes and rebalance it. 
///
/// For visual studio: Project Properties->Linkers->System->Stack Reserve Size
///
/// For g++/MinGW cmd windows, the following command set the stack size to 16M.
///   g++ -Wl,--stack,16777216 listdsDriver.cpp listdsx.cpp .......
/// To check the stack size on Windows, you may use dumpbin that comes with VS
///
/// For Mac OSX
///    g++ -Wl,-stack_size,0x1000000 listdsDriver.cpp listdsx.cpp .......
/// To check the stack size on OSX
///    otool -lv _exefile_name | grep stack
////
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <ctime>
#include "nowic.h"
#include "tree.h"
using namespace std;

void treeprint(tree root);				// print tree on console graphically
void treeprint_levelorder(tree root);	// print tree in levelorder
void treeprint_levelorder_tasty(tree root);	// print tree in levelorder

// returns a tree built by command-line arguments, for example 5 7 3 8 2 6 4 
tree build_tree_by_args(int argc, char *argv[], int& tree_type) {
	if (argc < 2) return nullptr;

	string arg(argv[1]);
	if (arg == "-b")
		tree_type = BT_MODE;
	else if (arg == "-s")
		tree_type = BST_MODE;
	else if (arg == "-a")
		tree_type = AVL_MODE;
	else {
		cout << "Usage: tree -[bsa] n1 n2 n3 ... \n";
		cout << "Usage:        b for BT, s for BST, and a for AVL \n";
		exit(EXIT_SUCCESS);
	}

	if (argc == 2) return nullptr;

	int* bin = new (nothrow) int[argc];
	assert(bin != nullptr);

	for (int i = 0; i < argc - 2; i++)
		bin[i] = strtol(argv[i + 2], nullptr, 10);

	tree root = nullptr;
	switch (tree_type) {
	case BST_MODE:
		for (int i = 0; i < (argc - 2); i++)
			root = grow(root, bin[i]);
		break;
	case AVL_MODE:
		for (int i = 0; i < (argc - 2); i++)
			root = growAVL(root, bin[i]);
		break;
	default:
		root = growBT(root, bin, 0, argc - 2);
	}

	delete[] bin;
	return root;
}

string treespecs(tree root) {
	if (root == nullptr) return "";
	DPRINT(cout << ">treespecs \n";);
	stringstream ss;

	ss << " size:" << size(root);
	ss << " height:" << height(root);

	bool BSTtree = isBST(root);
	tree(*fp)(tree);   
	fp = BSTtree ? minimum : minimumBT;
	ss << " min:" << value(fp(root));
	fp = BSTtree ? maximum : maximumBT;
	ss << " max:" << value(fp(root));

	DPRINT(cout << "<treespecs \n";);
	return ss.str();
}

void treeprint_mode(tree root, int mode) {
	if (root == nullptr) return;

	if (size(root) >= 1000) {  // a magic number
		cout << "\tThere are 1,000 nodes and more, the print mode goes into ...\n";
		mode = TASTY_MODE;
	}

	// TASTY_MODE: show just the first and last three levels each
	if ((height(root) + 1) < 7 && mode == TASTY_MODE)     // height + 1 = level, 
		mode = LEVEL_MODE;

	switch (mode) {
	case TREE_MODE:
		treeprint(root);
		break;
	case LEVEL_MODE:
		treeprint_levelorder(root);
		break;
	default: // TASTY_MODE: show just the fist and last three levels each
		treeprint_levelorder_tasty(root);
		cout << endl;
	}
}

void show_timeit(int begin) { 	// display elapsed time
	cout << "\tcpu: " << ((double)clock() - begin) / CLOCKS_PER_SEC << " sec\n";
}

int main(int argc, char **argv) {
	string menuBT = "Menu [BT] ";
	string menuBST = "Menu [BST] ";
	string menuAVL = "Menu [AVL] ";
	string showMenu[] = { "[tree]", "[level]", "[tasty]" };
	int showMode = TREE_MODE;  // by default, display both [tree] only
	bool AVLtree = false;
	bool BSTtree = false;
	tree node, x, y, root = nullptr;
	int item, key, p, q;
	vector<int> vec;
	char c;
	clock_t begin = 0;

	DPRINT(cout << "\t>Joyful Coding\n";);

	if (argc > 1) {
		int treeTypeBuilt;
		root = build_tree_by_args(argc, argv, treeTypeBuilt);
		if (treeTypeBuilt == BT_MODE)
			AVLtree = BSTtree = false;
		else if (treeTypeBuilt == AVL_MODE) 
			AVLtree = BSTtree = true;
		else
			BSTtree = true;
	}

	do {
		treeprint_mode(root, showMode);
		if (BSTtree)
			cout << "\n\t" << (AVLtree ? menuAVL : menuBST) << treespecs(root) << endl;
		else
			cout << "\n\t" << menuBT << treespecs(root) << endl;
		
		cout << "\tg - grow\t"; 				  cout << "\ta - grow a leaf    [BT]\n";
		cout << "\tt - trim*\t"; 				  cout << "\td - trim a leaf    [BT]\n";
		cout << "\tG - grow N\t";                 cout << "\tA - grow by Level  [BT]\n";
		cout << "\tT - trim N\t";                 cout << "\tf - find node      [BT]\n";
		cout << "\to - BST or AVL?\t";            cout << "\tp - find path&back [BT]\n";
		cout << "\tr - rebalance tree**";         cout << "\tl - traverse       [BT]\n";
		cout << "\tL - LCA*       \t";            cout << "\tB - LCA*           [BT]\n";
		cout << "\tm - menu [BST]/[AVL]**";       cout << "\tC - convert BT to BST*\n";
		cout << "\tc - clear\t"; 				  cout << "\ts - show mode:" << showMenu[showMode] << endl; 
		
		c = GetChar("\tCommand(q to quit): ");
		
		switch (c) {
		case 'g': // grow
			if (!BSTtree && !AVLtree) break;
			item = GetInt("\tEnter a key to grow: ");
			root = AVLtree ? growAVL(root, item) : grow(root, item);
			break;

		case 'a': // add a child (it may become an invalid BST/AVL tree)
			if (empty(root)) {
				key = GetInt("\tEnter a key to grow: ");
				root = growBT(root, key);
				break;
			}

			key = GetInt("\tSelect a node(degree 0 or 1): ");
			node = findBT(root, key);
			if (node == nullptr) {
				cout << "\tThe key(" << key << ") entered is not found.\n";
				break;
			}

			if (degree(node) == 2) {
				cout << "\tThis subtree(" << key << ") is full.\n";
				break;
			}

			while (true) {
				key = GetInt("\tEnter a key to grow: ");
				if (containsBT(root, key))
					cout << "\tThis key(" << key << ") is already in the tree.\n";
				else
					break;
			}

			if (degree(node) == 0) {
				cout << "\tAdding a child(" << key;
				cout << ") under its parent(" << node->key << ")" << endl;
				do {
					item = GetInt("\tEnter 0 for left, 1 for right: ");
				} while (item != 0 && item != 1);
				(item == 0) ? node->left = new TreeNode(key) 
					        : node->right = new TreeNode(key);
			}
			else {
				if (node->left == nullptr)
					node->left = new TreeNode(key);
				else if (node->right == nullptr)
					node->right = new TreeNode(key);
			}

			// after adding a node, check and reset the tree status flag.
			BSTtree = isBST(root);   
			AVLtree = isAVL(root);
			break;
		
		case 'd': // delete a child (it may become an invalid BST/AVL tree)
			key = GetInt("\tSelect a leaf node to trim: ");
			x = findBT(root, key);
			if (x == nullptr) {
				cout << "\tThe key(" << key << ")entered is not found.\n";
				break;
			}

			if (degree(x) != 0) {
				cout << "\tIt(" << key << ") is not a leaf node.\n";
				break;
			}

			// find its parent and remove this child node
			node = findParent(root, key, x);  // 
			if (node->left != nullptr && node->left->key == key) {
				node->left = nullptr;
				delete x;
			}
			else if (node->right != nullptr && node->right->key == key) {
				node->right = nullptr;
				delete x;
			}

			// after adding a node, check and reset the tree status flag.
			BSTtree = isBST(root);
			AVLtree = isAVL(root);
			break;

		case 'A':
			key = GetInt("\tEnter a key to add in level order: ");
			x = findBT(root, key);
			if (x != nullptr) {
				cout << "\tThe key(" << key << ") already exists." << endl;
				break;
			}
			root = growBT(root, key);
			// after adding a node, check and reset the tree status flag.
			BSTtree = isBST(root);
			AVLtree = isAVL(root);
			break;

		case 'B':  // LCA - Lowest Common Ancestor for Binary Tree[BT]
			if (empty(root)) break;
			if (BSTtree) {
				cout << "\n\tSelect a menu item for BST.\n";
				break;
			}
			// Notice that both p and q exist and are unique in a given tree by definition. 
			p = GetInt("\tEnter 1st descendent: ");
			q = GetInt("\tEnter 2nd descendent: ");
			x = findBT(root, p);
			y = findBT(root, q);
			if (x == nullptr || y == nullptr) {
				cout << "\n\tTwo descendents(" << p << ", " << q << ") should be existent.\n";
				break;
			}

			node = LCA_BT(root, x, y);           // LCA for BT recursive algorithm
			cout << "\tLCA(" << p << ", " << q << ") = " << value(node) << " by recursion" << endl;

			key = LCA_BTiteration(root, x, y);  // LCA for BT iteration algorithm
			cout << "\tLCA(" << p << ", " << q << ") = " << key << " by iteration" << endl;
			break;
		
		case 'L':  // LCA - Lowest Common Ancestor
			if (empty(root)) break;
			if (!BSTtree) {
				cout << "\n\tIt is not a BST. Select a menu item for BST\n";
				break;
			}
			// Notice that both p and q exist and are unique in a given tree by definition. 
			p = GetInt("\tEnter 1st descendent: ");
			q = GetInt("\tEnter 2nd descendent: ");
			x = find(root, p); 
			y = find(root, q); 
			if (x == nullptr || y == nullptr) {
				cout << "\n\tTwo descendents(" << p << ", " << q << ") should be existent.\n";
				break;
			}
			
			node = LCA(root, x, y);          // LCA for BST recursive algorithm
			cout << "\tLCA(" << p << ", " << q << ") = " << value(node) << " by recursion"<< endl;

			key = LCAiteration(root, x, y);  // LCA for BST iteration algorithm
			cout << "\tLCA(" << p << ", " << q << ") = " << key << " by iteration" << endl;
			break;

		case 't':  // trim
			if (empty(root)) break;
			if (!BSTtree && !AVLtree) break;
			item = GetInt("\tEnter a node to trim: ");
			root = AVLtree ? trimAVL(root, item) : trim(root, item);
			break;

		case 'f':  // find a node - contrainsBT/contains
			if (empty(root)) break;
			item = GetInt("\tEnter a key to find: ");
			bool (*fp_contains)(tree, int);   // fp for contains() and containsBT()
			fp_contains = BSTtree ? contains : containsBT; 
			if (fp_contains(root, item))
				cout << "\n\t" << item << " is found\n";
			else
				cout << "\n\t" << item << " is not found\n";
			break;

		case 'p': // find the path from root to a node // BT/BST/AVL
			if (empty(root)) break;
			item = GetInt("\tEnter a key to find path: ");

			tree (*fp_find)(tree, int);   // fp for find() and findBT()
			fp_find = BSTtree ? ::find : findBT;

			x = fp_find(root, item);
			if (x == nullptr) {
				cout << "\n\tThe node(" << value(x) << ") is not found.\n";
				break;
			}
			vec.clear();
			findPath(root, x, vec);
			cout << "\n\tPath: "; for (auto i : vec) cout << i << " "; cout << endl;
			vec.clear();
			findPathBack(root, x, vec);
			cout << "\tBack: "; for (auto i : vec) cout << i << " "; cout << endl;
			break;

		case 'l': // list nodes // BT/BST/AVL
			cout << "\n\t    inorder: "; vec.clear(); inorder(root, vec); show_vector(vec);
			cout << "\n\t   preorder: "; vec.clear(); preorder(root, vec); show_vector(vec);
			cout << "\n\t  postorder: "; vec.clear(); postorder(root, vec); show_vector(vec);
			cout << "\n\t levelorder: "; vec.clear(); levelorder(root, vec); show_vector(vec);
			cout << endl;
			if (!BSTtree && !AVLtree) break;
			node = pred(root);
			if (node)
				cout << "\tPredecessor: " << value(node);
			else
				cout << "\tPredecessor: undefined";
			node = succ(root);
			if (node)
				cout << "\tSuccessor: " << value(node) << endl;
			else
				cout << "\tSucessor: undefined" << endl;
			break;

		case 'o': // BT/BST/AVL
			if (empty(root)) break;
			cout << "\n\tBST: " << (isBST(root) ? "true" : "false") << endl;
			cout << "\tAVL: " << (isAVL(root) ? "true" : "false") << endl;
			break;

		case 's': // show mode - roll over to the next menu item
			showMode = (showMode + 1) % (sizeof(showMenu) / sizeof(showMenu[0]));
			break;

		case 'c': // BT/BST/AVL
			root = clear(root);
			break;

		case 'r':  // rebalance 
			if (!BSTtree)
				cout << "\n\tSince it is not a BST, we cannot rebalance it.\n";
			else {
				cout << "\n\tRebalance by reconstructing the tree...\n";
				begin = clock();
				root = reconstruct(root);
				show_timeit(begin);
				cout << "\n\tTree type remains as it is.\n";
			}
			break;

		case 'm':  // change menu to[BST]/[AVL]
			if (!BSTtree && !AVLtree) break;
			if (AVLtree) {
				AVLtree = false;
				BSTtree = true;
				cout << "\n\tTree type is set to BST.\n";
			}
			else {
				cout << "\n\tRebalance by reconstructing the tree...\n";
				begin = clock();
				root = reconstruct(root);
				show_timeit(begin);
				AVLtree = true;
				cout << "\n\tTree type is set to AVL.\n";
			}

			break;

		case 'G':
			if (!BSTtree && !AVLtree) break;
			item = GetInt("\tEnter a number of nodes to grow: ");
			begin = clock();
			root = growN(root, item, AVLtree);
			show_timeit(begin);
			break;

		case 'T':
			if (!BSTtree && !AVLtree) break;
			item = GetInt("\tEnter a number of nodes to trim: ");
			begin = clock();
			root = trimN(root, item, AVLtree);
			show_timeit(begin);
			break;

		case 'C':
			if (BSTtree) {
				cout << "\tIt is already a BST.\n";
				break;
			}
			begin = clock();
			BTtoBST(root);
			show_timeit(begin);

			// after conversion, check and reset the tree status flag.
			BSTtree = isBST(root);  
			AVLtree = false;       
			break;

		case 'q':
			break;
		}
	} while (c != 'q');

	clear(root);
	cout << "\n\tJoyful Coding~~\n";
	return EXIT_SUCCESS;
}


