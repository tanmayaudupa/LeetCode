// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/shifting-letters/description/
// Type: Arrays
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long long int> sum(shifts.size(),0) ;
        long long int total = 0;
        for(int i = shifts.size()-1;i>=0;i--){
            total = total + shifts[i];
            sum[i] = total;
        }
        string result = "";
        for(int i = 0;i<s.size();i++){
            s[i]='a'+(s[i]-'a'+sum[i])%26;
        }
        return s;
    }
};