class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 or j == 0)
                    continue;
                if(matrix[i][j] == 1)
                    matrix[i][j] = min({matrix[i][j-1], matrix[i-1][j-1], matrix[i-1][j]}) + 1;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                ans += matrix[i][j];
        }
        return ans;
    }
};

/*

    [0,1,2,3],
    [1,2,1,1],
    [0,1,1,1]
    
    []

*/