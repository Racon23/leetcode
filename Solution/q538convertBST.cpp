#include "../Solution.h"

TreeNode *getSuccessor(TreeNode *node)
{
    TreeNode *succ = node->right;
    while (succ->left != nullptr && succ->left != node)
    {
        succ = succ->left;
    }
    return succ;
}

TreeNode *Solution::convertBST(TreeNode *root)
{
    int sum = 0;
    TreeNode *node = root;
    while (node != nullptr)
    {
        if (node->right == nullptr)
        {
            // �����ҽڵ����ڵ�
            sum += node->val;
            node->val = sum;
            node = node->left;
        }
        else
        {
            TreeNode *succ;
            succ = getSuccessor(node);
            if (succ->left == nullptr)
            {
                succ->left = node;
                node = node->right;
            }
            else
            {
                // ������ڵ�
                sum += node->val;
                node->val = sum;
                node = node->left;
                succ->left = nullptr;
            }
        }
    }
    return root;
}
