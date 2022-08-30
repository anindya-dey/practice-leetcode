class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        int n = accounts.size();
        int m = accounts[0].size();
        
        for(int i = 0; i < n; i++) {
            int wealth = 0;
            for(int j = 0; j < m; j++) {
                wealth += accounts[i][j];
            }
            
            if(wealth > maxWealth) {
                maxWealth = wealth;
            }
        }
        
        return maxWealth;
    }
};