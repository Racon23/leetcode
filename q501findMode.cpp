#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

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

    TreeNode *buildTreeNode(TreeNode *node, queue<int> q,queue<TreeNode*> tq)
    {
        int li, ri;
        struct TreeNode *tnode;
        if (q.size() == 0)
        {
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }
        li = q.front();
        q.pop();

        if(li==NULL){
            tnode=nullptr;
            tq.push(nullptr);
        }else{
            tnode = new TreeNode;
            tnode->val=li;
            tq.push(tnode);
        }
        node->left = tnode;

        if (q.size() == 0)
        {
            node->right = nullptr;
            return node;
        }
        ri = q.front();
        q.pop();
        if(li==NULL){
            tnode=nullptr;
            tq.push(nullptr);
        }else{
            tnode = new TreeNode;
            tnode->val=ri;
            tq.push(tnode);
        }
        node->right = tnode;
        
        return node;
    }

public:
    TreeNode *buildBinTree(queue<int> q)
    {
        struct TreeNode *root = new TreeNode;
        queue<TreeNode*> tq;
        root->val = q.front();
        q.pop();
        root = buildTreeNode(root, q,tq);

        return root;
    }
};

class Solution
{
    int base = 0;
    int count = 0;
    int maxcount = 0;
    vector<int> arr;

    TreeNode *getSuccessor(TreeNode *node)
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

    void morisSearch(TreeNode *root)
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
                succ = getSuccessor(node);
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

public:
    vector<int> findMode(TreeNode *root)
    {
        morisSearch(root);
        return arr;
    }
};

int main()
{
    Solution sl;

    BuildTree bt;

    // -1,0,0,1,2,2
    // vector<int> arr = {1,0,2,-1,0,2};
    // vector<int> arr = {1, NULL, 2, 2};
    vector<int> vec = {1, NULL, 2, 2};
    queue<int> q;
    for (int v : vec)
    {
        q.push(v);
    }

    TreeNode *root = bt.buildBinTree(q);

    clock_t time_start = clock();

    // sl.minCameraCover();
    vector<int> res = sl.findMode(root);

    for (int r : res)
    {
        cout << r << " ";
    }
    cout << endl;
    clock_t time_end = clock();

    cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

    // system("pause");
    return 0;
}



