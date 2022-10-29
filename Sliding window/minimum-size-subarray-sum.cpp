// Author: Tanmaya Udupa
// URL: minimum-size-subarray-sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int result = INT_MAX;
        while(j<nums.size()){
            sum += nums[j];
            if(sum<target){  
                j++;
            }
            else{
                while(sum >=target){
                    result = min(result,(j-i+1));  
                    sum = sum - nums[i];
                    i++;
                } 
                j++;
            }
        }
        if(result == INT_MAX){
            return 0;
        }
        return result;
    }
};