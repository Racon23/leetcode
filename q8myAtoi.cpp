#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

class Automaton
{
    string state = "start";
    // space +/- number other
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};

    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if()
    }
};

class Solution
{
public:

    int sign = 1;
    long long ans =0;

    int myAtoi(string str)
    {
    }
};

int main()
{
    Solution s;

    string str = "   -83723   ";

    clock_t time_start = clock();
    cout << s.myAtoi(str);

    cout << endl;
    clock_t time_end = clock();
    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    system("pause");
    return 0;
}