#include<bits/stdc++.h>
using namespace std;
// Program to find shortest path in undirect graph with unit weights using BFS.
void shortest(vector<int> adj[], int v, int src) {
    vector<int> dist(v, INT_MAX);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]) {
            if(dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    for(int i = 0; i < v; i++) cout << dist[i] << " ";   
}

int main() {
    int v, e;
    cout << "Enter no of vertices and edges : ";
    cin >> v >> e;
    vector<int> adj[v + 1];
    for(int i = 0; i < e; i++) {
        int f, s;
        cout << i + 1 << ". " << "Enter two vertices that are connected directly : ";
        cin >> f >> s;
        adj[f].push_back(f);
        adj[s].push_back(s); 
    }
    shortest(adj, v, 0);
    return 0;
}