#include <bits/stdc++.h>
using namespace std;

// Basic structure Of Tree Declaration
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

void topView(Node *root, vector<int> &res)
{

    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *temp = it.first;
        int line = it.second;
        if (mp.find(line) == mp.end())
        {
            mp[line] = temp->data;
        }
        if (temp->left)
            q.push({temp->left, line - 1});
        if (temp->right)
            q.push({temp->right, line + 1});
    }

    for (auto it : mp)
    {
        res.push_back(it.second);
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
    vector<int> res;
    topView(root, res);
    cout << "Top View Of Binary Tree is \n";
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}
