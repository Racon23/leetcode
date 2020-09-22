#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
    }
};

int main()
{
    Solution sol;

    string s = "abbbbd";
    string p = "ab*c*d";

    clock_t time_start = clock();
    cout << sol.isMatch(s, p);

    cout << endl;
    clock_t time_end = clock();
    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    system("pause");
    return 0;
}