#include <bits/stdc++.h>
using namespace std;

// Basic Structure Of Tree Declaration
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    // Constructor to initialize Node with a given value
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to find the path from the root to a given node
bool rootToNode(Node *root, vector<int> &ans, int x)
{
    // Base case: If the root is null, return false
    if (!root)
        return false;

    // Push the current node's data to the path vector
    ans.push_back(root->data);

    // If the current node contains the target value 'x', return true
    if (root->data == x)
        return true;

    // Recursively search in the left and right subtrees
    if (rootToNode(root->left, ans, x) || rootToNode(root->right, ans, x))
    {
        return true;
    }

    // If the target value is not found in the subtree rooted at the current node,
    // backtrack by removing the current node from the path vector
    ans.pop_back();
    return false;
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

    // Target node value to find the path to
    int x = 5;

    // Vector to store the path from the root to the target node
    vector<int> ans;

    // Call the function to find the path and store the result in 'y'
    bool y = rootToNode(root, ans, x);

    // Display the path from the root to the target node
    cout << "Root to Node Path is \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
