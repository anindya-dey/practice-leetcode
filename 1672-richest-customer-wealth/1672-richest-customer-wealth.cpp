class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        
        for(vector<int> customer : accounts) {
            int wealth = 0;
            for(int bank : customer) {
                wealth += bank;
            }
            
            maxWealth = max(maxWealth, wealth);
        }
        
        return maxWealth;
    }
};