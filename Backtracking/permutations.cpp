// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/permutations/
// Type: Backtracking
class Solution {
public:

    vector<vector<int>> result;
    vector<int> tnums;
    set<int> s;
    void dfs(int k, int n, vector<int>temp){

        if(k==n){
            result.push_back(temp);
            return;
        }

        for(int i=0;i<tnums.size();i++){
            if(s.find(tnums[i])==s.end()){
                s.insert(tnums[i]);
                temp.push_back(tnums[i]);
                dfs(k+1,n,temp);
                temp.pop_back();
                s.erase(tnums[i]);
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        tnums=nums;
        dfs(0,nums.size(),{});
        return result;

    }
};