#include "../Solution.h"

int base = 0;
int count = 0;
int maxcount = 0;
vector<int> arr;

TreeNode *getSuccessorF(TreeNode *node)
{
    TreeNode *succ = node->left;
    if (succ->right != nullptr && succ->right != node)
    {
        succ = succ->right;
    }
    return succ;
}

void exeNode(TreeNode *root)
{
    if (root->val == base)
    {
        count++;
        if (maxcount == count)
        {
            arr.push_back(root->val);
        }
        if (maxcount < count)
        {
            maxcount = count;
            arr.clear();
            arr.push_back(root->val);
        }
    }
    else
    {
        base = root->val;
        count = 1;
    }
}

void morisSearchF(TreeNode *root)
{
    TreeNode *node = root;
    TreeNode *succ;
    while (node)
    {
        if (node->left == nullptr)
        {
            // 到达最左节点，处理并右移
            exeNode(node);
            node = node->right;
        }
        else
        {
            // 连接最右节点与根节点
            succ = getSuccessorF(node);
            if (succ->right == nullptr)
            {
                // 如果未连接，连接并左移
                succ->right = node;
                node = node->left;
            }
            else
            {
                // 如果已经连接，处理，右移，并断开连接。
                exeNode(node);
                node = node->right;
                succ->right = nullptr;
            }
        }
    }
    // return node;
}

vector<int> Solution::findMode(TreeNode *root)
{
    base = 0;
    count = 0;
    maxcount = 0;
    morisSearchF(root);
    return arr;
}
