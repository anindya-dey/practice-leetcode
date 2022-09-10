class Solution {
private:
    int f(vector<int>& prices, int n, int i, bool buy, int k, vector<vector<vector<int>>>& dp) {
        if(i == n || k == 0) return 0;
        
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        
        int profit = 0;
        
        if(buy) {
            profit = max(
                -prices[i] + f(prices, n, i+1, false, k, dp),
                f(prices, n, i+1, true, k, dp)
            );
        } else {
            profit = max(
                prices[i] + f(prices, n, i+1, true, k-1, dp),
                f(prices, n, i+1, false, k, dp)
            );
        }
        
        return dp[i][buy][k] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector< vector< vector<int> > > dp(n, vector< vector<int> >(2, vector<int>(k+1, -1)));
        return f(prices, n, 0, true, k, dp);
    }
};