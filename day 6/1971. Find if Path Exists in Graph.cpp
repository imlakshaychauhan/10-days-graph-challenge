// tc - O(n + e)
// sc - O(n)
// https://leetcode.com/problems/find-if-path-exists-in-graph/
bool validPath(int n, vector<vector<int>> &edges, int src, int dest) {
    if (src == dest)
        return true;
    vector<int> vis(n, 0);
    unordered_map<int, vector<int>> adj;
    for (auto &it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto &it : adj[node]) {
            if (it == dest)
                return true;
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return false;
}