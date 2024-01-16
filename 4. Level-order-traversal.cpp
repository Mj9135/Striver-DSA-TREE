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
// Function of  level order Traversal
void levelOrder(struct Node *root, vector<int> &ans)
{
    queue<Node *> q;
    q.push(root);
    while (q.size())
    {
        vector<int> level;
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            Node *temp = q.front();
            q.pop();
            level.push_back(temp->data);
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        for (auto it : level)
        {
            ans.push_back(it);
        }
    }
    return;
}

//Function of zigzag level order Traversal
void levelOrderZigZag(struct Node *root, vector<int> &ans2)
{
    queue<Node *> q;
    q.push(root);
    bool flag = false;
    while (q.size())
    {
        vector<int> level;
        int s = q.size();

        for (int i = 0; i < s; i++)
        {
            Node *temp = q.front();
            q.pop();
            level.push_back(temp->data);
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        if (flag == true)
        {
            reverse(level.begin(), level.end());
            flag = !flag;
        }
        else
        {
            flag = !flag;
        }
        for (auto it : level)
        {
            ans2.push_back(it);
        }
        }
    return;
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
    vector<int> ans2;
    levelOrder(root, ans);
    cout << "Level Order Traversal " << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << "\nZigzag Level Order Traversal " << endl;
    levelOrderZigZag(root, ans2);
    for (auto it : ans2)
    {
        cout << it << " ";
    }
    return 0;
}
