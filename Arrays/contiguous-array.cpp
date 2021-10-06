// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/contiguous-array/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> umap;
        umap[0] = -1;
        int sum = 0;
        int maxl = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum-=1;
            }
            else{
                sum+=1;
            }
            if(umap.find(sum)==umap.end()){
                umap[sum] = i;
            }
            else{
               int tmp = i-umap[sum];
                if(tmp>maxl){
                    maxl = tmp;
                }
            }
        }
        return maxl;
    }
};