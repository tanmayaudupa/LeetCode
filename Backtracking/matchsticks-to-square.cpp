// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/matchsticks-to-square/
// Type: Backtracking
class Solution {
public:
    int n;
    vector<int> mat;
    bool dfs(int len, int a, int b, int c, int d,int s){
        if(len == n && a==b && b==c && c==d){
            return true;
        }
        else if(len == n){
            return false;
        }

        if (a + mat[len]<=s){
             if(dfs(len+1,a +mat[len],b,c,d,s)){
                 return true;
             }
        }
        if (b + mat[len]<=s){
             if(dfs(len+1,a,b+mat[len],c,d,s)){
                 return true;
             }
        }
        if (c + mat[len]<=s){
             if(dfs(len+1,a,b,c+mat[len],d,s)){
                 return true;
             }
        }
        if (d + mat[len]<=s){
             if(dfs(len+1,a,b,c,d+mat[len],s)){
                 return true;
             }
        }
        return false;


    }
    bool makesquare(vector<int>& matchsticks) {

        mat = matchsticks;
        sort(mat.rbegin(),mat.rend());
        n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        int mod = sum/4;
        if (sum%4 !=0){
            return false;
        }
        bool res = dfs(0,0,0,0,0,mod);
        return res;
    }
};