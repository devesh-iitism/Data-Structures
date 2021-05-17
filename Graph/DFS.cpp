#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void dfsUtil(vector<vector<int>> g, vector<bool> &visited, int i)
{
    cout<<i<<" ";
    visited[i] = true;

    for(int j=0;j<g[i].size();j++) {
        if(!visited[g[i][j]])
            dfsUtil(g, visited, g[i][j]);
    }
}

void dfs(vector<vector<int>> g, int v)
{
    vector<bool> visited(v, false);

    for(int i=0;i<v;i++) {
        if(!visited[i])
            dfsUtil(g, visited, i);
    }
}

int main() 
{
    int v, e;
    cin>>v>>e;

    vector<vector<int>> g(v, vector<int>());

    int a,b;
    for(int i=0;i<e;i++) {
        cin>>a>>b;
        g[a].pb(b);
        // g[b].pb(a);
    }

    dfs(g, v);

    return 0;
}