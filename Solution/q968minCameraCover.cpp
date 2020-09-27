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
    // 根节点的左右节点都是1 ，没有放监控头，root要自救
    if (dfs(root) == 0)
        res++;
    return res;
}
