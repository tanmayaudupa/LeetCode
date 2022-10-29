class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int i=0;
    int j= nums.size()-1;
    int result = 0;
    if(nums.size()==1){
        if(nums[0]==val){
            return 0;
        }
        else{
            return 1;
            }
    }
    while (i<j){
        if(nums[i]==val)
        {
            result ++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j--;
        }
        else
        {
            i++;
        }
    } 
    return nums.size() - result;
        
    }
};