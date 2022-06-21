bool check(int node, vector<int> adj[], vector<int> &color) {
    if (color[node] == -1) color[node] = 1;
    for (auto it : adj[node])
        if (color[it] == -1) {
            color[it] = 1 - color[node];
            if (check(it, adj, color)) return true;
        }
        else if (color[it] == color[node]) return false;
    return true;
}
bool isBipartite(int v, vector<int> adj[])
{
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
        if (color[i] == -1)
            if (check(i, adj, color))
                return true;
    return false;
}