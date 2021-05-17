#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left, *right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

void levelOrder(TreeNode *root)
{
    if(!root)
        return;
    
    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *temp = q.front();
        cout<<temp->val<<" ";
        q.pop();

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);
    root->right->right->left = new TreeNode(11);

    levelOrder(root);
    return 0;
}