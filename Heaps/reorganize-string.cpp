// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/reorganize-string/
// Type: Heap (Max Heap)
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> map;
        for(auto c : s){
            map[c]+=1;
        }
        priority_queue<pair<int,char>> pq;
        
        
        for(auto e: map){
            pq.push(make_pair(e.second,e.first));
        }
        string result = "";
        while(pq.size() > 1){
            
            pair p1 = pq.top();
            pq.pop();
            pair p2 = pq.top();
            pq.pop();
            
            if(p1.first > (s.size()+1)/2){
                return "";
            }
            
            result += p1.second;
            result +=p2.second;
            
            int p1r = p1.first - 1;
            int p2r = p2.first - 1;
            
            if(p1r>0){
                pq.push(make_pair(p1r,p1.second));
                
            }
            
            if(p2r>0){
                pq.push(make_pair(p2r,p2.second));    
            }
            
        }
        
        if (pq.size()>0){
            if (pq.top().first<2){
                result += pq.top().second;    
            }
            
        }
        
        return result;
    }
};