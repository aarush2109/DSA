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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    
    void preorder(TreeNode* node, vector<int>& ans) {
        if (node == nullptr) return;
        ans.push_back(node->val);       
        preorder(node->left, ans);       
        preorder(node->right, ans);       
    }
};

int main() {
    // Creating a sample binary tree:
    //        1
    //         \
    //          2
    //         /
    //        3

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
