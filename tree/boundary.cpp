#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    void traverseLeft(Node* root, vector<int>& ans) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return;

        ans.push_back(root->data);
        if (root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    void traverseRight(Node* root, vector<int>& ans) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return;

        if (root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);

        ans.push_back(root->data); // Add after recursion to reverse order
    }

    void traverseLeaf(Node* root, vector<int>& ans) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    vector<int> boundary(Node* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        ans.push_back(root->data);

        // Traverse the left boundary (excluding leaf nodes)
        traverseLeft(root->left, ans);

        // Traverse all leaf nodes
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        // Traverse the right boundary (excluding leaf nodes) in reverse order
        vector<int> rightBoundary;
        traverseRight(root->right, rightBoundary);
        ans.insert(ans.end(), rightBoundary.begin(), rightBoundary.end());

        return ans;
    }
};

int main() {
    // Example usage:
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.boundary(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
