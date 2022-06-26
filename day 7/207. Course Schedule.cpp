// https://leetcode.com/problems/course-schedule/
    bool dfs(int node, unordered_map<int, vector<int>> &preq, vector<int> &vis, vector<int> &dfs_vis) {
        vis[node] = 1;
        dfs_vis[node] = 1;
        for(auto& it : preq[node])
            if(!vis[it]) {
                if(dfs(it, preq, vis, dfs_vis))
                    return true;
            }
            else if(vis[it] && dfs_vis[it])
                return true;
        dfs_vis[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& adj) {
        unordered_map<int, vector<int>> preq;
        for(auto &it : adj) preq[it[0]].push_back(it[1]);
        vector<int> vis(n, 0), dfs_vis(n, 0);
        for(int i = 0; i < n; i++)
            if(!vis[i])
                if(dfs(i, preq, vis, dfs_vis)) 
                    return false;
        return true;
    }