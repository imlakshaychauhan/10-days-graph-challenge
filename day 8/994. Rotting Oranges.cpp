// https://leetcode.com/problems/rotting-oranges/
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if(i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == 1)
            return true;
        return false;
    }
    int bfs(queue<pair<int, int>> &q, vector<vector<int>>& grid, int n, int m) {
        int time = 0;
        while(!q.empty()) {
            int size = q.size(), temp = 0;
            while(size != 0) {
                int x1 = q.front().first, y1 = q.front().second;
                q.pop();
                // Created these two arrays for covering all 4 directions
                int ax[4] = {1, -1, 0, 0};
                int ay[4] = {0, 0, 1, -1};
                for(int i = 0; i < 4; i++) {
                    int x = ax[i] + x1;
                    int y = ay[i] + y1;
            // All four coordinates these iterations will cover
            // { x = 1, y = 0 || x = -1, y = 0 || x = 0, y = 1 || x = 0, y = -1}
                    if(isValid(x, y, n, m, grid)) {
                        temp++;
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
                size--;
            }
            if(temp != 0) time++;
        }
        return time;
    }
    bool isFresh(vector<vector<int>>& grid, int n, int m) {
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j] == 1) return 1;
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), fresh = 0, time = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
        
        // Checking if no fresh orange is present.
        // Which means number of minutes will be 0
        if(fresh == 0) return 0;
        
        // Now Starting BFS Traversal for
        time = bfs(q, grid, n, m);
        
        // Checking if fresh oranges are still here
        // Which means it is impossible to convert this fresh orange into rotten one
        if(isFresh(grid, n, m)) return -1;
        
        return time;
    }