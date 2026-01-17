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
    void inorder(TreeNode* root, int k, vector<int> &ans) {
        if (root == NULL) return;
        inorder(root->left, k, ans);
        ans.push_back(root->val);
        inorder(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, k, ans);
        return ans[k - 1];
    }
};

int main() {
    /*
        Example BST:
              5
             / \
            3   6
           / \
          2   4
         /
        1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution obj;
    int k = 3;

    cout << "Kth Smallest Element: " << obj.kthSmallest(root, k) << endl;

    return 0;
}


//most optimal solution

// class Solution {
// public:
//         int helper(TreeNode* root, int k, int &count) {
//         if (root == NULL) return -1;

//         int left = helper(root->left, k, count);
//         if (left != -1) return left;

//         count++;
//         if (count == k) return root->val;

//         return helper(root->right, k, count);
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         int count = 0;
//         return helper(root, k, count);
//     }
// };