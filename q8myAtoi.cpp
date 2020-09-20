#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        
    }
};

int main()
{
    Solution s;

    string str = "abc";

    clock_t time_start = clock();
    cout << s.myAtoi(str);
    // cout << -32 % 10;
    cout << endl;
    clock_t time_end = clock();
    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    system("pause");
    return 0;
}