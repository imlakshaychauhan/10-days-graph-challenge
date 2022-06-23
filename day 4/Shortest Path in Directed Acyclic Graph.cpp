#include<bits/stdc++.h>
using namespace std;
// Program to find shortest path in Directed Acyclic Graph.

void findTopo(int node, stack<int> &st, vector<pair<int, int>> adj[], vector<int> &vis) {
    vis[node] = 1;
    for(auto it : adj[node])
        if(!vis[it.first]) findTopo(it.first, st, adj, vis);
    st.push(node);  
}

void shortestPath(int src, int v, vector<pair<int, int>> adj[]) {
    vector<int> vis(v, 0), dist(v, INT_MAX);
    stack<int> st;
    for(int i = 0; i < v; i++) if(!vis[i]) findTopo(i, st, adj, vis);
    dist[src] = 0;
	while(!st.empty())  {  
		int node = st.top(); st.pop();
		if (dist[node] != INT_MAX)
		    for(auto it : adj[node])
		        if(dist[node] + it.second < dist[it.first])
		            dist[it.first] = dist[node] + it.second;
	}
    for(int i = 0; i < v; i++) cout << dist[i] << " ";
}

int main() { 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0; i < m; i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v,  wt}); 
	}
	shortestPath(0, n, adj); 
	return 0; 
} 