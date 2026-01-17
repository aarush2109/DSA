#include <bits/stdc++.h>
using namespace std;

/*
Definition for Binary Tree Node
*/
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    void getPath(vector<vector<int>> &ans, vector<int> &path, Node* node) {
        if (node == NULL) return;

        path.push_back(node->data);

        if (node->left == NULL && node->right == NULL) {
            ans.push_back(path);
        } else {
            getPath(ans, path, node->left);
            getPath(ans, path, node->right);
        }

        path.pop_back();  // backtrack
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> path;
        getPath(ans, path, root);
        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<vector<int>> paths = sol.Paths(root);

    cout << "Root to Leaf Paths:\n";
    for (auto &p : paths) {
        for (int x : p) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
