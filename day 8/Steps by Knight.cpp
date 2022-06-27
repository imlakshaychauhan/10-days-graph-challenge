// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#
    bool isValid(int i, int j, int n, vector<vector<bool>>& vis) {
        if(i >= 0 && j >= 0 && i < n && j < n && !vis[i][j]) return true;
        return false;
    }
    int bfs(queue<pair<int, int>>& q, int n, vector<vector<bool>>& vis, int tx, int ty) {
        int ans = 0;
	    while(!q.empty()) {
	        int size = q.size();
	        ans++;
	        while(size != 0) {
	            int xx = q.front().first;
	            int yy = q.front().second;
	            q.pop();
	            int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
	            int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};
	            for(int i = 0; i < 8; i++) {
	                int x = xx + ax[i];
	                int y = yy + ay[i];
	                if(x == tx && y == ty) return ans;
	                if(isValid(x, y, n, vis)) {
	                    vis[x][y] = true;
	                    q.push({x, y});
	                }
	            }
	            size--;
	        }
	    }
	    return ans;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int n)
	{
	    int tx = tp[0] - 1, ty = tp[1] - 1;
	    int x1 = kp[0] - 1, y1 = kp[1] - 1;
	    if(x1 == tx && y1 == ty) return 0;
	    vector<vector<bool>> vis(n, vector<bool>(n, false));
	    queue<pair<int, int>> q;
	    q.push({x1, y1});
	    vis[x1][y1] = true;
	    return bfs(q, n, vis, tx, ty);
	}