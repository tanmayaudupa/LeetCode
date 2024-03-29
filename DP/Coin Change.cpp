// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1));
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                
                if(i==0){
                    dp[i][j]= INT_MAX-1;
                }
                if(j==0 && i!=0){
                    dp[i][j]=0;
                }
                    
            }
        }
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(coins[i-1]<=j){
                    dp[i][j]=min((1+dp[i][j-coins[i-1]]),dp[i-1][j]);
                }               
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }   
        }
        if(dp[dp.size()-1][dp[0].size()-1] == INT_MAX-1){
            return -1;
        }
        else{
        return dp[dp.size()-1][dp[0].size()-1];
        }
    }
                    
};