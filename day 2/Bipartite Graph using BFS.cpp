bool isBipartite(int v, vector<int> adj[]) {
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto it : adj[node])
                    if (color[it] == -1) {
                        color[it] = 1 - color[node];
                        q.push(it);
                    }
                    else if (color[it] == color[node])
                        return false;
            }
        }
    return true;
}