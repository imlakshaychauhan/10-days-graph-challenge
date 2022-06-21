// Function to return Breadth First Traversal of given graph having multiple components in it.
vector<int> bfsOfGraph(int v, vector<int> adj[])
{
    vector<int> ans, vis(v, 0);
    for (int i = 0; i < v; i++)
        if (!vis[i]) {
            queue<int> q;
            vis[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    return ans;
}