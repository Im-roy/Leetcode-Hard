class Solution {
public:
    
    vector<vector<int>> mat;
    int n, m, k, mod = 1e9 + 7;
    int dp[50005][55];
    int help(int i, int j, int val){
        if(i == n-1 and j == m-1){
            if(val%k == 0)
                return 1;
            return  0;
        }
        
        if(dp[m*i + j][val] != -1)
            return dp[m*i + j][val]%mod;
        
        int left = 0, right = 0;
        if(i+1 < n)
            left = help(i+1, j, (val + mat[i+1][j])%k);
        if(j+1 < m)
            right = help(i, j+1, (val + mat[i][j+1])%k);
        return dp[m*i + j][val] = (left + right)%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int _k) {
        
        memset(dp, -1, sizeof(dp));
        n = grid.size();
        m = grid[0].size();
        
        k = _k;
        mat = grid;
        return help(0, 0, grid[0][0]%k);
    }
};