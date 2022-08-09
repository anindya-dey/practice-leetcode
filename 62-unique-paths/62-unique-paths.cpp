class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
    
    /*
    int solve(int m, int n, int r, int c, map<pair<int, int>, int> &dp) {
        if(dp.find({r, c}) != dp.end()) return dp[{r, c}];
        
        if((r == m) && (c == n)) return 1;
        
        if((r > m) || (c > n)) return 0;
        
        dp[{r, c}] = solve(m, n, r + 1, c, dp) + solve(m, n, r, c + 1, dp);
        
        return dp[{r, c}];
    }
    */
};