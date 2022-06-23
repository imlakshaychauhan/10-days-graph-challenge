#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pip;
// Program to find Minimum Spanning Tree by Prim's Algorithm.
// TC - O(N*logN)
void prims(int N, vector<pair<int, int>> adj[]) {
    vector<int> parent(N, -1), mst(N, false), key(N, INT_MAX);
    priority_queue<pip, vector<pip>, greater<pip>> pq;
    pq.push({0, 0});
    key[0] = 0;
    for (int count = 0; count < N - 1; count++) {
        int u = pq.top().second;
        pq.pop(); 
        mst[u] = true;
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < key[v]) {
                parent[v] = u, key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    for (int i = 1; i < N; i++) cout << parent[i] << " - " << i << " \n";
}

int main()
{
    int N = 5, m = 6;
    vector<pair<int, int>> adj[N];

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    prims(N, adj);

    return 0;
}