// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/shortest-common-supersequence/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = LCS(str1,str2);
        cout << lcs<<endl;
        int s1,s2,com=0;
        int longer = max(str1.length(),str2.length());
        return lcs;    
    }
    
    string LCS(string s1,string s2){
        
        vector<vector<int>> dp;
        dp.assign(s1.size()+1,vector<int>(s2.size()+1));
        for (int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else if (s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string result;
        int i=dp.size()-1;
        int j = dp[0].size()-1;
        while(i!=0 and j!=0){
            if(s1[i-1]==s2[j-1]){
                result.push_back(s1[i-1]);
                i = i-1;
                j = j-1;
            }
            else {
                if(dp[i-1][j]>dp[i][j-1]){
                     result.push_back(s1[i-1]);
                    i = i-1;
    
                }
                else{
                    result.push_back(s2[j-1]);
                    j=j-1;
                }
            }
        }
        while(i>0){
            result.push_back(s1[i-1]);
            i--;
        }
        while(j>0){
            result.push_back(s2[j-1]);
            j--;
        }
        reverse(result.begin(), result.end());
        return result ;
        
        
    }
};