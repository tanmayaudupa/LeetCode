// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        vector<vector<string>> result;
        for(int i=0;i<strs.size();i++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            umap[tmp].push_back(strs[i]);
        }
        for(auto itr=umap.begin();itr!=umap.end();itr++){
            result.push_back(itr->second);
        }
        
        return result;
    }
};