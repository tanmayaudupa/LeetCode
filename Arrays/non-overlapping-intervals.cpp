// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/non-overlapping-intervals/
class Solution {
public:
    static bool comp(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[1] < vec2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        sort(intervals.begin(), intervals.end(), comp);
        int res=1;
        int finish = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=finish){
                res+=1;
                finish = intervals[i][1];
            }
        }
        cout<<res;
        return intervals.size()-res;
    }
};