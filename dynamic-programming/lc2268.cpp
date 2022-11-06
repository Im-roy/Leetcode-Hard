class Solution {
public:

    map<int, vector<int>> mp;
    int n, dp[10005][7][7], mod = 1e9 + 7;

    int help(int i, int l, int sl){

        if(i == n)
            return 1;

        if(dp[i][l][sl] != -1)
            return dp[i][l][sl]%mod;

        int ans = 0;
        for(auto x: mp[l]){
            if(x != sl){
                ans += help(i+1, x, l);
                ans %= mod;
            }
        }
        return dp[i][l][sl] = ans;
    }

    int distinctSequences(int _n) {
        
        mp[0] = {1, 2, 3, 4, 5, 6};
        mp[1] = {2, 3, 4, 5, 6};
        mp[2] = {1, 3, 5};
        mp[3] = {1, 2, 4, 5};
        mp[4] = {1, 3, 5};
        mp[5] = {1, 2, 3, 4, 6};
        mp[6] = {1, 5};
        n = _n;
        memset(dp, -1, sizeof(dp));
        return help(0, 0, 0)%mod;
    }
};