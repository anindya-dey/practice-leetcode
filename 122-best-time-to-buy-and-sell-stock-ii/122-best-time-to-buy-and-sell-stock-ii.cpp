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
        /*
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return recurse(prices, prices.size(), 0, true, dp);
        */
        
        int n = prices.size();
        int profit = INT_MIN;
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy) {
                    profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                } else {
                    profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        
        return dp[0][1];
    }
};