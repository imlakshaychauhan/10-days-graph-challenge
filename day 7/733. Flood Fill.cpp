// https://leetcode.com/problems/flood-fill/
    bool isValid(vector<vector<int>>& image, int i, int j, int st) {
        if(i >= 0 && j >= 0 && i < image.size() && j < image[0].size() && image[i][j] == st)
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int st, int color) {
        image[sr][sc] = color;
        if(isValid(image, sr + 1, sc, st)) 
            dfs(image, sr + 1, sc, st, color);
        if(isValid(image, sr, sc + 1, st))
            dfs(image, sr, sc + 1, st, color);
        if(isValid(image, sr - 1, sc, st)) 
            dfs(image, sr - 1, sc, st, color);
        if(isValid(image, sr, sc - 1, st)) 
            dfs(image, sr, sc - 1, st, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }