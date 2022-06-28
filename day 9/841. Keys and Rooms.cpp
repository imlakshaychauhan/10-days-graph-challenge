    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n = adj.size(), m = adj[0].size();
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto &it : adj[node])
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
        }
        for(int i = 0; i < n; i++) if(!vis[i]) return false;
        return true;
    }