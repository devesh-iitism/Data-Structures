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

void reverseLevelOrder(TreeNode *root)
{
    vector<vector<int>> levels;

    vector<int> temp;

    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();

        while(n--) {
            TreeNode *node = q.front();
            temp.pb(node->val);
            q.pop();

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        levels.pb(temp);
        temp.clear();
    }

    for(int i=levels.size()-1;i>=0;i--) {
        for(int j=0;j<levels[i].size();j++)
            cout<<levels[i][j]<<" ";
    }
    cout<<endl;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->right->left = new TreeNode(50);
    root->right->right = new TreeNode(60);

    reverseLevelOrder(root);

    return 0;
}