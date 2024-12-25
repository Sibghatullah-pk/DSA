#include <iostream>
#include <vector>
#include <queue>
#include <deque>

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
    vector<int> zigzagTraversal(Node* root) {
        vector<int> result;
        if (root == nullptr) 
            return result;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            deque<int> level;

            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                if (leftToRight) {
                    level.push_back(frontNode->data);
                } else {
                    level.push_front(frontNode->data);
                }

                if (frontNode->left) 
                    q.push(frontNode->left);

                if (frontNode->right) 
                    q.push(frontNode->right);
            }

            // Append the current level to the result
            for (int val : level) {
                result.push_back(val);
            }

            // Switch the direction
            leftToRight = !leftToRight;
        }

        return result;
    }
};

int main() {
    // Example Usage
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.zigzagTraversal(root);

    cout << "Zigzag Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
