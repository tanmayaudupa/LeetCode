// URL: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Type: left,right arrays
// Name: Tanmaya Udupa

class Solution {
public:
    int minimumDeletions(string s) {
        vector<pair<int,int>> left;
        vector<pair<int,int>> right;
        int la=0,lb = 0;
        int ra=0,rb = 0;
        for(int i = 0 ;i < s.length();i++ ){
            if (s[i]=='a'){
                la+=1;
            }
            else{
                lb+=1;
            }
            left.push_back(make_pair(la,lb));
        }
        
        for(int i = s.length()-1;i>=0;i--){
            if (s[i]=='a'){
                ra+=1;
            }
            else{
                rb+=1;
            }
            right.push_back(make_pair(ra,rb));
        }
        reverse(right.begin(),right.end());
        int result = INT_MAX;
        int change = 0;
        for(int i=0;i<s.length();i++){
            
            change = left[i].second + right[i].first;
            result = min(result,change);
        }
        
        return result-1;
    }
};