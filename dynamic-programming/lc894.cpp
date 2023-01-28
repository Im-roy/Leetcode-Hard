/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(dp.count(n))
            return dp[n];
        vector<TreeNode*> arr;
        if (n == 1) 
            arr.push_back(new TreeNode(0));
        else if(n%2 == 1) {
            for(int x=0; x<n; x++){
                int y = n-1-x;
                for(TreeNode *left: allPossibleFBT(x)) {
                    for(TreeNode *right: allPossibleFBT(y)) {
                        TreeNode *bns = new TreeNode(0);
                        bns->left = left;
                        bns->right = right;
                        arr.push_back(bns);
                    }
                }
            }
        }
        return arr;
    }
};