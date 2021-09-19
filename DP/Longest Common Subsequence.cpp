// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/longest-common-subsequence/
class Solution {
    public:
    int dp[1001][1001];
public:
    int longestCommonSubsequence(string text1, string text2) {
        for(int i=0;i<text1.length();i++){
            for( int j=0;j<text2.length();j++){
                dp[i][j]=0;
            }
        }
        int result = LCS(text1,text2,text1.length(),text2.length());
        return result;
    }
    int LCS(string t1, string t2, int l1, int l2){
        
        for(int i=0;i<l1+1;i++){
            for(int j=0;j<l2+1;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<l1+1;i++){
            for(int j=1;j<l2+1;j++){
                if(t1[i-1]==t2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        return dp[l1][l2];
    }
};