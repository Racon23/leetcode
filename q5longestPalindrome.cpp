#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        string str = s.substr(len / 2, 1);
        string tstr;
        string tstr1;
        string tstr2;
        if (len <= 1)
            return s;
        int i = len / 2;
        int k = 1;
        while (i >= 0 && i < len)
        {
            i = len / 2 + k;
            if (i >= len)
            {
                continue;
            }
            for (int j = 1; j < len; j++)
            {
                if (i - j >= 0 && i + j < len)
                {
                    if (s.at(i - j) == s.at(i + j))
                    {
                        tstr = s.substr(i - j, j * 2 + 1);
                        if (tstr.length() > str.length())
                        {
                            str = tstr;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (i < len - 1 && s.at(i) == s.at(i + 1))
            {
                tstr = s.substr(i, 2);
                if (tstr.length() > str.length())
                {
                    str = tstr;
                }
                for (int j = 1; j < len; j++)
                {
                    if (i - j >= 0 && i + j + 1 < len)
                    {
                        if (s.at(i - j) == s.at(i + j + 1))
                        {
                            tstr = s.substr(i - j, j * 2 + 2);
                            if (tstr.length() > str.length())
                            {
                                str = tstr;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            i = len / 2 - k;
            if (i < 0)
            {
                continue;
            }
            for (int j = 1; j < len; j++)
            {
                if (i - j >= 0 && i + j < len)
                {
                    if (s.at(i - j) == s.at(i + j))
                    {
                        tstr = s.substr(i - j, j * 2 + 1);
                        if (tstr.length() > str.length())
                        {
                            str = tstr;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (i < len - 1 && s.at(i) == s.at(i + 1))
            {
                tstr = s.substr(i, 2);
                if (tstr.length() > str.length())
                {
                    str = tstr;
                }
                for (int j = 1; j < len; j++)
                {
                    if (i - j >= 0 && i + j + 1 < len)
                    {
                        if (s.at(i - j) == s.at(i + j + 1))
                        {
                            tstr = s.substr(i - j, j * 2 + 2);
                            if (tstr.length() > str.length())
                            {
                                str = tstr;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            k++;
        }
        return str;
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
    // string str = "ccd";
    string str = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
    clock_t time_start = clock();
    cout << s.longestPalindrome(str);
    cout << endl;
    clock_t time_end = clock();
    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    system("pause");
    return 0;
}