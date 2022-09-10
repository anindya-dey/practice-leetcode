class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy = 0, aheadNotBuy = 0;
        
        for(int i = n-1; i >= 0; i--) {
            aheadBuy = max(
                -prices[i] + aheadNotBuy,
                aheadBuy
            );

            aheadNotBuy = max(
                prices[i] - fee + aheadBuy,
                aheadNotBuy
            );
        }
        
        return aheadBuy;
    }
};