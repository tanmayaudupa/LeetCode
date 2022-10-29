// Author: Tanmaya Udupa
// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,pair<int,int>> umap;
        for (int i=0;i<nums.size();i++){
            umap[nums[i]]=make_pair(0,0);
        }
        for (int i=0;i<nums.size();i++){
            umap[nums[i]].second +=1;
            umap[nums[i]].first = i; 
        }
        int x,y;
        for(int i=0;i<nums.size();i++){
            int diff = target -nums[i];
            cout<<diff;
            if(umap.find(diff)!=umap.end()){
                if(umap[diff].second>1 && diff==nums[i]){
                    x = i;
                    y = umap[diff].first;
                    break;
                }
                else if(diff!= nums[i]){
                    x = i;
                    y= umap[diff].first;
                    break;
                }
                
            }
        }
        vector<int> result;
        result.push_back(x);
        result.push_back(y);
        return result;
    }
};