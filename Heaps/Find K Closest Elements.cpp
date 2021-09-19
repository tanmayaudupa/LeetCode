// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/find-k-closest-elements/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<arr.size();i++)
        {
            int diff = arr[i] - x ;
            if(diff<0){
                pq.push(make_pair(abs(diff),-1));
            }
            else{
                pq.push(make_pair(abs(diff),1));
            }
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> v ;
        for(int i=0;i<k;i++){
            int sum = 0;
            if(pq.top().second == 1){
             sum = pq.top().first + x;
            }
            else{
             sum = -(pq.top().first)+x;
            }
            v.push_back(sum);
            pq.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};