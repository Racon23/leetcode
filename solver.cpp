// #pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "utils.h"
#include "mTree.h"
#include "mList.h"
#include "mVector.h"
#include "mString.h"
#include "Solution.h"
using namespace std;

// 循环读取直到遇到非空行
fstream &mGetLine(fstream &f, string &in)
{
	while (getline(f, in))
	{
		if (!in.empty())
		{
			break;
		}
	}
	return f;
}

int main()
{
	Solution solu;
	fstream f("input.txt", ios::in);
	clock_t time_start;
	clock_t time_end;
	string in1;

	while (mGetLine(f, in1))
	{
		cout << in1 << endl;
		// 读取第二行
		// string in2;
		// if (!mGetLine(f, in2))
		// {
		// 	break;
		// }
		// cout << in2 << endl;
		// // 读取第三行
		// string in3;
		// if (!mGetLine(f, in3))
		// {
		// 	break;
		// }
		// cout << in3 << endl;

		// string str1 = buildString(in1);
		// int n = parseInt(in2);
		// TreeNode *root = buildTree2(in1);
		// TreeNode *p = buildTreeNode(in2);
		// TreeNode *q = buildTreeNode(in3);
		vector<int> vec1 = buildVector(in1);
		// printTree2(root);

		cout << "--result--" << endl;
		time_start = clock();
		// 执行操作

		// cout << solu.numIdenticalPairs(vec1);
		// printTree2(solu.minCameraCover(root));
		// printVector(solu.findMode(root));
		// cout << solu.isMatch(buildString(in1), buildString(in2));
		// printTree2(solu.lowestCommonAncestor(root, p, q));
		cout << solu.maxArea(vec1);

		cout << endl;
		// cout << INT_MAX << endl;
		//结束
		time_end = clock();
		cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;
		cout << endl;
	}

	return 0;
}
