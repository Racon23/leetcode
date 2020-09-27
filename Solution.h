#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>
#include "utils.h"
#include "mTree.h"
#include "mList.h"

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
};

#endif