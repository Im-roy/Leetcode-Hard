class Solution {
public:

    vector<vector<int>> grid;
    int n, m, dp[1005][1005], mn = INT_MAX, mod = 1e9 + 7;
    bool vis[1005][1005];
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    

    bool isValid(int i, int j){
        if(i < 0 or i >= n or j < 0 or j >= m)
            return false;
        return true;
    }

    int help(int i, int j){
        if(grid[i][j] == mn){
            return dp[i][j] = 1;
        }

        if(dp[i][j] != -1)
            return dp[i][j]%mod;

        int ans = 0;
        for(int x=0; x<4; x++){
            int ni = i + dx[x];
            int nj = j + dy[x];
            if(isValid(ni, nj) and grid[i][j] > grid[ni][nj]){
                ans += help(ni, nj)%mod;
            }
        }
        ans += 1;
        return dp[i][j] = ans;
    }

    int countPaths(vector<vector<int>>& _grid) {
        
        vector<pair<int, int>> vp;
        grid = _grid;
        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));
        memset(vis, false, sizeof(vis));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mn = min(mn, grid[i][j]);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    help(i, j);
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans += (dp[i][j]%mod);
                ans %= mod;
            }
        }

        return ans%mod;
    }
};