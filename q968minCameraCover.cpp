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
        struct TreeNode* node=new TreeNode;
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
        struct TreeNode* root=new TreeNode;
        root = buildTreeNode(arr, 0);

        return root;
    }
};


class Solution {
    
    int res=0;

public:


    int minCameraCover(TreeNode* root)
    {  
        // 根节点的左右节点都是1 ，没有放监控头，root要自救
        if(dfs(root)==0) res++;
        return res;

    }

    int dfs(TreeNode* node){
        if(node==nullptr) return 1;
        int left=dfs(node->left);
        int right=dfs(node->right);
        if(left==1&&right==1) return 0;
        if(left+right>=3) return 1;
        res++;
        return 2;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {10, 6, 15, 2, 8, 11, 18};
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