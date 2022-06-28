// TC - O(n ^ 2) and SC - O(n) reduced some space to create adjacency list
    void dfs(int node, vector<vector<int>>& isConn, int n, vector<int>& vis) {
        vis[node] = 1;
        for(int i = 0; i < n; i++)
            if(isConn[node][i] == 1 && !vis[i]) dfs(i, isConn, n, vis);
    }
    int findCircleNum(vector<vector<int>>& isConn) {
        int n = isConn.size(), ans = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++)
            if(!vis[i]) {
                ans++;
                dfs(i, isConn, n, vis);
            }
        return ans;
    }
// TC - O(n ^ 2) and SC - O(n)
/*
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for(auto it : adj[node])
            if(!vis[it]) dfs(it, adj, vis);
    }
    int findCircleNum(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> adj;
        int n = mat.size(), m = mat[0].size(), ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == 1) adj[i + 1].push_back(j + 1);
        vector<int> vis(n + 1, 0);
        for(int i = 1; i < n + 1; i++) {
            if(!vis[i]) {
                ans++;
                dfs(i, adj, vis);
            }
        }
        return ans;
    }
*/