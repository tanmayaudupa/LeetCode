// URL: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Type: Stack
// Name: Tanmaya Udupa
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        
        for(int i = 0; i< s.length();i++){
            if (s[i] == '('){
                st.push('(');
            }
            else{
                if (!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
        }
        
        return st.size();
    }
};