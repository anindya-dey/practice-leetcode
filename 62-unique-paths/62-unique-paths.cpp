class Solution {
public:
    int uniquePaths(int m, int n) {
        map<pair<int, int>, int> dp;
        return solve(m - 1, n - 1, 0, 0, dp);
    }
    
    int solve(int m, int n, int r, int c, map<pair<int, int>, int> &dp) {
        if(dp.find({r, c}) != dp.end()) return dp[{r, c}];
        
        if((r == m) && (c == n)) return 1;
        
        if((r > m) || (c > n)) return 0;
        
        dp[{r, c}] = solve(m, n, r + 1, c, dp) + solve(m, n, r, c + 1, dp);
        
        return dp[{r, c}];
    }
};