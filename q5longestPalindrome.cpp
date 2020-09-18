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
        string str;
        string tstr;
        string tstr1;
        string tstr2;
        if (len <= 1)
            return s;
        int i;
        int ia;
        if (len % 2 == 0)
        {
            ia = len / 2 - 1;
        }
        else
        {
            ia = len / 2;
        }
        i = ia;
        str = s.substr(ia, 1);
        int k = 0;
        int flag = 0;
        while (i >= 0 && i < len)
        {
            i = ia + k;
            if (i < len)
            {
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
                                if (i - j == 0 || i + j == len - 1)
                                {
                                    flag = 1;
                                    break;
                                }
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
                                    if (i - j == 0 || i + j + 1 == len - 1)
                                    {
                                        flag = 1;
                                        break;
                                    }
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
                if (flag == 1)
                    return str;
            }

            if (k == 0)
            {
                k++;
                continue;
            }

            i = ia - k;
            if (i >= 0)
            {
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
                                if (i - j == 0 || i + j == len - 1)
                                {
                                    flag = 1;
                                    break;
                                }
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
                                    if (i - j == 0 || i + j + 1 == len - 1)
                                    {
                                        flag = 1;
                                        break;
                                    }
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
                if (flag == 1)
                    return str;
            }

            k++;
        }
        return str;
    }
};

int main()
{
    Solution s;
    // string str = "ababd";
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
    // string str = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
    // string str = "aaaa";
    // string str = "aaaaa";
    string str = "caba";
    clock_t time_start = clock();
    cout << s.longestPalindrome(str);
    cout << endl;
    clock_t time_end = clock();
    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    system("pause");
    return 0;
}