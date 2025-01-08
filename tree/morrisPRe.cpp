#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector<int> preOrder(node *root)
{
    vector<int> result;
    node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            result.push_back(curr->data); 
            curr = curr->right;
        }
        else
        {
            node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                result.push_back(curr->data); 
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return result;
}

int main()
{
    // Constructing binary tree.
    //
    //             1
    //            / \
    //           /   \
    //          2     3
    //         / \   / \
    //        /   \ /   \
    //       4    5 6    7
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> result = preOrder(root);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
