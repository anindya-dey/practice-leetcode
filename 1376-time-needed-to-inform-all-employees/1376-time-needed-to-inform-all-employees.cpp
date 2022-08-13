class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1) return informTime[0];
        
        int mint = INT_MIN;
        unordered_map<int, int> tracker;
        
        for(int i = 0; i < n; i++) {
            int j = manager[i], time = 0;
            
            if(tracker[j]) continue;
            
            while(j != -1) {
                time += informTime[j];
                j = manager[j];
            }
            mint = max(mint, time);
            
            tracker[j] = mint;
        }
        
        return mint;
    }
};