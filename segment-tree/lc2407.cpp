class Solution {
public:
    
    int t[4*100005];
    vector<int> arr;
    void build(int tl, int th, int v){
        if(tl == th){
            t[v] = arr[tl];
            return;
        }
        int tm = tl + (th - tl)/2;
        build(tl, tm, 2*v);
        build(tm+1, th, 2*v+1);
        t[v] = max(t[2*v], t[2*v + 1]);
    }
    
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return max(sum(v*2, tl, tm, l, min(r, tm))
               , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    int lengthOfLIS(vector<int>& nums, int k) {
        
        memset(t, 0, sizeof(t));
        arr = nums;
        int ans = 1;
        for(int i=0; i<nums.size(); i++){
            if(i == 0){
                update(1, 0, 100005, nums[i], 1);
                continue;
            }
            int temp = sum(1, 0, 100005, max(0, nums[i]-k), nums[i]-1);
            ans = max(ans, 1 + temp);
            update(1, 0, 100005, nums[i], temp + 1);
        }
        return ans;
    }
};