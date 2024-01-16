
#include <bits/stdc++.h>
using namespace std;

//Basic Structure Of Tree Declaration
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

// Recursive Preorder Traversal Function
void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// Recursive Postorder Traversal Function
void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// Recursive Inorder Traversal Function
void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->right = new Node(2);
    root->left = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // Function Call of preorder Traversal
    cout << "Preorder Traversal is \n";
    preorder(root);
    cout << endl;
    // Function Call of posorder Traversal
    cout << "Postorder Traversal is \n";
    postorder(root);
    cout << endl;
    // Function Call of inorder Traversal
    cout << "Inorder Traversal is \n";
    inorder(root);

    return 0;
}
