#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void dfs(int i, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[i] = true;
    
    for(auto j: adj[i]) {
        if(!visited[j])
            dfs(j, adj, visited);
    }
}

int makeConnected(int n, vector<vector<int>>& A) {
    if(n>A.size()+1)
        return -1;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    int ans = 0;
    
    for(auto k: A) {
        adj[k[0]].pb(k[1]);
        adj[k[1]].pb(k[0]);
    }
    
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            ans++;
            dfs(i, adj, visited);
        }
    }
    
    return (ans-1);
}

int main()
{
    cout<<"Enter number of computers: ";
    int n;
    cin>>n;

    cout<<"Enter number of connected edges: ";
    int m;
    cin>>m;
    vector<vector<int>> A;
    int x;

    cout<<"Enter the Edges\n";
    for(int i=0;i<m;i++) {
        vector<int> temp;
        for(int j=0;j<2;j++) {
            cin>>x;
            temp.pb(x);
        }
        A.pb(temp);
    }

    cout<<"Ans: "<<makeConnected(n, A)<<endl;
    return 0;
}