// Author: Tanmaya Udupa
// https://leetcode.com/problems/single-number-ii/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       unordered_map<int,int> umap;
        for(auto i:nums){
            umap[i]= 0;
        }
        for(auto i : nums){
            umap[i]+=1;
        }
        int result;
        for(auto u:umap){
            if(u.second == 1){
                result = u.first;
                break;
            }
        }
        return result;
    }
};