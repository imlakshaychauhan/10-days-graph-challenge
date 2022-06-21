// Function to detect cycle in an undirected graph using bfs.
bool isCycle(int v, vector<int> adj[]) {
    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
        if (!vis[i]) {
            queue<pair<int, int>> q;
            vis[i] = 1;
            q.push({i, -1});
            while (!q.empty()) {
                int node = q.front().first, par = q.front().second;
                q.pop();
                for (auto it : adj[node])
                    if (!vis[it]) {
                        q.push({it, node});
                        vis[it] = 1;
                    }
                    else if (par != it) return true;
            }
        }
    return false;
}