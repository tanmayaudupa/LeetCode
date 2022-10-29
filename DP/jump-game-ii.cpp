// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),100000);
        int j=0;
        dp[0] = 0;
        for(int i=1;i<nums.size();i++){
          while(j!=i){
            if((i-j) <= nums[j]){
              dp[i] = min(dp[i],1+dp[j]);
            }
            j++;
          }
        j=0;
        }
        return dp[nums.size()-1];
    }
};