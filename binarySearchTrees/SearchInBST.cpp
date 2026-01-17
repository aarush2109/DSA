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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL && root->val != val) {
            if (root->val < val)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }
};

// Inorder traversal to verify BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
            4
           / \
          2   7
         / \
        1   3
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    int key = 2;
    TreeNode* result = sol.searchBST(root, key);

    if (result != NULL) {
        cout << "Node found with value: " << result->val << endl;
        cout << "Inorder of subtree: ";
        inorder(result);
    } else {
        cout << "Value not found in BST";
    }

    return 0;
}
