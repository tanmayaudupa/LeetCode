// Author: Tanmaya Udupa
// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        if(nums.size()==0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        vector<int> result;
        for(auto it=s.begin();it!=s.end();it++){
            result.push_back(*it);
        }
        int count=1;
        int mc=1;
        for(int i=1;i<result.size();i++){
            if(result[i]-result[i-1]==1){
                count++;
            }
            else{
                count=1;
            }
            mc = max(mc,count);
        }
        return mc;
    }
    
};