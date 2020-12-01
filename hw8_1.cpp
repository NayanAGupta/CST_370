/* Title: hw8_1.cpp
* Abstract: Creates a Binary Tree with the following
*   functions: append, isBST, findFirstNode, getHeight, 
    levelOrder, preOrder, inOrder, and postOrder.
* Author: Nayan Gupta
* ID: 9653
* Date: 10/29/2020
*/

// A simple implementation of a binary tree with "struct" in C++.
// It displays all nodes using the inorder traversal.
// Written by EIR and Dr. Byun for CST370.

#include <iostream>
#include <string>
#include <queue>

using namespace std;

/*
15
9
append 10
append 50
isBST
preOrder
append 45
height
levelOrder
findFirstNode
postOrder
*/
struct Node {
	// Data part for a node. 
    int data;
    Node* left;
    Node* right;
    Node* root;
    // Constructor for a new node.
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void append(Node* r, Node* d) {
    queue<Node*> Q;
    Q.push(r);
 
    while (!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();
        if (curr->left != nullptr)
            Q.push(curr->left);
        else {
            curr->left = d;
            return;
        }
        if (curr->right != nullptr)
            Q.push(curr->right);
        else {
            curr->right = d;
            return;
        }
    }
}

bool isBST(Node* r) {
    if (r == nullptr) {
        return true; 
    }
    else if (r->left != NULL && r->left->data > r->data) {
        return false;
    }
    else if (r->right != NULL && r->right->data < r->data) { 
        return false;
    }
    else if (!isBST(r->left) || !isBST(r->right)) {
        return false;
    }
    return true;
}

void findFirstNode(Node* r) {
    if (!r->left) {
        cout << r->data;
    }
    else {
        findFirstNode(r->left);
    }
}

int getHeight(Node* r) {
    if (r == nullptr) {
        return -1;
    }
    else  {
        int height = getHeight(r->left);
        return height + 1;
    }
}

void levelOrder(Node* r) {
    queue<Node*> Q;
    Q.push(r);
    while (!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();
        cout << curr->data << " ";
        if (curr->left != nullptr)
            Q.push(curr->left);
        if (curr->right != nullptr)
            Q.push(curr->right);
    }
}

void inOrder(Node* r) {
    if (r) {
        inOrder(r->left);
        cout << r->data << " ";
        inOrder(r->right);
    }
}

void preOrder(Node* r) {
    if (r) {
        cout << r->data << " ";
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(Node* r) {
    if (r) {
        postOrder(r->left);
        postOrder(r->right);
        cout << r->data << " ";
    }
}


// A sample main to create a binary tree like below.
//       5
//      / \
//     3   4
//    / \
//   1   2
//
int main() {
    int root, numInst;
    cin >> root >> numInst;

    Node* Root = new Node(root);
    for (int i = 0; i < numInst; i++) {
        string instruction;
        cin >> instruction;
        if (instruction == "append") {
            int data;
            cin >> data;
            Node* Data = new Node(data);
            append(Root, Data);
        }
        if (instruction == "isBST") {
            if (isBST(Root)) {
                cout << "true";
            }
            else {
                cout << "false";
            }
            cout << endl;
        }
        if (instruction == "height") {
            cout << getHeight(Root);
            cout << endl;
        }
        if (instruction == "findFirstNode") {
            findFirstNode(Root);
            cout << endl;
        }
        if (instruction == "levelOrder") {
            levelOrder(Root);
            cout << endl;
        }
        if (instruction == "postOrder") {
            postOrder(Root);
            cout << endl;
        }
        if (instruction == "inOrder") {
            inOrder(Root);
            cout << endl;
        }
        if (instruction == "preOrder") {
            preOrder(Root);
            cout << endl;
        }
    }

    return 0;
}


