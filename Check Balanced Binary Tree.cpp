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
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}
bool isBalanced(Node *root) // Time Complexity Of this Code is O(n*n);
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    int diff = abs(lh - rh);
    if (diff <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int height2(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = height2(root->left);
    int rh = height2(root->right);
    if (lh == -1 || rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}
bool isBalanced2(Node *root)  // Time Complexity Of this code is O(n)
{
    return height2(root) != -1;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    if (isBalanced2(root))
        cout << "Tree is Balanced";
    else
        cout << "Tree is Unbalanced";
    return 0;
}
