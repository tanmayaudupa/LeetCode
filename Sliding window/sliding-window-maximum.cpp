// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int global_max=nums[0];
        multiset<int> s;
        vector<int> result;
        while(j<nums.size()){
            if((j-i+1)<k){
                s.insert(nums[j]);
                auto it = s.end();
                it--;
                global_max = nums[j];
                j++;
            } 
            else if((j-i+1)==k){
                s.insert(nums[j]);
                auto it = s.end();
                it--;
                global_max = *(it);
                result.push_back(global_max);
                s.erase(s.find(nums[i]));
                i++;
                j++;
            }
        }
        return result;
    }
};