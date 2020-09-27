#include "mTree.h"
#include "queue"

using namespace std;

TreeNode *buildTree(std::string in, char p)
{
	auto values = split(in.substr(1, in.length() - 2), p);
	return buildTree(values, 0);
}

TreeNode *buildTree(std::vector<std::string> values, int idx)
{
	if (idx >= values.size() || values[idx] == "null")
		return NULL;
	TreeNode *root = new TreeNode(parseInt(values[idx]));
	root->left = buildTree(values, idx * 2 + 1);
	root->right = buildTree(values, idx * 2 + 2);
	return root;
}

TreeNode *buildTree2(std::string in)
{
	auto values = split(in.substr(1, in.length() - 2), ',');

	struct TreeNode *root;
	struct TreeNode *node;
	std::queue<std::string> vq;
	std::queue<TreeNode *> tq;

	for (int i = 0; i < values.size(); i++)
	{
		vq.push(values[i]);
	}
	node = root;
	if (vq.size() == 0 || vq.front() == "null")
	{
		return nullptr;
	}
	else
	{
		root = new TreeNode(parseInt(vq.front()));
		vq.pop();
		tq.push(root);
	}
	std::string ts;
	while (vq.size() > 0)
	{
		node = tq.front();
		tq.pop();
		ts = vq.front();
		vq.pop();
		if (ts != "null")
		{
			//左节点
			node->left = new TreeNode(parseInt(ts));
			tq.push(node->left);
		}
		// 右节点
		if (vq.size() > 0)
		{
			ts = vq.front();
			vq.pop();
			if (ts != "null")
			{
				node->right = new TreeNode(parseInt(ts));
				tq.push(node->right);
			}
		}
	}

	return root;
}

// 前序遍历
void printTree(TreeNode *root)
{
	if (root == NULL)
		return;
	std::cout << " ( " << root->val;
	printTree(root->left);
	printTree(root->right);
	std::cout << " ) ";
}

// 广度优先遍历
void printTree2(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	queue<TreeNode *> tq;
	TreeNode *node;
	node = root;
	cout << "(";
	cout << node->val;
	tq.push(node->left);
	tq.push(node->right);
	while (tq.size() > 0)
	{
		node = tq.front();
		tq.pop();
		if (node == nullptr)
		{
			cout << ",null";
		}
		else
		{
			cout << "," << node->val;
			tq.push(node->left);
			tq.push(node->right);
		}
	}
	cout << ")" << endl;
}
