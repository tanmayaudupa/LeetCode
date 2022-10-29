// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    static bool comp(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[0] < vec2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> result;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
                end = max(end,intervals[i][1]);
            }
            else{
                vector<int> vect;
                vect.push_back(start);
                vect.push_back(end);
                result.push_back(vect);
                start = intervals[i][0];
                end = intervals[i][1];
            }
            
        }
        vector<int> vect;
        vect.push_back(start);
        vect.push_back(end);
        result.push_back(vect);
        
        return result;
    }
};