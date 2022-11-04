// Author: Tanmaya Udupa
// https://leetcode.com/problems/furthest-building-you-can-reach/
// Type: Heap (Max Heap)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        
        priority_queue<int> pq;
        
        for(int i=0;i<heights.size()-1;i++){
            
            int diff = heights[i+1]-heights[i];
            
            
            if(diff>0){
                bricks -= diff;
                pq.push(diff);
                if(bricks<0){
                    ladders-=1;
                    bricks+=pq.top();
                    pq.pop();
                    
                }
                
                if(ladders<0){
                    return i;
                }
            }
            else{
                continue;
            }
        }
        
        return heights.size()-1;
    }
};