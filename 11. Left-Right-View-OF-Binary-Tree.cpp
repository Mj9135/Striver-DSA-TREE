#include <bits/stdc++.h>
using namespace std;

// Basic Structure Of Tree Declaration
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to calculate the right view of a binary tree
void rightView(Node *root, int level, vector<int> &res2)
{
    if (root == NULL)
        return;
    if (level == res2.size())
        res2.push_back(root->data);
    rightView(root->right, level + 1, res2);
    rightView(root->left, level + 1, res2);
}

// Function to calculate the left view of a binary tree
void leftView(Node *root, int level, vector<int> &res1)
{
    if (root == NULL)
        return;
    if (level == res1.size())
        res1.push_back(root->data);
    leftView(root->left, level + 1, res1);
    leftView(root->right, level + 1, res1);
}

int main()
{
    // Creating a sample binary tree
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Calculate and display the left view of the binary tree
    vector<int> res1;
    leftView(root, 0, res1);
    cout << "Left View Of Binary Tree is \n";
    for (auto it : res1)
    {
        cout << it << " ";
    }

    // Calculate and display the right view of the binary tree
    vector<int> res2;
    rightView(root, 0, res2);
    cout << "\nRight View Of Binary Tree is \n";
    for (auto it : res2)
    {
        cout << it << " ";
    }

    return 0;
}
