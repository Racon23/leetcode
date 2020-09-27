#include "../Solution.h"

TreeNode *Solution::invertTree(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    struct TreeNode *p;
    p = root->left;
    root->left = root->right;
    root->right = p;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
