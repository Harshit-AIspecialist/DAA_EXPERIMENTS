#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int>dijkstra(int V,vector<vector<pii>> &adj,int src) {
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vector<int> dist(V, INT_MAX);
    dist[src]= 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d= pq.top().first;
        int u = pq.top().second;
        pq.pop();
      
        if (d >dist[u]) continue;

        for (auto &edge: adj[u]) {
            int v= edge.first;
            int weight= edge.second;

            if (dist[u]+ weight < dist[v]) {
                dist[v]= dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
