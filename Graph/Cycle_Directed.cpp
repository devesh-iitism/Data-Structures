#include<bits/stdc++.h>
#define pb push_back
using namespace std;

bool isCyclicUtil(vector<vector<int>> g, int i, vector<bool> &visited, vector<bool> &recStack)
{
    if(!visited[i]) {
        visited[i] = true;
        recStack[i] = true;

        for(int j=0;j<g[i].size();j++) {
            if(!visited[g[i][j]] && isCyclicUtil(g, g[i][j], visited, recStack))
                return true;
            else if(recStack[g[i][j]])
                return true;
        }
    }
    recStack[i] = false;
    return false;
}

bool isCyclic(vector<vector<int>> g, int v)
{
    vector<bool> visited(v, false);
    vector<bool> recStack(v, false);

    for(int i=0;i<v;i++) {
        if(isCyclicUtil(g, i, visited, recStack))
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
    }

    cout<<isCyclic(g, v)<<endl;

    return 0;
}