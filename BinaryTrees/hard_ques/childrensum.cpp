#include <bits/stdc++.h>
using namespace std;

/*
Definition for Binary Tree Node
*/
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    bool isLeaf(Node* node) {
        if (node->left == NULL && node->right == NULL)
            return true;
        else
            return false;
    }

    bool isSumProperty(Node* root) {
        if (root == NULL) return true;
        if (isLeaf(root)) return true;

        int leftval = 0, rightval = 0;

        if (root->left != NULL) leftval = root->left->data;
        if (root->right != NULL) rightval = root->right->data;

        if (leftval + rightval != root->data)
            return false;
        else
            return isSumProperty(root->left) && isSumProperty(root->right);
    }
};

int main() {
    /*
            10
           /  \
          8    2
         / \
        3   5
    */

    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    Solution sol;

    if (sol.isSumProperty(root))
        cout << "Tree follows Children Sum Property" << endl;
    else
        cout << "Tree does NOT follow Children Sum Property" << endl;

    return 0;
}
