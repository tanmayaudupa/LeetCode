// Author: Tanmaya Udupa
// https://leetcode.com/problems/k-diff-pairs-in-an-array/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int count=0;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]] += 1;
        }
        if (k==0){
            for(auto j:umap){
                if(j.second>1){
                    count++;
                }
            }
            return count;
        }
        for(auto i:umap){
            int second = i.first-k;
            if(umap.find(second)!=umap.end() ){
                count+=1;
            }
        }
        return count;
    }
};