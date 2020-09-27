#include "../Solution.h"

bool Solution::isMatch(string s, string p)
{
    int m = s.size();
    int n = p.size();

    // f[0][0]�ǿ��ַ�����ע���±��Ӧλ��
    // ƥ���2���ַ�ʱ���±���1,1,����f�±���f[2][2]
    // i j ��Ӧ����f�±꣬s,pʱӦ�ü�1������f����
    // ���帨������matches
    // ע��matches��f�Ĺ�ϵ��һ��������ַ�ƥ�䣬һ���Ǵ�ƥ��
    auto matches = [&](int i, int j) {
        //�߽磬���ַ��϶���ƥ��
        if (i == 0)
            return false;
        //ƥ��.
        if (p[j - 1] == '.')
            return true;
        //һ��ƥ��
        return s[i - 1] == p[j - 1];
    };

    vector<vector<int>> f(m + 1, vector<int>(n + 1));
    // �߽�
    f[0][0] = true;
    // ���ַ�����ƥ��
    for (int i = 0; i <= m; i++)
    {
        // ģ��Ҫ�ӵ�һ���ַ���ʼ
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
