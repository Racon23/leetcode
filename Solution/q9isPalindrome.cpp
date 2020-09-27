#include "../Solution.h"

bool Solution::isPalindrome(int x)
{
    int x1 = 0;
    int temp = 0;
    if ((x < 0 || x % 10 == 0) && x != 0)
    {
        return 0;
    }
    while (x1 < x)
    {
        x1 = x1 * 10 + x % 10;
        x /= 10;
    }
    return x1 == x || x == x1 / 10;
}