/*
current=root
while(root!=NULL)
If the current does not have left child
Print current’s data
Go to the right, i.e., current = current->right
     left not exits visit (current)->right
else
    predecessor=find()(left then right jata jana jb tk null)
     if(pred->right==null)
        pre->right=current;
        current=current->left
        else
        pred->right=null
        viist(current)
        current=current->right

*/
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
vector<int> inOrder(node *root)
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
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                result.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return result;
}
int main()
{
    // Representation of input binary tree:
    //           1
    //          / \ 
    //         2   3
    //            / \  
    //           4   5
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);

    vector<int> result = inOrder(root);

    for (int data : result)
    {
        cout << data << " ";
    }

    return 0;
}