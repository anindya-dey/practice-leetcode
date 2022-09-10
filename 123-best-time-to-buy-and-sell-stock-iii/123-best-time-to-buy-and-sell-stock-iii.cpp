class Solution {
/*
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
    
    int g(vector<int> &prices, int n, int i, int txn, vector<vector<int>> &dp) {
        if(i == n || txn == 4) return 0;
        
        if(dp[i][txn] != -1) return dp[i][txn];
        
        int profit = 0;
        
        if((txn % 2) == 0) {
            profit = max(
                -prices[i] + g(prices, n, i+1, txn+1, dp),
                g(prices, n, i+1, txn, dp)
            );
        } else {
            profit = max(
                prices[i] + g(prices, n, i+1, txn+1, dp),
                g(prices, n, i+1, txn, dp)
            );
        }
        
        return dp[i][txn] = profit;
    }
*/
public:
    int maxProfit(vector<int>& prices) {
        /*
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(prices, n, 0, 1, 2, dp);
        */
        
        /*
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= 2; cap++) {
                    if(buy) {
                        curr[buy][cap] = max(
                            -prices[i] + after[0][cap],
                            after[1][cap]
                        );
                    } else {
                        curr[buy][cap] = max(
                            prices[i] + after[1][cap-1],
                            after[0][cap]
                        );
                    }
                }
            }
            after = curr;
        }
        
        return after[1][2];
        */
  
        
        /*
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return g(prices, n, 0, 0, dp);
        */
        
        /*
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int txn = 0; txn < 4; txn++) {
                if((txn % 2) == 0) {
                    dp[i][txn] = max(
                        -prices[i] + dp[i+1][txn+1],
                        dp[i+1][txn]
                    );
                } else {
                    dp[i][txn] = max(
                        prices[i] + dp[i+1][txn+1],
                        dp[i+1][txn]
                    );
                }
            }
        }
        
        return dp[0][0];
        */
        
        /*
        int n = prices.size();
        vector<int> ahead(5);
        vector<int> curr(5);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int txn = 0; txn < 4; txn++) {
                if((txn % 2) == 0) {
                    curr[txn] = max(
                        -prices[i] + ahead[txn+1],
                        ahead[txn]
                    );
                } else {
                    curr[txn] = max(
                        prices[i] + ahead[txn+1],
                        ahead[txn]
                    );
                }
            }
            ahead = curr;
        }
        
        return ahead[0];
        */
        
        int n = prices.size();
        vector<int> res(5);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int txn = 0; txn < 4; txn++) {
                if((txn % 2) == 0) {
                    res[txn] = max(
                        -prices[i] + res[txn+1],
                        res[txn]
                    );
                } else {
                    res[txn] = max(
                        prices[i] + res[txn+1],
                        res[txn]
                    );
                }
            }
        }
        
        return res[0];
    }
};