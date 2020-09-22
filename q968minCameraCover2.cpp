#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class BuildTree {

    TreeNode* buildTreeNode(vector<int> arr, int pos)
    {
        struct TreeNode* node = new TreeNode;
        if (pos >= arr.size()) {
            return nullptr;
        }
        node->val = arr.at(pos);
        node->left = buildTreeNode(arr, 2 * pos + 1);
        node->right = buildTreeNode(arr, 2 * pos + 2);
        return node;
    }

public:
    TreeNode* buildBinTree(vector<int> arr)
    {
        struct TreeNode* root = new TreeNode;
        root = buildTreeNode(arr, 0);

        return root;
    }
};

struct Status {
    int a, b, c;
};

class Solution {

public:
    Status dfs(TreeNode* node)
    {
        if (node == nullptr) {
            return {INT_MAX / 2, 0, 0};
        }
        // vector<int> larr = dfs(node->left);
        // vector<int> rarr = dfs(node->right);
        // int a = larr.at(2) + rarr.at(2) + 1;
        // int b = min(a, min(larr.at(0) + rarr.at(1), larr.at(1) + rarr.at(0)));
        // int c = min(a, larr.at(1) + larr.at(1));
        
        auto [la, lb, lc] = dfs(node->left);
        auto [ra, rb, rc] = dfs(node->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, lb + ra));
        int c = min(a, lb + rb);
        return { a, b, c };
    }

    int minCameraCover(TreeNode* root)
    {
        // 根节点的左右节点都是1 ，没有放监控头，root要自救
        Status res = dfs(root);
        return res.b;
    }
};

int main()
{
    Solution s;

    vector<int> arr = { 10, 6, 15, 2, 8, 11, 18 };
    TreeNode* root;
    BuildTree bt;
    root = bt.buildBinTree(arr);

    clock_t time_start = clock();

    cout << s.minCameraCover(root);

    cout << endl;
    clock_t time_end = clock();
    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    system("pause");
    return 0;
}