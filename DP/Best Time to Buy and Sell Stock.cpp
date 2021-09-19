// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(),0);
        int price = 100000;
        int j = 0;
        int flag=1;
        for(int i=0;i<prices.size();i++){
            if(prices[i]< price){
                j++;
                price = prices[i];
                dp[i] = 0-price;
            }
            else{
                dp[i] = prices[i]-price;
                flag = 0;
            }
        }
        if(j==prices.size()-1 && flag !=0){
            return 0;
        }
        else{
            int max = 0;
            for(int i=0;i<dp.size();i++){
                if(dp[i]>max){
                    max = dp[i];
                }
            }
            return max;
        }
        
    }
};