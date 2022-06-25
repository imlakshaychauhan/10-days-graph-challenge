#include<bits/stdc++.h>
using namespace std;
// Program to find Minimum Spanning Tree by Kruskal's Algorithm
// TC - O(M * log M)
// SC - O(N)
struct node {
    int u, v, wt;
    node(int x, int y, int z) {
        u = x;
        v = y;
        wt = z;
    }
};

void makeSet(int n, vector<int> &parent, vector<int> &ranks) {
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findPar(int node, vector<int> &parent) {
    if(node == parent[node]) return node;
    return parent[node] = findPar(parent[node], parent); // path compression line
}

void doUnion(int u, int v, vector<int> &parent, vector<int> &ranks) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(ranks[u] < ranks[v]) parent[u] = v;
    else if(ranks[u] > ranks[v]) parent[v] = u;
    else {
        parent[v] = u;
        ranks[u]++;
    }
}
bool comp(node a, node b) {
    return a.wt < b.wt;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin  >> u >> wt;
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);
    vector<int> parent(n, 0), ranks(n, 0);
    for(int i = 0; i < n; i++) parent[i] = i;
    int cost = 0;
    vector<pair<int, int>> mst;
    for(auto it : edges)
        if(findPar(it.u, parent) != findPar(it.v, parent)) {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            doUnion(it.u, it.v, parent, ranks);
        }
    cout << "Total of Cost of MST : " << cost << endl;
    for(auto it : mst) cout << it.first << " - " << it.second << endl;
    return 0;
}