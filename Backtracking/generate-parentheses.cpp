// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/generate-parentheses/
// Type: Backtracking
class Solution {
public:
    vector<string> result;
    string temp = "(";
    int gn;
    void dfs(int k, string t, int o, int c){
        if (k==2*gn){
            result.push_back(t);
            return;
        }
        if (o<gn){
            dfs(k+1,t+"(",o+1,c);
        }

        if (c<gn){
            if(c < o){
                dfs(k+1,t+")",o,c+1);
            }
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        gn = n;
        dfs(1,temp,1,0);
        return result;

    }
};