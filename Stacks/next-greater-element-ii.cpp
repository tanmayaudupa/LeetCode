//Author: Tanmaya Udupa
//URL: https://leetcode.com/problems/next-greater-element-ii/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> result;
        result.assign(nums.size(),0);
        if(nums.size()==1){
            result[0] = -1;
            return result;
        }
        for(int i = nums.size()-2;i>=0;i--){
            s.push(nums[i]);
        }
        cout<<endl;
        int j = 0;
        int eFlag=0;
        for(int i=nums.size()-1;i>=0;i--){
            while(nums[i]>=s.top()){
                s.pop();
                if(s.empty()){
                    result[j] = -1;
                    s.push(nums[i]);
                    eFlag = 1;
                    break;
                }
            }
            if(eFlag==0){
                result[j] = s.top();
                s.push(nums[i]);
                j++;
            }
            else{
                j++;
            }
            eFlag = 0;
            
        }
        reverse(result.begin(),result.end());
        return result;
    }
};