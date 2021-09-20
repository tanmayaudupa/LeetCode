//Author: Tanmaya Udupa
//URL: https://leetcode.com/problems/online-stock-span/
class StockSpanner {
public:
    stack<pair<int,int>> s;
    int tmp=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        if(s.empty()){
            s.push(make_pair(price,count));
            return count;
        }
        while(!s.empty() && price >= s.top().first){
            if(s.empty()){
                break;
            }
            
            count = count + s.top().second;
            s.pop();
            
        }
        s.push(make_pair(price,count));
        return s.top().second;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */