// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/maximal-square/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        int m = matrix.size()+1;
        int n = matrix[0].size()+1;
        int result =0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = 1+ min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                    if(dp[i][j] > result){
                        result = dp[i][j];
                    }
                }
            }
        }
        return result*result;
    }
};