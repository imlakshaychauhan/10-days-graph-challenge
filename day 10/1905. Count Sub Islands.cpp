void dfs(int i, int j, int m, int n, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int &res){
        if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) return;
        if(grid1[i][j] == 0){
            res = 0;
			return;
        }
        grid2[i][j] = 0;
        dfs(i + 1, j, m, n, grid1, grid2, res);
        dfs(i - 1, j, m, n, grid1, grid2, res);
        dfs(i, j + 1, m, n, grid1, grid2, res);
        dfs(i, j - 1, m, n, grid1, grid2, res);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid2[i][j] == 1){
                    int res = 1;
                    dfs(i, j, m, n, grid1, grid2, res);
                    ans += res;
                }
        return ans;
    }