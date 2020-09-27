#include "../Solution.h"

int res = 0;

int dfs(TreeNode *node)
{
    if (node == nullptr)
        return 1;
    int left = dfs(node->left);
    int right = dfs(node->right);
    if (left == 1 && right == 1)
        return 0;
    if (left + right >= 3)
        return 1;
    res++;
    return 2;
}

int Solution::minCameraCover(TreeNode *root)
{
    // ���ڵ�����ҽڵ㶼��1 ��û�зż��ͷ��rootҪ�Ծ�
    if (dfs(root) == 0)
        res++;
    return res;
}
