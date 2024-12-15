#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter the data: ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new node(data);
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrder(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void iterativePreorder(node* root) {
    if (root == NULL) return;

    stack<node*> s;
    s.push(root);

    cout << "Preorder traversal: ";
    while (!s.empty()) {
        node* curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if (curr->right) {
            s.push(curr->right);
        }
        if (curr->left) {
            s.push(curr->left);
        }
    }
    cout << endl;
}

void iterativeInorder(node* root) {
    stack<node*> s;
    node* curr = root;

    cout << "Inorder traversal: ";
    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

void iterativePostorder(node* root) {
    if (root == NULL) return;

    stack<node*> s1, s2;
    s1.push(root);

    cout << "Postorder traversal: ";
    while (!s1.empty()) {
        node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) {
            s1.push(curr->left);
        }
        if (curr->right) {
            s1.push(curr->right);
        }
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

int main() {
    // Sample input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    cout << "Level Order traversal is: " << endl;
    levelOrder(root);

    iterativePreorder(root);
    iterativeInorder(root);
    iterativePostorder(root);

    return 0;
}
