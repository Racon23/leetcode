#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int x1 = 0;
        int temp = 0;
        if((x<0||x%10==0)&&x!=0){
            return 0;
        }
        while (x1 < x)
        {
            x1 = x1 * 10 + x % 10;
            x /= 10;
        }
        return x1 == x || x == x1 / 10;
    }
};

int main()
{
    Solution s;

    // int x = -1110;
    int x =0;

    clock_t time_start = clock();
    cout << s.isPalindrome(x);

    cout << endl;
    clock_t time_end = clock();
    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    system("pause");
    return 0;
}