
// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> hash(1001,0);
        for(int i=0;i<arr.size();i++){
            hash[arr[i]] += 1;
        }
        for(int i=0;i<target.size();i++){
            if (hash[target[i]] !=0){
                hash[target[i]] -=1;
            } 
            else{
                return false;
            }
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]!=0){
                return false;
            }
        }
        return true;
    }
};