#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        int pop = 0;
        while (x != 0)
        {
            pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main()
{
    Solution s;

    int nums = 123;

    clock_t time_start = clock();
    cout << s.reverse(nums);
    // cout << -32 % 10;
    cout << endl;
    clock_t time_end = clock();
    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    system("pause");
    return 0;
}