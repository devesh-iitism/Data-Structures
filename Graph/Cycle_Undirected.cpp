#include<bits/stdc++.h>
#define pb push_back
using namespace std;

bool isCyclicUtil(vector<vector<int>> g, vector<bool> &visited, int i, int parent)
{
    visited[i] = true;

    for(int j=0;j<g[i].size();j++) {
        if(!visited[g[i][j]]) {
            if(isCyclicUtil(g, visited, g[i][j], i))
                return true;
        }
        else if(g[i][j]!=parent)
            return true;
    }
    return false;
}

bool isCyclic(vector<vector<int>> g, int v)
{
    vector<bool> visited(v, false);

    for(int i=0;i<v;i++) {
        if(!visited[i])
            if(isCyclicUtil(g, visited, i, -1))
                return true;
    }

    return false;
}

int main()
{
    int v,e;
    cin>>v>>e;

    vector<vector<int>> g(v, vector<int>());

    int a,b;

    for(int i=0;i<e;i++) {
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }

    cout<<isCyclic(g, v)<<endl;

    return 0;
}