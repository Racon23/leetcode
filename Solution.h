#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>
#include "utils.h"
#include "mTree.h"
#include "mList.h"
#include "mNode.h"

using namespace std;

class Solution
{

public:
	//#4 findMedianSortedArrays
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);

	//#5 longestPalindrome
	string longestPalindrome(string s);

	//#6 convert
	string convert(string s, int numRows);

	//#7 reverse
	int reverse(int x);

	//#8 myAtoi
	int myAtoi(string str);

	//#9 isPalindrome
	bool isPalindrome(int x);

	//#10 isMatch
	bool isMatch(string s, string p);

	//#11 盛最多水的容器
	int maxArea(vector<int> &height);

	//#226 invertTree
	TreeNode *invertTree(TreeNode *root);

	//#538 convertBST
	TreeNode* convertBST(TreeNode* root);

	//#617 mergeTrees
	TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2);

	//#968 minCameraCover
	int minCameraCover(TreeNode* root);
	int minCameraCover2(TreeNode* root);

	//#1431 kidsWithCandies
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

	//#1470 shuffle
	vector<int> shuffle(vector<int>& nums, int n);

	//#1480 runningSum
    vector<int> runningSum(vector<int>& nums);

	//#1512 numIdenticalPairs
	int numIdenticalPairs(vector<int>& nums);

	//#501 findMode
	vector<int> findMode(TreeNode *root);

	//#235 二叉搜索树的最近公共祖先
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

	//# 117. 填充每个节点的下一个右侧节点指针 II
	Node* connect(Node* root);
};

#endif