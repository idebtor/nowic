#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode {
	int			key;	
	TreeNode	*left;			// left child 
	TreeNode	*right;			// right child 
	TreeNode(const int k = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) {
		key = k; 	left = l;	right =r;
	}
	~TreeNode() {}
};
using tree = TreeNode*;

#endif