// URL: https://leetcode.com/problems/find-the-most-competitive-subsequence/
// Type: Monotonic Stack
// Name: Tanmaya Udupa
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        st.push(nums[0]);
        for (int i =1;i<nums.size();i++){
            if(nums[i]<st.top()){
                while( !st.empty() && ((nums.size()-i-1)+st.size() >= k) && nums[i]<st.top()){
                    st.pop();
                }
                st.push(nums[i]);
            }
            else{
                st.push(nums[i]);
            }
        }
        
        vector<int> result;
        result.assign(nums.size(),0);
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        vector<int> res;
        res.assign(k,0);
        for(int i=0;i<k;i++){
            res[i] = result[i];
        }
        return res;
    }
};