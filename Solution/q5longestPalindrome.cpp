#include "../Solution.h"

// 中心扩展法
string Solution::longestPalindrome(string s)
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
        // 中心右移一位
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
            //双位
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

        // 中心左移一位
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
            //双位
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
