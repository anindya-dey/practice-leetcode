class Solution {
private:
    int f(vector<int> &prices, int n, int i, int buy, int cap, vector<vector<vector<int>>> &dp) {
        if((i == n) || (cap == 0)) return 0;
        
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        
        int profit = 0;
        if(buy) {
            profit = max(
                -prices[i] + f(prices, n, i+1, 0, cap, dp),
                f(prices, n, i+1, 1, cap, dp)
            );
        } else {
            profit = max(
                prices[i] + f(prices, n, i+1, 1, cap - 1, dp),
                f(prices, n, i+1, 0, cap, dp)
            );
        }
        
        return dp[i][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(prices, n, 0, 1, 2, dp);
    }
};