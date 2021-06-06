#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void tSortUtil(int i, vector<bool> &visited, vector<int> adj[], stack<int> &s) 
{
    visited[i] = true;
    
    for(int j=0;j<adj[i].size();j++) {
        if(!visited[adj[i][j]])
            tSortUtil(adj[i][j], visited, adj, s);
    }
    
    s.push(i);
}

void tSort(int V, vector<int> adj[], vector<int> &ans) 
{
    stack<int> s;
    vector<bool> visited(V, false);
    
    for(int i=0;i<V;i++) {
        if(!visited[i])
            tSortUtil(i, visited, adj, s);
    }
    
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> ans;
    tSort(V, adj, ans);
    return ans;
}

int main()
{
    int v, e;
    cin>>v>>e;

    vector<int> g[v];

    int a,b;
    for(int i=0;i<e;i++) {
        cin>>a>>b;
        g[a].pb(b);
    }

    vector<int> temp = topoSort(v, g);

    for(int i=0;i<v;i++) {
        cout<<temp[i]<<" ";
    }
    cout<<"\n";

    return 0;
}