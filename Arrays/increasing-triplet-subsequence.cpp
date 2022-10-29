// Author: Tanmaya Udupa
// https://leetcode.com/problems/increasing-triplet-subsequence/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX;
        int mid = INT_MAX;
        for(auto i :nums){
            if(i<min){
                min = i;
            }
            else{
                if(i>min){
                    if(mid<i){
                        return true;
                    }
                    mid = i;
                }
            }
        }
        return false;
    }
};