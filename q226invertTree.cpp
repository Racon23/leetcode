#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(root==NULL){
            return NULL;
        }
        struct TreeNode* p;
        p=root->left;
        root->left=root->right;
        root->right=p;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main()
{
    Solution s;
    string str = "babad";

    struct TreeNode* root;
    struct TreeNode* p;
    root = new TreeNode;
    root->val = 4;
    root->left = NULL;
    root->right = NULL;

    root->left = new TreeNode;
    root->left->val = 2;
    root->left->left = new TreeNode;
    root->left->left->val = 1;
    root->left->left->left = NULL;
    root->left->left->right = NULL;

    root->left->right = new TreeNode;
    root->left->right->val = 3;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    root->right = new TreeNode;
    root->right->val = 7;
    root->right->left = new TreeNode;
    root->right->left->val = 6;
    root->right->left->left = NULL;
    root->right->left->right = NULL;

    root->right->right = new TreeNode;
    root->right->right->val = 9;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    s.invertTree(root);
    
    cout << endl;

    system("pause");
    return 0;
}
