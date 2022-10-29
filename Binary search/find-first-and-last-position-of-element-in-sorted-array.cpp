// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int j = nums.size()-1;
        int first=-1 ;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(nums[mid]==target){
                first = mid;
                j = mid -1;
            }
            else if( nums[mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        i=0;
        j = nums.size()-1;
        int last =-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(nums[mid]==target){
                last = mid;
                i = mid +1;
            }
            else if( nums[mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        vector<int> result;
        result.push_back(first);
        result.push_back(last);
        return result;
    }
};