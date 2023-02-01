class Solution {
public:
    vector<string> ans;
    int n;
    
    void fun(int i, int val, string str) {
        if(i == 2*n) {
            if(val == 0){
                ans.push_back(str);
            }
            return;
        }
        
        if(val == 0){
            fun(i+1, val+1, str+"(");
        }
        else {
            fun(i+1, val+1, str+ "(");
            fun(i+1, val - 1, str + ")");
        }
    }
    
    vector<string> generateParenthesis(int _n) {
        n = _n;
        fun(1, 1, "(");
        return ans;
    }
};