// #pragma once

#ifndef MTREE_H
#define MTREE_H

#include <vector>
#include <iostream>
#include "utils.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

TreeNode* buildTree(std::string in , char p = ' ');

TreeNode* buildTree(std::vector<std::string> values, int idx);

TreeNode* buildTree2(std::string in);

TreeNode* buildTreeNode(std::string in);


void printTree(TreeNode* root);

// 广度优先遍历
void printTree2(TreeNode *root);

#endif