// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/partition-labels/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> umap;
        vector<int> result;
        int last=0;
        for(int i=0;i<s.length();i++){
            // cout<<i<<endl;
            umap[s[i]]=i;
        }
        int j=0;
        int leng =0;
        for(int i=0;i<s.length();i++){
            int tmp = umap[s[i]];
            if(tmp>last){
                last = tmp;
            }
            leng+=1;
            if(i==last){
                result.push_back(leng);
                leng = 0;
            }
        }
        return result;
    }
};