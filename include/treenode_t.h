#ifndef TREENODET_H
#define TREENODET_H

template <typename T>
struct TreeNode {
	T			key;	
	TreeNode	*left;			// left child 
	TreeNode	*right;			// right child 
	TreeNode(T k, TreeNode* l, TreeNode* r) {
		key = k; 	left = l;	right = r;
	}
	TreeNode(T k) : key(k), left(nullptr), right(nullptr) {}
	~TreeNode() {}
};

template <typename T> using tree = TreeNode<T>*;

#endif