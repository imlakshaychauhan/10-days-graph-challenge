// Function to return a list containing the DFS traversal of the graph with multiple components in it.
void dfs(int node, vector<int> adj[], vector<int> &ans, vector<int> &vis)
{
    ans.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, adj, ans, vis);
}
vector<int> dfsOfGraph(int v, vector<int> adj[])
{
    vector<int> ans, vis(v, 0);
    for(int i = 0; i < v; i++)
        if(!vis[i])
            dfs(i, adj, ans, vis);
    return ans;
}