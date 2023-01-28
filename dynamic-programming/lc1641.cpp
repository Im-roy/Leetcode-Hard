class Solution {
public:
    int n, dp[55][5];
    int f(int i, int pos) {
        if(i == n)
            return 1;
        if(dp[i][pos] != -1)
            return dp[i][pos];
        int ans = 0;
        for(int j=pos; j<5; j++){
            ans += f(i+1, j);
        }
        return dp[i][pos] = ans;
    }
    int countVowelStrings(int _n) {
        n = _n;
        memset(dp, -1, sizeof(dp));
        return f(0, 0);
    }
};