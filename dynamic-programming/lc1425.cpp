class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        multiset<int> ms;
        int n = nums.size(), ans = INT_MIN;
        vector<int> dp(n, 0);
        
        for(int i=0; i<n; i++){
            if(i == 0){
                dp[i] = nums[i];
                ms.insert(nums[i]);
                ans = max(ans, dp[i]);
                continue;
            }

            auto it = *ms.rbegin();
            dp[i] = nums[i] + (it > 0 ? it : 0);
            ms.insert(dp[i]);
            if(i-k >= 0){
                ms.erase(ms.find(dp[i-k]));
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    };
};