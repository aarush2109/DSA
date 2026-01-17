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
        left = right = NULL;
    }
};

class Solution {
public:
    int floor(Node* root, int x) {
        int ans = -1;

        while (root != NULL) {
            if (root->data == x) 
                return root->data;

            if (root->data > x) {
                root = root->left;
            } else {
                ans = root->data;
                root = root->right;
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
    int floorValue = sol.floor(root, x);

    if (floorValue != -1)
        cout << "Floor of " << x << " is: " << floorValue << endl;
    else
        cout << "No floor exists for " << x << endl;

    return 0;
}
