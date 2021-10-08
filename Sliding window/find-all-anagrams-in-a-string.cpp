// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0;
        int j=0;
        int hash_count=0;
        unordered_map<char,int> umap;
        vector<int> result;
        for(auto &ch:p){
            umap[ch] = 0;
        }
        for(auto &ch:p){
            umap[ch] += 1;
        }
        hash_count = umap.size();
        while(j<s.size()){
            if((j-i+1)<p.size()){
                if(umap.find(s[j])!=umap.end()){
                    umap[s[j]] -= 1;
                    if(umap[s[j]]==0){
                        hash_count-=1;
                    }
                }
                j++;
            }
            else if((j-i+1)==p.size()){
                if(umap.find(s[j])!=umap.end()){
                    umap[s[j]] -= 1;
                    if(umap[s[j]]==0){
                        hash_count-=1;
                    }
                    
                }
                if(hash_count==0){
                    result.push_back(i);
                }
                if(umap.find(s[i])!=umap.end()){
                    if(umap[s[i]]==0){
                        hash_count+=1;
                    }
                    umap[s[i]] += 1;
                }
                i++;
                j++;  
            }
        }
        return result;
    }
};