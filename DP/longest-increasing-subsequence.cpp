// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int maxdp = 0;
        for(int i=1;i<nums.size();i++){
            maxdp = 0;
            int j = i-1;
            while(j>=0){
            if(nums[j]<nums[i]){
                    if(dp[j]>maxdp){
                            maxdp = dp[j];
                    }
                }
            j--;
            }
            dp[i] = dp[i] + maxdp;
        }
        int result=0;
        for(int i=0;i<dp.size();i++){
            if(dp[i]>result){
                result = dp[i];
            }
        }
        return result;
    }
};