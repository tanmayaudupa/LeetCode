// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int count=0;
        int len = INT_MIN;
        while(j<nums.size()){
            if(nums[j]==1){
                j++;
            }
            else{
                count +=1;
                if(count>1){
                    while(count>1){
                        len = max(len,(j-i-1));
                        if(nums[i]==0){
                            count-=1;
                            i++;
                        }
                        else{
                            i++;
                        }
                    }    
                }
                j++; 
            }
        }
        len = max(len,j-i-1);
        if(len == INT_MIN){
            return nums.size()-1;
        }       
        return len;
        
    }
};