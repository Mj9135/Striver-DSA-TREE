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

// Preorder Traversal Technique without recusion
void preorder(struct Node *root, vector<int> &ans)
{
    stack<Node *> st;
    st.push(root);
    while (st.size())
    {
        Node *temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if (temp->right != NULL)
            st.push(temp->right);
        if (temp->left != NULL)
            st.push(temp->left);
    }
    return;
}

// Inorder Traversal Technique without Recursion
void inorder(struct Node *root, vector<int> &ans2)
{
    stack<Node *> st;
    Node *temp = root;
    while (st.size() || temp != NULL)
    {

        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }

        temp = st.top();
        st.pop();
        ans2.push_back(temp->data);

        temp = temp->right;
    }

    return;
}
// Postorder Traversal Technique without Recursion
void postorder(struct Node *root, vector<int> &ans3)
{
    Node *temp = root;
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->left != NULL)
            st1.push(temp->left);
        if (temp->right != NULL)
            st1.push(temp->right);
    }
    while (!st2.empty())
    {
        temp = st2.top();
        st2.pop();
        ans3.push_back(temp->data);
    }
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
    vector<int> ans;
    preorder(root, ans);
    cout << "Preorder Traversal is \n";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    vector<int> ans2;
    inorder(root, ans2);
    cout << "\nInorder Traversal is \n";
    for (auto x : ans2)
    {
        cout << x << " ";
    }
    vector<int> ans3;
    postorder(root, ans3);
    cout << "\nPostorder Traversal is \n";
    for (auto x : ans3)
    {
        cout << x << " ";
    }
    return 0;
}
