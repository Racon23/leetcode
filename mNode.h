// #pragma once

#ifndef MNODE_H
#define MNODE_H

#include <vector>
#include <iostream>
#include <string>
#include <queue>

#include "utils.h"
#include "mJSON.h"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* buildNode(std::string in);

void printNode(Node* node);

#endif