#include<bits/stdc++.h>
#define pb push_back
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

void dfs(TreeNode *root, int h, int &mh, vector<int> &ans)
{
    if(!root)
        return;
    
    if(h>mh) {
        ans.pb(root->val);
        mh = h;
    }

    dfs(root->left, h+1, mh, ans);
    dfs(root->right, h+1, mh, ans);
}

vector<int> left_view(TreeNode *root) 
{
    if(!root)
        return {};
    vector<int> ans = {root->val};

    int mh = 0;
    dfs(root, 0, mh, ans);
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

    vector<int> temp = left_view(root);
    for(int i=0;i<temp.size();i++) {
        cout<<temp[i]<<" ";
    }

    cout<<"\n";

    return 0;
}
