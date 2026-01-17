#include <bits/stdc++.h>
using namespace std;

/*
Definition for BST Node
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
    int findCeil(Node* root, int x) {
        int ans = -1;

        while (root != NULL) {
            if (root->data == x) {
                return root->data;
            }
            if (root->data < x) {
                root = root->right;
            } else {
                ans = root->data;
                root = root->left;
            }
        }
        return ans;
    }
};

int main() {
    /*
            8
           / \
          4   12
         / \  / \
        2  6 10 14
    */

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    Solution sol;

    int x = 5;
    int ceilValue = sol.findCeil(root, x);

    if (ceilValue != -1)
        cout << "Ceil of " << x << " is: " << ceilValue << endl;
    else
        cout << "No ceil exists for " << x << endl;

    return 0;
}
