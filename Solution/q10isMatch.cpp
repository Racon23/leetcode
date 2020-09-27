#include "../Solution.h"

bool Solution::isMatch(string s, string p)
{
    int m = s.size();
    int n = p.size();

    // f[0][0]是空字符串，注意下标对应位置
    // 匹配第2个字符时，下标是1,1,但是f下标是f[2][2]
    // i j 对应的是f下标，s,p时应该减1，但是f不减
    // 定义辅助函数matches
    // 注意matches和f的关系，一个是逐个字符匹配，一个是串匹配
    auto matches = [&](int i, int j) {
        //边界，空字符肯定不匹配
        if (i == 0)
            return false;
        //匹配.
        if (p[j - 1] == '.')
            return true;
        //一般匹配
        return s[i - 1] == p[j - 1];
    };

    vector<vector<int>> f(m + 1, vector<int>(n + 1));
    // 边界
    f[0][0] = true;
    // 空字符可以匹配
    for (int i = 0; i <= m; i++)
    {
        // 模板要从第一个字符开始
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                f[i][j] |= f[i][j - 2];
                if (matches(i, j - 1))
                {
                    f[i][j] |= f[i - 1][j];
                }
            }
            else
            {
                if (matches(i, j))
                {
                    f[i][j] |= f[i - 1][j - 1];
                }
            }
        }
    }
    return f[m][n];
}
