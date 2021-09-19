// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/target-sum/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        int count = 0;
        for (auto i = nums.begin();i<nums.end();i++){
            sum = sum + *i;
            if( *i == 0){
                count +=1;
            }
        }
        sum = (target + sum);
        if (sum %2 == 0){
            sum = sum/2;
        }
        else {
            return 0;
        }
        if (sum <0){
            return 0;
        }
        int result =subsetsum(nums,sum,count);
        return result;
    }
    int subsetsum(vector<int>& arr, int sum, int count){
        vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1));
        for (int i = 0;i<dp.size();i++){
            for (int j = 0;j<dp[i].size();j++){
                if ( i==0 && j==0){
                    dp[i][j]=1;
                }
                if (j == 0 && i != 0){
                    dp[i][j]=1;
                }
                if( i==0 && j!=0){
                    dp[i][j]=0;
                }
            }
        }
        for (int i=1;i<dp.size();i++){
            for (int j = 1;j<dp[i].size();j++){
                if (arr[i-1]==0){
                    dp[i][j]=dp[i-1][j];
                }
                else if (arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return pow(2,count)*dp[dp.size()-1][dp[0].size()-1];
    }
};