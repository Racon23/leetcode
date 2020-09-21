#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
    }
};

int main()
{
    Solution s;

    int x = 121;

    clock_t time_start = clock();
    s.isPalindrome(x);

    cout << endl;
    clock_t time_end = clock();
    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    system("pause");
    return 0;
}