// Author: Tanmaya Udupa
// https://leetcode.com/problems/task-scheduler/
// Type: Heap (Max Heap)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> map;
        
        for(auto s: tasks){
            map[s]+=1;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto e : map){
            pq.push(make_pair(e.second,e.first));
        }
        int result = 0;
        while(pq.size() > 0){
            int k = n;
            vector<pair<int,char>> temp;
            while(k >= 0){
                if(pq.size()==0){
                    result++;
                }
                else{
                    pair p = pq.top();
                    pq.pop();

                    if(p.first > 0){
                        result+=1;
                        p.first -=1;
                    }

                    if(p.first>0){
                        temp.push_back(p);
                    }
                }
                k-=1;
                if(temp.size()==0){
                    break;
                }
            }
            
            for(int i = 0;i<temp.size();i++){
                pq.push(temp[i]);
            }
            
            temp.clear();
            
            
        }
        
        return result;
    }
};