#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);

        TreeNode* node = new TreeNode(val);
        TreeNode* temp = root;

        while (true) {
            if (temp->val < val) {
                if (temp->right == NULL) {
                    temp->right = node;
                    break;
                } else {
                    temp = temp->right;
                }
            }
            else if (temp->val > val) {
                if (temp->left == NULL) {
                    temp->left = node;
                    break;
                } else {
                    temp = temp->left;
                }
            }
        }
        return root;
    }
};

// Inorder traversal to verify BST property
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
            8
           / \
          4   12
         / \  / \
        2  6 10 14
    */

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    Solution sol;

    int val = 5;
    root = sol.insertIntoBST(root, val);

    cout << "Inorder after inserting " << val << ": ";
    inorder(root);
    cout << endl;

    return 0;
}
