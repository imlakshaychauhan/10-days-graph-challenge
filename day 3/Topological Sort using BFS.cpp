// Function to return list containing vertices in Topological order using BFS.
vector<int> topoSort(int v, vector<int> adj[]) {
    vector<int> in(v, 0), ans;
    queue<int> q;
    for (int i = 0; i < v; i++) for (auto it : adj[i]) in[it]++;
    for (int i = 0; i < v; i++) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node]) {
            in[it]--;
            if (!in[it]) q.push(it);
        }
    }
    return ans;
}