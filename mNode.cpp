#include "mNode.h"

Node* buildNode(std::string in) {
	auto values = split(in.substr(1, in.length() - 2), ',');

	struct Node *root;
	struct Node *node;
	std::queue<std::string> vq;
	std::queue<Node *> tq;

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
			node->left = new Node(parseInt(ts));
			tq.push(node->left);
		}
		// 右节点
		if (vq.size() > 0)
		{
			ts = vq.front();
			vq.pop();
			if (ts != "null")
			{
				node->right = new Node(parseInt(ts));
				tq.push(node->right);
			}
		}
	}

	return root;
}
}

void printNode(Node* node){

}