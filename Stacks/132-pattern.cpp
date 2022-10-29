
// Type : Monotonic stack 
// Name: Tanmaya Udupa

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
     
        stack <int> st;
        st.push(nums[nums.size()-1]);
        
        vector<int> min;
        min.assign(nums.size(),-1);
        int m = nums[0];
        min[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            if (nums[i]<m){
                min[i] = nums[i];
                m = nums[i];
            }
            else{
                min[i] = m;
            }
        }
        
        for(int i = nums.size()-2;i>=0;i--){
            if (nums[i] <= st.top()){
                st.push(nums[i]);
            }
            else{
               while(!st.empty()){
                   if (st.top()< nums[i] && st.top() > min[i]){
                       return true;
                   }
                   else if (st.top() > nums[i]){
                       st.push(nums[i]);
                       break;
                   }
                   else{
                       st.pop();
                   }
               } 
                if (st.empty()){
                    st.push(nums[i]);
                }
            }
        }
        return false;
    }
};