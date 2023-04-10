class Solution {
public:
    
    bool ok(vector<int> arr, long long num, int k){
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= num){
                cnt += 1;
                i += 1;
            }
        }
        return cnt >= k;
    }
    
    int minCapability(vector<int>& nums, int k) {
        long long l = 1, h = 1e14, ans = -1; 
        while(l <= h){
            long long mid = l + (h-l)/2;
            if(ok(nums, mid, k)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
