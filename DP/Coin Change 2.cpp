// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1));
        for (int i=0;i<dp.size();i++)
        {
            for (int j=0;j<dp[i].size();j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else if(i==0 && j!=0){
                    dp[i][j]=0;
                }
                else if (i!=0 && j==0){
                    dp[i][j]=1;
                }
            }
        }
        for(int i=1;i<dp.size();i++){
            for (int j=1;j<dp[i].size();j++){
                if(coins[i-1]<=j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[dp.size()-1][dp[0].size()-1];
    }
};