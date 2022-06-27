// https://leetcode.com/problems/max-area-of-island/
    int count = 0;
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if(i >= 0 && i < n && j >= 0  && j < m && grid[i][j] == 1)
            return true;
        return false;
    }
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid) {
        grid[i][j] = 0;
        count++;
        if(isValid(i, j + 1, n, m, grid))
            dfs(i, j + 1, n, m, grid);
        if(isValid(i + 1, j, n, m, grid))
            dfs(i + 1, j, n, m, grid);
        if(isValid(i, j - 1, n, m, grid))
            dfs(i, j - 1, n, m, grid);
        if(isValid(i - 1, j, n, m, grid))
            dfs(i - 1, j, n, m, grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1) {
                    dfs(i, j, n, m, grid);
                    ans = max(ans, count);
                    count = 0;
                }
        return ans;
    }