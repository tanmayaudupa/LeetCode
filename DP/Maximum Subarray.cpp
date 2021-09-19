// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        
        dp.assign(nums.size(),0);
        dp[0] = nums[0] ;
        for(int i=1;i<nums.size();i++){
           dp[i]= max(nums[i],nums[i]+dp[i-1]);
        }
        int max=dp[0];
        for(int i=0;i<dp.size();i++){
            if(dp[i]>max){
                max=dp[i];
            }
        }
        return max;
    
    }
};