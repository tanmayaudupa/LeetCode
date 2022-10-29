// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii


class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> sk;
        int count=1;
        for(int i=0;i<s.length();i++){
            if(sk.empty()){
                sk.push(make_pair(s[i],1));
            }
            else if(sk.top().first != s[i]){
                sk.push(make_pair(s[i],1));
            }
            else{
                sk.push(make_pair(s[i],sk.top().second+1));
            }
            if(sk.top().second==k){
                int i=0;
                while(i<k){
                    sk.pop();
                    i++;
                }
            }
        }
        string result;
        while(!sk.empty()){
         result.push_back(sk.top().first);
         sk.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};