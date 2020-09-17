#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() == 1 || s.length() == 0)
        {
            return s;
        }
        if (s.length() == 2)
        {
            if (s.at(0) == s.at(1))
            {

                return s;
            }
            else
            {
                return s.substr(0, 1);
            }
        }
        string s1;
        if (longestPalindrome(s.substr(1, s.length() - 2)).compare(s.substr(1, s.length() - 2)) == 0)
        {
            if (s.at(0) == s.at(s.length() - 1))
                s1 = s;
            else
                s1 = s.substr(1, s.length() - 2);
        }
        string s2 = longestPalindrome(s.substr(1, s.length() - 1));
        if (s1.length() < s2.length())
            s1 = s2;
        string s3 = longestPalindrome(s.substr(0, s.length() - 1));
        if (s1.length() < s3.length())
            s1 = s3;
        return s1;
    }
};

int main()
{
    Solution s;
    // string str = "babad";
    // string str = "a";
    // string str = "aba";
    // string str = "abc";
    // string str = "abba";
    // string str = "abbbc";
    // string str = "abccbd";
    // string str = "";
    // string str = "abcdadc";
    // string str = "abb";
    string str = "ccd";


    cout << s.longestPalindrome(str);
    cout << endl;

    system("pause");
    return 0;
}