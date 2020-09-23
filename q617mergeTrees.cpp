#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class BuildTree
{

    TreeNode *buildTreeNode(vector<int> arr, int pos)
    {
        struct TreeNode *node = new TreeNode;
        if (pos >= arr.size())
        {
            return nullptr;
        }
        node->val = arr.at(pos);
        node->left = buildTreeNode(arr, 2 * pos + 1);
        node->right = buildTreeNode(arr, 2 * pos + 2);
        return node;
    }

public:
    TreeNode *buildBinTree(vector<int> arr)
    {
        struct TreeNode *root = new TreeNode;
        root = buildTreeNode(arr, 0);

        return root;
    }
};

class Solution
{

public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1 != nullptr && t2 != nullptr)
        {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        }
        if (t1 != nullptr && t2 == nullptr)
        {
            t1->left = mergeTrees(t1->left, nullptr);
            t1->right = mergeTrees(t1->right, nullptr);
            return t1;
        }
        if (t1 == nullptr && t2 != nullptr)
        {
            t2->left = mergeTrees(nullptr, t2->left);
            t2->right = mergeTrees(nullptr, t2->right);
            return t2;
        }

        return nullptr;
    }
};

int main()
{
    Solution sl;

    BuildTree bt;

    // vector<int> arr = {10, 6, 15, 2, 8, 11, 18};
    // vector<int> arr2 = {1, 3, NULL, 5};

    vector<int> arr = {1, 3, 5, 2};
    vector<int> arr2 = {2, 1, 3, NULL, 4, NULL, 7};

    TreeNode *root = bt.buildBinTree(arr);
    TreeNode *root2 = bt.buildBinTree(arr2);
    TreeNode *root3;

    clock_t time_start = clock();

    root3 = sl.mergeTrees(root, root2);

    cout << endl;
    clock_t time_end = clock();

    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    // system("pause");
    return 0;
}