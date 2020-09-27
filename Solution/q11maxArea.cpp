#include "../Solution.h"

int Solution::maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    int temp = 0;
    int ma = 0;
    while (i < j)
    {
        temp = (j - i) * min(height[i], height[j]);
        ma = max(ma, temp);
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return ma;
}
