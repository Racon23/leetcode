#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        int t = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums.at(i) == nums.at(j)) {
                    t++;
                }
            }
        }
        return t;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1, 1, 1, 1 };

    cout << s.numIdenticalPairs(nums);
    cout << endl;

    system("pause");
    return 0;
}
