// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/longest-palindromic-subsequence/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp;
        dp.assign(s.length()+1,vector<int>(s.length()+1,0));
        for(int i=1;i<dp.size();i++)
            for(int j=1;j<dp[0].size();j++){  
                if(s[i-1]==s[s.length() - j]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        
        return dp[dp.size()-1][dp[0].size()-1];
    }
    
};