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

int height(TreeNode *root, int &ans) {
    if(!root)
        return 0;
    int lh = height(root->left, ans);
    int rh = height(root->right, ans);
    
    ans = max(ans, 1+lh+rh);
    return 1+max(lh, rh);
}

int diameter(TreeNode* root) {
    int ans = 0;
    height(root, ans);
    return ans;
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

    cout<<diameter(root)<<endl;

    return 0;
}