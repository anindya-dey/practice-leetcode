class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = 0, notBuy = 0;
        
        for(int i = n-1; i >= 0; i--) {
            buy = max(-prices[i] + notBuy, buy);
            notBuy = max(prices[i] - fee + buy, notBuy);
        }

        return buy;
    }
};