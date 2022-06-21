// Function to detect cycle in an undirected graph using DFS.
bool check(int node, int parent, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            if (check(it, node, adj, vis)) return true;
            else if (parent != it) return true;
    return false;
}
bool isCycle(int v, vector<int> adj[]) {
    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
        if (!vis[i])
            if (check(i, -1, adj, vis)) return true;
    return false;
}