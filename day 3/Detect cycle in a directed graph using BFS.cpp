// Function to detect cycle in a directed graph using BFS.
bool isCyclic(int v, vector<int> adj[]) {
    queue<int> q;
    vector<int> in(v, 0);
    int c = 0;
    for (int i = 0; i < v; i++) for (auto it : adj[i]) in[it]++;
    for (int i = 0; i < v; i++) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        c++;
        for (auto it : adj[node]) {
            in[it]--;
            if (!in[it]) q.push(it);
        }
    }
    if (c == v) return false;
    return true;
}