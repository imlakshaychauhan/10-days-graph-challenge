#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pip;
void dijkstra(int src, int v, vector<pair<int, int>> adj[]) {
    priority_queue<pip, vector<pip>, greater<pip>> pq;
    vector<int> dist(v + 1, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node])
            if(dist[node] + it.second < dist[it.first]) {
                dist[it.first] = dist[node] + it.second;
                pq.push({dist[it.first], it.first});
            }
    }
    for(int i = 1; i <= v; i++) cout << dist[i] << " ";
}

int main() { 
	int n = 5, m = 6;
	vector<pair<int, int>> adj[n + 1];
	adj[1].push_back({2,2});
	adj[1].push_back({4,1});
	adj[2].push_back({1,2});
	adj[2].push_back({5,5});
	adj[2].push_back({3,4});
	adj[3].push_back({2,4});
	adj[3].push_back({4,3});
	adj[3].push_back({5,1});
	adj[4].push_back({1,1});
	adj[4].push_back({3,3});
	adj[5].push_back({2,5});
	adj[5].push_back({3,1});
	dijkstra(1, n, adj); 
	return 0; 
} 