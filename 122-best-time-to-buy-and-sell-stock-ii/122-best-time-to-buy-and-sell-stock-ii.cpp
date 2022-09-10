class Solution {
private:
    int recurse(vector<int> &prices, int n, int idx, bool buy, vector<vector<int>> &dp) {
        if(idx == n) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        int profit = 0;
        
        if(buy) {
            int buying = -prices[idx] + recurse(prices, n, idx+1, false, dp);
            int notBuying = recurse(prices, n, idx+1, true, dp);
            profit = max(buying, notBuying);
        } else {
            int selling = prices[idx] + recurse(prices, n, idx+1, true, dp);
            int notSelling = recurse(prices, n, idx+1, false, dp);
            profit = max(selling, notSelling);
        }
        
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return recurse(prices, prices.size(), 0, true, dp);
    }
};