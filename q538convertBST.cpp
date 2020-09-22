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

class Solution {

    TreeNode* getSuccessor(TreeNode* node)
    {
        TreeNode* succ = node->right;
        while (succ->left != nullptr && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }

public:
    TreeNode* convertBST(TreeNode* root)
    {
        int sum = 0;
        TreeNode* node = root;
        while (node != nullptr) {
            if (node->right == nullptr) {
                // 处理右节点和左节点
                sum += node->val;
                node->val = sum;
                node = node->left;
            } else {
                TreeNode* succ;
                succ = getSuccessor(node);
                if (succ->left == nullptr) {
                    succ->left = node;
                    node = node->right;
                } else {
                    // 处理根节点
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                    succ->left = nullptr;
                }
            }
        }
        return root;
    }
};

int main()
{
    Solution s;

    struct TreeNode* root;
    struct TreeNode* p;
    root = new TreeNode;
    root->val = 10;
    root->left = NULL;
    root->right = NULL;

    root->left = new TreeNode;
    root->left->val = 6;
    root->left->left = new TreeNode;
    root->left->left->val = 2;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = new TreeNode;
    root->left->right->val = 9;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    root->right = new TreeNode;
    root->right->val = 15;
    root->right->left = new TreeNode;
    root->right->left->val = 11;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = new TreeNode;
    root->right->right->val = 18;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    clock_t time_start = clock();
    s.convertBST(root);

    cout << endl;
    clock_t time_end = clock();
    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    system("pause");
    return 0;
}