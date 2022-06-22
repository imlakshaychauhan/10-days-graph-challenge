// Function to detect cycle in a directed graph using DFS.
bool check(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs_vis) {
    vis[node] = 1;
    dfs_vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it]) {
            if (check(it, adj, vis, dfs_vis)) return true;
        }
        else if (dfs_vis[it]) return true;
    dfs_vis[node] = 0;
    return false;
}
bool isCyclic(int v, vector<int> adj[])
{
    vector<int> vis(v, 0), temp(v, 0);
    for (int i = 0; i < v; i++)
        if (!vis[i]) if (check(i, adj, vis, temp)) return true;
    return false;
}