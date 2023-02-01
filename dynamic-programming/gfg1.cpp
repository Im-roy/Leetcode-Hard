// link: https://practice.geeksforgeeks.org/problems/844b4fdcd988ac5461324d62d43f7892749a113c/1

class Solution{   
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        long long dp[n][3];
        dp[0][0] = r[0], dp[0][1] = g[0], dp[0][2] = b[0];
        
        for(int i = 1; i<n ; i++){
            dp[i][0] = r[i] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = g[i] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = b[i] + min(dp[i-1][1], dp[i-1][0]);
        }
        return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};