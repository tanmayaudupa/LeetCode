// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length(),0);
        if(s.length()==1 && (s[0]-'0') == 0){
            return 0;
        }
        if(s[0]-'0' !=0){
            dp[0] = 1;
        }
        else{
            dp[0] = 0;
        }
        if(s.length()>=2){
            // cout<<"h1"<<s[0]-'0' <<s[1]-'0' <<endl;
            if((s[0]-'0')==2 && ((s[1]-'0')<=6 && (s[1]-'0')>0)){
                dp[1] = 2;
                cout<<"h2"<<endl;
            }
            else if((s[0] - '0') == 1 && ((s[1]-'0') <= 9 &&(s[1]-'0') > 0)){
                dp[1] = 2;
                cout<<"h3"<<endl;
            }
            else if(((s[1]-'0') == 0|| (s[1]-'0'>=7)) && ((s[0]-'0')==2 || (s[0]-'0')==1))              {
                cout<<"h4"<<endl;
                dp[1]= 1;
            }
            else if(((s[1]-'0') == 0 && ((s[0]-'0')>=3))){
                 dp[1]=0;
            } 
            else if(s[0]-'0' == 0){
                dp[1]=0;
            }
            else{
                dp[1]= 1;
            }
        }
        for(int i=2;i<dp.size();i++){
            if(((s[i]-'0')<=6 && (s[i] - '0')>0)&& (s[i-1]-'0')==2){
                dp[i] = dp[i-1] + dp[i-2];
            }
            else if (((s[i] - '0')<=9 && (s[i] - '0')>0) && (s[i-1]-'0') == 1){
                dp[i] = dp[i-1] + dp[i-2];
            }
            else if((s[i]-'0') == 0 && ((s[i-1]-'0')==2 || (s[i-1]-'0')==1)){
                dp[i] = dp[i-2];
            }
            else if((s[i]-'0'==0 && s[i-1]-'0'==0) ||(s[i]-'0'==0 && s[i-1]-'0'>=3)){
                return 0;
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<< " ";
        }
        return dp[dp.size()-1];
    }
    
};