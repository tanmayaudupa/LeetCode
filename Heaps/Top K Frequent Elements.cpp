// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        unordered_map<int, int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        for (auto itr = umap.begin(); itr != umap.end(); itr++)
        {
            minh.push(make_pair(itr->second,itr->first));
            if(minh.size()>k){
                minh.pop();
            }
        }
        vector<int> result;
        result.assign(k,0);
        for(int i=0;i<k;i++){
            result[i] = (minh.top().second);
            minh.pop();
        }
        return result;
    }
};