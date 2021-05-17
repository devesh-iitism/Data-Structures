#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void bfs(vector<vector<int>> g, int v, int start)
{
    vector<bool> visited(v, false);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    int i;
    while(!q.empty()) {
        i = q.front();
        q.pop();

        cout<<i<<" ";
        for(int j=0;j<g[i].size();j++) {
            if(!visited[g[i][j]]) {
                q.push(g[i][j]);
                visited[g[i][j]] = true;
            }
        }
    }
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
        // g[b].pb(a);
    }

    bfs(g, v, 0);
    return 0;
}