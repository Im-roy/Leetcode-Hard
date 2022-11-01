class Solution {
public:
    
    int t[4*100005];
    
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return (sum(v*2, tl, tm, l, min(r, tm))
               + sum(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] += new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = (t[v*2] + t[v*2+1]);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        memset(t, 0, sizeof(t));
        
        vector<int> res;
        int n = nums.size();
        set<int> st;
        int cnt = 0;
        for(auto x: nums){
            st.insert(x);
        }
        map<int, int> mp;
        for(auto x: st){
            mp[x] = cnt;
            cnt += 1;
        }
        for(int i=n-1; i>=0; i--){
            if(i == n-1){
                update(1, 0, n, mp[nums[i]], 1);
                res.push_back(0);
                continue;
            }
            int temp = sum(1, 0, n, 0, mp[nums[i]] - 1);
            res.push_back(temp);
            update(1, 0, n, mp[nums[i]], 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
