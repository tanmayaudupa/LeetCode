// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/reduce-array-size-to-the-half/description/
// Type: Heap (Max Heap)
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> map;
        for(auto s: arr){
            map[s]+=1;
        } 

        priority_queue<pair<int,int>> pq;
        for(auto m:map){
            pq.push(make_pair(m.second,m.first));
        }
        int result=0;
        int s= arr.size();
        while(pq.size()>0){
            if(s<=arr.size()/2){
                break;
            }

            pair p  = pq.top();
            pq.pop();
            s = s- p.first;
            result +=1;
        }
        return result;
    }
};