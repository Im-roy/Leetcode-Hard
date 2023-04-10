// Problem-URL: https://practice.geeksforgeeks.org/problems/63c232252d445a377e01cd91adfd7d1060580038/1
class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        vector<pair<int, int>> vp;
        for(auto x: lines){
            vp.push_back({x[0], 1});
            vp.push_back({x[1], 2});
        }
        
        sort(vp.begin(), vp.end());
        int cnt = 0, mx = 0;
        for(auto x: vp){
            if(x.second == 1){
                cnt += 1;
            } else {
                cnt -= 1;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};