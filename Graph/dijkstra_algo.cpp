#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define iPair pair<int, int>

using namespace std;

//typedef pair<int, int> iPair;

void dijkstra(vector<vector<iPair>> g, int src, int V)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(V, 101);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(int i=0;i<g[u].size();i++) {
            int v = g[u][i].first;
            int weight = g[u][i].second;

            if(dist[u]+weight<dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    int v,e;
    cin>>v>>e;

    vector<vector<iPair>> g(v, vector<iPair>());

    int a,b,w;

    for(int i=0;i<e;i++) {
        cin>>a>>b>>w;
        g[a].push_back(make_pair(b, w));
        g[b].push_back(make_pair(a, w));
    }

    dijkstra(g, 0, v);
    return 0;
}
