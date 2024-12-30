#include <bits/stdc++.h>

using namespace std;

struct treeNode
{
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

// Inorder traversal to store elements in a vector
void inorderTraversal(treeNode *root, vector<int> &elements)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, elements);
    elements.push_back(root->val);
    inorderTraversal(root->right, elements);
}

// Function to merge two sorted arrays
vector<int> mergeSortedArrays(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            merged.push_back(arr1[i++]);
        }
        else
        {
            merged.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size())
    {
        merged.push_back(arr1[i++]);
    }
    while (j < arr2.size())
    {
        merged.push_back(arr2[j++]);
    }
    return merged;
}

// Function to build a balanced BST from a sorted array
treeNode *buildBalancedBST(const vector<int> &sortedArray, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    treeNode *root = new treeNode(sortedArray[mid]);
    root->left = buildBalancedBST(sortedArray, start, mid - 1);
    root->right = buildBalancedBST(sortedArray, mid + 1, end);
    return root;
}

// Function to merge two BSTs
treeNode *mergeBST(treeNode *root1, treeNode *root2)
{
    vector<int> elements1, elements2;
    inorderTraversal(root1, elements1);
    inorderTraversal(root2, elements2);
    vector<int> mergedElements = mergeSortedArrays(elements1, elements2);
    return buildBalancedBST(mergedElements, 0, mergedElements.size() - 1);
}

// Utility function to print Inorder Traversal of a BST
void printInorder(treeNode *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    treeNode *root1 = new treeNode(3);
    root1->left = new treeNode(1);
    root1->right = new treeNode(4);

    treeNode *root2 = new treeNode(5);
    root2->left = new treeNode(3);
    root2->right = new treeNode(6);

    cout << "Inorder of BST1: ";
    printInorder(root1);
    cout << endl;

    cout << "Inorder of BST2: ";
    printInorder(root2);
    cout << endl;

    // Merging the two BSTs
    treeNode *mergedRoot = mergeBST(root1, root2);

    cout << "Inorder of Merged BST: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}
