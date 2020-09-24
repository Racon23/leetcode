#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        return nums1[0];
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    queue<int> q;
    cout<<q.size();
    cout<<q.front();
    // cout << q.front() << " " << q.back() << endl;

    cout << s.findMedianSortedArrays(nums1, nums2);
    cout << endl;

    system("pause");
    return 0;
}