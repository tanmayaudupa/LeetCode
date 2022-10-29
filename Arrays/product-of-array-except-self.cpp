// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        int mull = 1;
        int mulr = 1;
        for(int i=0;i<nums.size();i++){
            left[i] = mull;
            mull = mull*nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            right[i] = mulr;
            mulr = mulr*nums[i];
        }
        vector<int> result(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            result[i] = left[i]*right[i];
        }
        return result;
    }
};