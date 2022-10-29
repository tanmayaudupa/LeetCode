// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> umap;
        unordered_map<string,int> tu;
        for(auto i :s){
            umap[i] = 0;
        }
        for(auto i :s){
            umap[i] += 1;
        }
        for(auto i :t){
            if(umap.find(i)!=umap.end()){
                if(umap[i]!=0){
                    umap[i]-=1;
                }
            }
        }
        int count=0;
        for(auto i :umap){
            count += i.second;
        }
        return count;
    }
};