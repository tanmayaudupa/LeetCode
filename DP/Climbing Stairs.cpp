// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        cout<<dp.size();
        for(int i=0;i<n+1;i++){
            cout<<dp[i]<<" ";
        }
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        else if(n==2){
return 2;}
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<n+1;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        // cout<<"hell";
        return dp[n];
    }
};