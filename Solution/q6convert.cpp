#include "../Solution.h"

string Solution::convert(string s, int numRows)
{
    int g = numRows * 2 - 2;
    int a = 0;
    string str;

    if (numRows == 1)
    {
        return s;
    }
    if (numRows == 2)
    {
        for (int j = 0; j < s.length(); j = j + 2)
        {
            str.push_back(s.at(j));
        }
        for (int j = 1; j < s.length(); j = j + 2)
        {
            str.push_back(s.at(j));
        }
        return str;
    }
    for (int i = 0; i < numRows; i++)
    {
        if (i % numRows == 0 || (i + 1) % numRows == 0)
        {
            int j = 0;
            int nums = 0;
            while (true)
            {
                nums = i + j * g;
                if (nums >= s.length())
                    break;
                str.push_back(s.at(nums));
                j++;
            }
        }
        else
        {
            int a = (numRows - i - 1) * 2;
            int j = 0;
            int nums1 = 0;
            int nums2 = 0;
            while (true)
            {
                nums1 = i + j * g;
                nums2 = i + j * g + a;
                if (nums1 >= s.length())
                    break;
                str.push_back(s.at(nums1));
                if (nums2 >= s.length())
                    break;
                str.push_back(s.at(nums2));
                j++;
            }
        }
    }
    return str;
}
