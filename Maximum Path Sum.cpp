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

int height(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = max(0, height(root->left, maxi));
    int rh = max(0, height(root->right, maxi));
    maxi = max(maxi, root->data + lh + rh);
    return root->data + max(lh, rh);
}
int findMaxSum(Node *root)
{
    int maxi = INT_MIN;
    height(root, maxi);
    return maxi;
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
    cout << "Maximum Path Sum is:-" << findMaxSum(root);
    return 0;
}
