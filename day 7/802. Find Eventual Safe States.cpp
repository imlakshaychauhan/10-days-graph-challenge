// https://leetcode.com/problems/find-eventual-safe-states/
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &dfs_vis, vector<bool> &isCycle) {
        vis[node] = 1; dfs_vis[node] = 1;
        for(auto &it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it, adj, vis, dfs_vis, isCycle)) return isCycle[node] = true;
            }
            else if(vis[it] && dfs_vis[it]) return isCycle[node] = true;
        }
        dfs_vis[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> vis(v, 0), dfs_vis(v, 0), ans;
        vector<bool> isCycle(v, false);
        for(int i = 0; i < v; i++)
            if(!vis[i])
                dfs(i, adj, vis, dfs_vis, isCycle);
        for(int i = 0; i < v; i++)
            if(!isCycle[i]) ans.push_back(i);
        return ans;
    }