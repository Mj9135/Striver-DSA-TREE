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

bool isLeaf(Node *root)
{
    return !root->left && !root->right;
}

void addLeft(Node *root, vector<int> &res)
{
    // Adds the left boundary nodes to the result vector
    Node *temp = root->left;
    while (temp)
    {
        if (!isLeaf(temp))
        {
            res.push_back(temp->data);
        }
        if (temp->left)
            temp = temp->left;
        else
            temp = temp->right;
    }
}

void addLeaf(Node *root, vector<int> &res)
{
    // Adds the leaf nodes to the result vector
    if (isLeaf(root))
{
        res.push_back(root->data);
        return;
}
    if (root->left)
        addLeaf(root->left, res);
    if (root->right)
        addLeaf(root->right, res);
}

void addRight(Node *root, vector<int> &res)
{
    // Adds the right boundary nodes to the result vector
    Node *temp = root->right;
    vector<int> temp2;
    while (temp)
    {
        if (!isLeaf(temp))
        {
            temp2.push_back(temp->data);
        }
        if (temp->right)
            temp = temp->right;
        else
            temp = temp->left;
    }
    reverse(temp2.begin(), temp2.end());
    for (auto x : temp2)
    {
        res.push_back(x);
    }
}

vector<int> printBoundary(Node *root)
{
    // Prints the boundary traversal of the binary tree
    vector<int> res;
    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeft(root, res);

    addLeaf(root, res);

    addRight(root, res);
    return res;
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

    // Calling the printBoundary function and storing the result in boundaryTraversal vector
    vector<int> boundaryTraversal;
    boundaryTraversal = printBoundary(root);

    // Printing the result
    cout << "The Boundary Traversal is : ";
    for (int i = 0; i < boundaryTraversal.size(); i++)
    {
        cout << boundaryTraversal[i] << " ";
    }
    return 0;
}
