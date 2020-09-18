#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        int maxd = 0;
        vector<bool> candies2;
        candies2.resize(candies.size());
        candies2.clear();
        for (int i = 0; i < candies.size(); i++) {
            if (candies.at(i) > maxd)
                maxd = candies.at(i);
            candies.at(i) = extraCandies + candies.at(i);
        }
        for (int i = 0; i < candies.size(); i++) {
            if (candies.at(i) >= maxd) {
                candies2.push_back(true);
            } else {
                candies2.push_back(false);
            }
        }
        return candies2;
    }
};

int main()
{
    Solution s;
    vector<int> candies = { 2, 3, 5, 1, 3 };
    int extraCandies = 3;

    vector<bool> r = s.kidsWithCandies(candies, extraCandies);
    for (int i = 0; i < r.size(); i++) {
        cout << r.at(i) << endl;
    }
    cout << endl;

    system("pause");
    return 0;
}
