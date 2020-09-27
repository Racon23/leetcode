#include "../Solution.h"

// 官方解法 动态规划
struct Status
{
    int a, b, c;
};

Status dfs2(TreeNode *node)
{
    if (node == nullptr)
    {
        return {INT_MAX / 2, 0, 0};
    }

    auto [la, lb, lc] = dfs2(node->left);
    auto [ra, rb, rc] = dfs2(node->right);
    int a = lc + rc + 1;
    int b = min(a, min(la + rb, lb + ra));
    int c = min(a, lb + rb);
    return {a, b, c};
}

int Solution::minCameraCover2(TreeNode *root)
{
    // 根节点的左右节点都是1 ，没有放监控头，root要自救
    Status res = dfs2(root);
    return res.b;
}