
/** File: treeprint.cpp
 * implements printing a binary tree on console graphically. 
 *
 * @Author: Youngsup Kim, idebtor@gmail.com
 * 2016/04/15	Adapted from   
 *				http://web.archive.org/web/20071224095835/http://www.
 *				openasthra.com/wp-content/uploads/2007/12/binary_trees1.c
 * 2016/05/05	added the back slash problem in console using Hangul
 * 2019/05/05	added treeprint_levelorder() - recursive version 
 * 
 * The original code was modified to hide pointer related 
 * information in the tree structure for easy programming.
 *
 * In order to use the functionality, compile this file with  
 * your source code and include the following function prototype 
 * in your code;
 * 1. void treeprint(tree root); 
 * 2. TreeNode structure must have left/right nodes and int key as 
 *    its members. For example, 
 *    struct TreeNode {
 *		int			key;
 *		TreeNode*	left;		
 *		TreeNode*	right;
 *    };
 *    using tree = TreeNode*;
 *
 * In default cmd window may not display \ (back slash properly). 
 * One way to fix this problem is to replace the default font 
 * with a true type font. 
 * This web site shows how to:  http://www.diskool.com/508379
 *
 * In case, if is unavailable, download and install the font.
 * http://dev.naver.com/projects/nanumfont/download
 * Start regedit to change the registry and move to 
 * [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion
 *  \Console\TrueTypeFont] 
 * Change 949 - ±¼¸²Ã¼ to 949 - ³ª´®°íµñÄÚµù
 * Reboot the machine. 
 * Start cmd window, change its property font to use '³ª´®°íµñÄÚµù'.
 * 
 */

#include <iostream>
#include <string>
#include <cassert>
#include "tree.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//      printing tree in console
//////////////////////////////////////////////////////////////////////////
struct PrintTree {    // treeprint structure
	PrintTree* left;
	PrintTree* right;
	int edge_length; //length of the edge from this node to its children
	int height;
	int lablen;
	int parent_dir;  //-1=I am left, 0=I am root, 1=right   
	//char label[11];  //max supported unit32 in dec, 10 digits max
	std::string label;
};
using ptree = PrintTree*;

#define _INFINITY (1<<20)
#define MAX_HEIGHT 1000
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];

int gap = 3;        //adjust gap between left and right nodes					
int print_next;     //x coordinate of the next char printed, used
					//for printing next node in the same level

int MIN(int X, int Y) { return ((X) < (Y)) ? (X) : (Y); }
int MAX(int X, int Y) { return ((X) > (Y)) ? (X) : (Y); }

ptree build_ptree_recursive(tree t) {
	if (t == nullptr) return nullptr;
	ptree node = new PrintTree;
	assert(node != nullptr);

	node->left = build_ptree_recursive(t->left);
	node->right = build_ptree_recursive(t->right);

	if (node->left != nullptr)  node->left->parent_dir = -1;
	if (node->right != nullptr) node->right->parent_dir = 1;

	node->label = std::to_string(t->key);
	node->lablen = node->label.length();

	return node;
}

//Copy the tree into the ascii node structre
ptree  build_ptree(tree t) {
	ptree node;
	if (t == nullptr) return nullptr;
	node = build_ptree_recursive(t);
	node->parent_dir = 0;
	return node;
}

//Free all the nodes of the given tree
void free_ptree(ptree node) {
	if (node == nullptr) return;
	free_ptree(node->left);
	free_ptree(node->right);
	delete node;
}

//The following function fills in the lprofile array for the given tree.
//It assumes that the center of the label of the root of this tree
//is located at a position (x,y).  It assumes that the edge_length
//fields have been computed for this tree.
void compute_lprofile(ptree node, int x, int y) {
	int i, isleft;
	if (node == nullptr) return;
	isleft = (node->parent_dir == -1);
	lprofile[y] = MIN(lprofile[y], x - ((node->lablen - isleft) / 2));
	if (node->left != nullptr) {
		for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++)
			lprofile[y + i] = MIN(lprofile[y + i], x - i);
	}
	compute_lprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
	compute_lprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

void compute_rprofile(ptree node, int x, int y) {
	int i, notleft;
	if (node == nullptr) return;
	notleft = (node->parent_dir != -1);
	rprofile[y] = MAX(rprofile[y], x + ((node->lablen - notleft) / 2));
	if (node->right != nullptr) {
		for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++)
			rprofile[y + i] = MAX(rprofile[y + i], x + i);
	}
	compute_rprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
	compute_rprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

//This function fills in the edge_length and 
//height fields of the specified tree
void compute_edge_lengths(ptree node) {
	int h, hmin, i, delta;
	if (node == nullptr) return;
	compute_edge_lengths(node->left);
	compute_edge_lengths(node->right);

	/* first fill in the edge_length of node */
	if (node->right == nullptr && node->left == nullptr)
		node->edge_length = 0;
	else {
		if (node->left != nullptr) {
			for (i = 0; i<node->left->height && i < MAX_HEIGHT; i++)
				rprofile[i] = -_INFINITY;
			compute_rprofile(node->left, 0, 0);
			hmin = node->left->height;
		}
		else {
			hmin = 0;
		}
		if (node->right != nullptr) {
			for (i = 0; i<node->right->height && i < MAX_HEIGHT; i++)
				lprofile[i] = _INFINITY;
			compute_lprofile(node->right, 0, 0);
			hmin = MIN(node->right->height, hmin);
		}
		else {
			hmin = 0;
		}
		delta = 4;
		for (i = 0; i<hmin; i++)
			delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);

		//If the node has two children of height 1, then we allow the
		//two leaves to be within 1, instead of 2 
		if (((node->left != nullptr && node->left->height == 1) ||
			(node->right != nullptr && node->right->height == 1)) && delta>4)
			delta--;

		node->edge_length = ((delta + 1) / 2) - 1;
	}

	//now fill in the height of node
	h = 1;
	if (node->left != nullptr)
		h = MAX(node->left->height + node->edge_length + 1, h);
	if (node->right != nullptr)
		h = MAX(node->right->height + node->edge_length + 1, h);

	node->height = h;
}

//This function prints the given level of the given tree, assuming
//that the node has the given x cordinate.
void print_level(ptree node, int x, int level) {
	int i, isleft;
	if (node == nullptr) return;
	isleft = (node->parent_dir == -1);
	if (level == 0) {
		for (i = 0; i<(x - print_next - ((node->lablen - isleft) / 2)); i++)
			printf(" ");

		print_next += i;
		// printf("%s", node->label);
		std::cout << node->label;
		print_next += node->lablen;
	}
	else if (node->edge_length >= level) {
		if (node->left != nullptr) {
			for (i = 0; i<(x - print_next - (level)); i++) printf(" ");

			print_next += i;
			printf("/");
			print_next++;
		}
		if (node->right != nullptr) {
			for (i = 0; i<(x - print_next + (level)); i++) printf(" ");

			print_next += i;
			printf("\\");   
			print_next++;
		}
	}
	else {
		print_level(node->left, x - node->edge_length - 1,
			level - node->edge_length - 1);
		print_level(node->right, x + node->edge_length + 1,
			level - node->edge_length - 1);
	}
}

// Compute the max depth of a tree. It is the number of nodes along
// the longest path from the root node down to the farthest leaf node.
// height: 0 (undefined) for empty tree, 1 for root only tree
int treeprint_height(tree node) {
	if (node == nullptr) return 0;
	int left = treeprint_height(node->left);
	int right = treeprint_height(node->right);
	DPRINT(cout << " height: left=" << left << " right=" << right << endl;);
	return (left > right) ? 1 + left : 1 + right;
}

//prints ascii tree for given Tree structure
void treeprint(tree t) {
	DPRINT(std::cout << ">treeprint\n";);
	ptree proot;
	int xmin, i;
	if (t == nullptr) return;

	proot = build_ptree(t);
	compute_edge_lengths(proot);
	for (i = 0; i<proot->height && i < MAX_HEIGHT; i++)
		lprofile[i] = _INFINITY;

	compute_lprofile(proot, 0, 0);
	xmin = 0;
	for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
		xmin = MIN(xmin, lprofile[i]);

	for (i = 0; i < proot->height; i++) {
		print_next = 0;
		print_level(proot, -xmin, i);
		printf("\n");
	}
	if (proot->height >= MAX_HEIGHT)
		printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
	free_ptree(proot);
	DPRINT(std::cout << "<treeprint\n";);
}

// Given a binary tree, its nodes are printed in level-order.
void treeprint_levelorder(tree root, int level) {
	DPRINT(cout << ">treeprint_levelorder lv=" << level << endl;);
	if (root == nullptr) return;
	if (level == 1)
		cout << root->key << " ";
	else {
		treeprint_levelorder(root->left, level - 1);
		treeprint_levelorder(root->right, level - 1);
	}
	DPRINT(cout << "<treeprint_levelorder lv=" << level << endl;);
}

void treeprint_levelorder(tree root) {
	DPRINT(cout << ">treeprint_levelorder";);
	if (root == nullptr) return;
	int h = treeprint_height(root);

	for (int i = 1; i <= h; i++) {
		treeprint_levelorder(root, i);
		cout << endl;
	}
	DPRINT(cout << "<treeprint_levelorder \n";);
}