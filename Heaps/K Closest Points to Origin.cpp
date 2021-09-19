// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>> maxh ;
        for(int i=0;i<points.size();i++){
            double dist = sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            maxh.push(make_pair(dist,make_pair(points[i][0],points[i][1])));
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<vector<int>> result;
        for(int i=0;i<k;i++){
            vector<int> temp;
            pair ptmp = maxh.top().second;
            temp.push_back(ptmp.first);
            temp.push_back(ptmp.second);
            maxh.pop();
            result.push_back(temp);
        }
        return result;
    }
};