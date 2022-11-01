class Solution {
public:
    
    int t[4*2505];
    
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

    
    int lengthOfLIS(vector<int>& nums) {
        
        memset(t, 0, sizeof(t));
        int ans = 1, cnt = 1;
        set<int> st; map<int, int> mp;
        for(auto x: nums)
            st.insert(x);
        
        for(auto x: st){
            mp[x] = cnt;
            cnt += 1;
        }

        for(int i=0; i<nums.size(); i++){
            if(i == 0){
                update(1, 0, 2505, mp[nums[i]], 1);
                continue;
            }
            int temp = sum(1, 0, 2505, 0, mp[nums[i]] - 1);
            ans = max(ans, 1 + temp);
            update(1, 0, 2505, mp[nums[i]], temp + 1);
        }
        return ans;
    }
};