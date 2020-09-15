#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int tl = nums1.size() + nums2.size();
        int k = 0; //记录中位数
        int k2 = 0; //记录k/2-1
        int i = 0; //nums1串下标
        int j = 0; //nums2串下标
        int i1 = 0; //临时存下标
        int j1 = 0;
        double r = 0; //输出结果

        //如果奇数
        if (tl % 2 == 1) {

            // 可能出门就空一个
            if (nums1.size() == 0) {
                return nums2[tl / 2];
            }
            if (nums2.size() == 0) {
                return nums1[tl / 2];
            }

            k = tl / 2 + 1;
            while (k > 1) {
                k2 = k / 2 - 1;

                // 解决k/2-1溢出串下标的问题
                if (i + k2 >= nums1.size()) {
                    i1 = nums1.size() - 1;
                } else {
                    i1 = i + k2;
                }
                if (j + k2 >= nums2.size()) {
                    j1 = nums2.size() - 1;
                } else {
                    j1 = j + k2;
                }

                if (nums1[i1] <= nums2[j1]) {
                    k = k - (i1 - i + 1);
                    i = i1 + 1;
                    if (i >= nums1.size()) {
                        r = nums2[j + k - 1];
                        return r;
                    }
                } else {
                    k = k - (j1 - j + 1);
                    j = j1 + 1;
                    if (j >= nums2.size()) {
                        r = nums1[i + k - 1];
                        return r;
                    }
                }
            }

            // 最终阶段，两串中找最小值即结果
            if (nums1[i] <= nums2[j])
                r = nums1[i];
            else
                r = nums2[j];
        }
        //如果偶数
        if (tl % 2 == 0) {

            // 可能出门就空一个
            if (nums1.size() == 0) {
                return (nums2[tl / 2 - 1] + nums2[tl / 2]) / 2.0;
            }
            if (nums2.size() == 0) {
                return (nums1[tl / 2 - 1] + nums1[tl / 2]) / 2.0;
            }

            //中位数有两个，但是只需要第一个
            k = tl / 2;
            while (k > 1) {
                k2 = k / 2 - 1;

                // 解决k/2-1溢出串下标的问题
                if (i + k2 >= nums1.size()) {
                    i1 = nums1.size() - 1;
                } else {
                    i1 = i + k2;
                }
                if (j + k2 >= nums2.size()) {
                    j1 = nums2.size() - 1;
                } else {
                    j1 = j + k2;
                }

                if (nums1[i1] <= nums2[j1]) {
                    k = k - (i1 - i + 1);
                    i = i + k2 + 1;
                    if (i >= nums1.size()) {
                        r = (nums2[j + k - 1] + nums2[j + k]) / 2.0;
                        return r;
                    }
                } else {
                    k = k - (j1 - j + 1);
                    j = j + k2 + 1;
                    if (j >= nums2.size()) {
                        r = (nums1[i + k - 1] + nums1[i + k]) / 2.0;
                        return r;
                    }
                }
            }

            // 最终阶段，两串中找最小值即结果
            int r1 = 0; //记录第一个中位数
            int r2 = 0; //记录第二个中位数
            if (nums1[i] <= nums2[j]) {
                r1 = nums1[i];
                i++;
                // 这里下标有可能溢出
                if (i >= nums1.size()) {
                    r2 = nums2[j];
                    r = (r1 + r2) / 2.0;
                    return r;
                }
            } else {
                r1 = nums2[j];
                j++;
                // 这里下标有可能溢出
                if (j >= nums2.size()) {
                    r2 = nums1[i];
                    r = (r1 + r2) / 2.0;
                    return r;
                }
            }
            if (nums1[i] <= nums2[j]) {
                r2 = nums1[i];
            } else {
                r2 = nums2[j];
            }
            r = (r1 + r2) / 2.0;
        }

        return r;
    }
};

int main()
{
    Solution s;
    // vector<int> nums1 = { 1, 3 };
    // vector<int> nums2 = { 2 };
    // vector<int> nums1 = { 1, 2, 7, 9 };
    // vector<int> nums2 = { 3, 5, 6, 8, 10 };

    // vector<int> nums1 = { 1, 2, 3, 4 };
    // vector<int> nums2 = { 5, 6, 7, 8, 9 };

    // vector<int> nums1 = { 1, 2, 7, 9 };
    // vector<int> nums2 = { 3, 5, 6, 8 };

    // vector<int> nums1 = { 1, 2 };
    // vector<int> nums2 = { 3, 4 };

    // vector<int> nums1 = {};
    // vector<int> nums2 = { 1, 2, 3, 4 };

    // vector<int> nums1 = { 1 };
    // vector<int> nums2 = { 2, 3, 4, 5, 6, 7 };
    vector<int> nums1 = { 1 };
    vector<int> nums2 = { 2, 3, 4, 5, 6, 7, 8 };

    cout << s.findMedianSortedArrays(nums1, nums2);
    cout << endl;

    system("pause");
    return 0;
}