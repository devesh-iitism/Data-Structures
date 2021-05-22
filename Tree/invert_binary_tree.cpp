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

void inOrder(TreeNode *root)
{
    if(!root)
        return;
    
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

TreeNode *invert(TreeNode *root)
{
    if(!root)
        return NULL;
    
    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = temp;

    invert(root->left);
    invert(root->right);

    return root;
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

    inOrder(root);
    cout<<endl;
    root = invert(root);
    inOrder(root);
    return 0;
}