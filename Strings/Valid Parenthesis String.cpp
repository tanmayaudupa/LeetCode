// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/valid-parenthesis-string/
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> bs;
        stack<char> bst;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='(') bs.push(i);
            
            else if(s[i]=='*') bst.push(i);
            
            else{
                
                if(!bs.empty()) bs.pop();
                
                else {
                    if(!bst.empty()) bst.pop();
                    
                    else return false;
                }
                
            }
        }
         while(!bs.empty()){
            
            if(bst.empty()) return false;
            
            else{
                
                if(bs.top() < bst.top()){
                    bs.pop();
                    bst.pop();
                }
                else{
                    return false;
                }
            }
         }
        
        return true; 
        
    }
};