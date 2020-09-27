#include "../Solution.h"

TreeNode *Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *node = root;
    while (true)
    {
        if (p->val < node->val && q->val < node->val)
        {
            node = node->left;
        }
        else if (p->val > node->val && q->val > node->val)
        {
            node = node->right;
        }
        else
        {
            break;
        }
    }
    return node;
}