// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/maximum-width-ramp/
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<pair<int,int>> s;
        s.push(make_pair(nums[0],0));
        for(int i=1;i<nums.size();i++){
            if(nums[i]<s.top().first){
                s.push(make_pair(nums[i],i));
            }
        }
        int j = nums.size() -1;
        int result=0;
        while(!s.empty() && j>=0){
            if(nums[j]>=s.top().first){
                result = max(result,(j-s.top().second));
                s.pop();
            }
            else{
                j--;
            }
        }
        return result;
    }
};