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

// Function to implement all three travesal in one function
void traversal(Node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
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
    vector<int> pre, in, post;
    traversal(root, pre, in, post);
    cout << "Preorder Traversal is \n";
    for (auto x : pre)
    {
        cout << x << " ";
    }
    cout << "\nIn order Traversal is \n";
    for (auto x : in)
    {
        cout << x << " ";
    }
    cout << "\nPostOrder Traversal is \n ";
    for (auto x : post)
    {
        cout << x << " ";
    }
    return 0;
}
