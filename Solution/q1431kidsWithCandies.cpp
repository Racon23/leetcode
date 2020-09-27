#include "../Solution.h"

vector<bool> Solution::kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int maxd = 0;
    vector<bool> candies2;
    candies2.resize(candies.size());
    candies2.clear();
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies.at(i) > maxd)
            maxd = candies.at(i);
        candies.at(i) = extraCandies + candies.at(i);
    }
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies.at(i) >= maxd)
        {
            candies2.push_back(true);
        }
        else
        {
            candies2.push_back(false);
        }
    }
    return candies2;
}
