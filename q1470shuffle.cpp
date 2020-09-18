#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> nums1;
        vector<int> nums2;
        nums1.resize(n);
        nums2.resize(n);
        nums1.clear();
        nums2.clear();
        for (int i = 0; i < n; i++) {
            nums1.push_back(nums.at(i));
            nums2.push_back(nums.at(i + n));
        }
        nums.clear();
        for (int i = 0; i < n; i++) {
            nums.push_back(nums1.at(i));
            nums.push_back(nums2.at(i));
        }

        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2, 5, 1, 3, 4, 7 };
    int n = 3;

    vector<int> r = s.shuffle(nums, n);

    // cout << s.runningSum(nums).at(3);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums.at(i) << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
