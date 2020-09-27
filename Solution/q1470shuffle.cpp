#include "../Solution.h"

vector<int> Solution::shuffle(vector<int> &nums, int n)
{
    vector<int> nums1;
    vector<int> nums2;
    nums1.resize(n);
    nums2.resize(n);
    nums1.clear();
    nums2.clear();
    for (int i = 0; i < n; i++)
    {
        nums1.push_back(nums.at(i));
        nums2.push_back(nums.at(i + n));
    }
    nums.clear();
    for (int i = 0; i < n; i++)
    {
        nums.push_back(nums1.at(i));
        nums.push_back(nums2.at(i));
    }

    return nums;
}
