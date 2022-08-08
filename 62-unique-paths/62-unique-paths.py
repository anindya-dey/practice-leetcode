class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return self.solve(m, n, 0, 0, {})
        
    def solve(self, m: int, n: int, r: int, c: int, dp: List) -> int:
        if (r, c) in dp:
            return dp[(r, c)]
        
        if r == m - 1 and c == n - 1:
            return 1
        
        if r >= m or c >= n:
            return 0
        
        down = self.solve(m, n, r + 1, c, dp)
        right = self.solve(m, n, r, c + 1, dp)
        
        dp[(r, c)] = down + right
        return dp[(r, c)]