#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        vector<int> nums1;
        nums1.resize(nums.size());
        nums1.clear();
        if(nums.size()==0){
            return nums1;
        }
        nums1.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            nums1.push_back(nums[i] + nums1[i - 1]);
        }

        return nums1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1, 1, 1, 1 };

    cout << s.runningSum(nums).at(3);
    cout << endl;

    system("pause");
    return 0;
}
