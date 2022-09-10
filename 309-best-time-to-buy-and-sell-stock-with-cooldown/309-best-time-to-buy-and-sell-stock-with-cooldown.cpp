class Solution {
private:
    int f(vector<int> &prices, int i, bool buy, vector<vector<int>> &dp) {
        if(i >= prices.size()) return 0;
        
        if(dp[i][buy] != -1) return dp[i][buy];
        
        if(buy) {
            return dp[i][buy] = max(
                -prices[i] + f(prices, i+1, false, dp),
                f(prices, i+1, true, dp)
            );
        }
        
        return dp[i][buy] = max(
            prices[i] + f(prices, i+2, true, dp),
            f(prices, i+1, false, dp)
        );
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(prices, 0, true, dp);
    }
};