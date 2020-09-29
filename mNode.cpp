#include "mNode.h"

Node *buildNode(std::string in)
{
	auto values = split(in.substr(1, in.length() - 2), ',');

	struct Node *root;
	struct Node *node;
	struct Node *lnode;
	// ֵ����
	std::queue<std::string> vq;
	// �ڵ����
	std::queue<Node *> tq;
	// �㼶��Ƕ���
	std::queue<int> lq;
	int layer = 0;
	int nlayer = -1;

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
		root = new Node(parseInt(vq.front()));
		vq.pop();
		tq.push(root);
		lq.push(layer);
	}
	std::string ts;
	while (tq.size() > 0)
	{
		node = tq.front();
		tq.pop();
		layer = lq.front();
		lq.pop();

		// ������ڵ�
		if (layer == nlayer)
		{
			lnode->next = node;
			lnode = node;
		}
		else
		{
			lnode = node;
			nlayer = layer;
		}

		layer++;
		if (vq.size() > 0)
		{
			ts = vq.front();
			vq.pop();
			if (ts != "null")
			{
				//��ڵ�
				node->left = new Node(parseInt(ts));
				tq.push(node->left);
				lq.push(layer);
			}
		}
		// �ҽڵ�
		if (vq.size() > 0)
		{
			ts = vq.front();
			vq.pop();
			if (ts != "null")
			{
				node->right = new Node(parseInt(ts));
				tq.push(node->right);
				lq.push(layer);
			}
		}
	}

	return root;
}

void printNode(Node *root)
{
	if (root == nullptr)
	{
		return;
	}
	queue<Node *> tq;
	Node *node;
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