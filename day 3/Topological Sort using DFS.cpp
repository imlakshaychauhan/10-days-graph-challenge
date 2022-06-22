// Function to return list containing vertices in Topological order using DFS.
void findTopoSort(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) if (!vis[it]) findTopoSort(it, adj, vis, st);
    st.push(node);
}
vector<int> topoSort(int v, vector<int> adj[])
{
    vector<int> vis(v, 0), ans;
    stack<int> st;
    for (int i = 0; i < v; i++) if (!vis[i]) findTopoSort(i, adj, vis, st);
    while (!st.empty()) ans.push_back(st.top()), st.pop();
    return ans;
}