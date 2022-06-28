    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if(i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == 0)
            return true;
        return false;
    }
    void dfs(int i, int j, int key, int n, int m, vector<vector<int>>& grid) {
        grid[i][j] = key;
        if(isValid(i, j + 1, n, m, grid)) dfs(i, j + 1, key, n, m, grid);
        if(isValid(i + 1, j, n, m, grid)) dfs(i + 1, j, key, n, m, grid);
        if(isValid(i, j - 1, n, m, grid)) dfs(i, j - 1, key, n, m, grid);
        if(isValid(i - 1, j, n, m, grid)) dfs(i - 1, j, key, n, m, grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n; i++) {
            int j = 0;
            if(grid[i][j] == 0) dfs(i, j, 1, n, m, grid);
            j = m - 1;
            if(grid[i][j] == 0) dfs(i, j, 1, n, m, grid);
        }
        for(int j = 0; j < m; j++) {
            int i = 0;
            if(grid[i][j] == 0) dfs(i, j, 1, n, m, grid);
            i = n - 1;
            if(grid[i][j] == 0) dfs(i, j, 1, n, m, grid);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    ans++;
                    dfs(i, j, 1, n, m, grid);
                }
            }
        }
        return ans;
    }