// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> umap = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        int sum = umap[s[s.length()-1]];
        cout<< sum;
        for(int i=s.length()-2;i>=0;i--){
            if(umap[s[i]]>=umap[s[i+1]]){
                sum += umap[s[i]];
            }
            else{
                sum -= umap[s[i]];
            }
        }
        return sum;
    }
};