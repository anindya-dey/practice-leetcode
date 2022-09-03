class Solution {
private:
    void dfs(int n, int k, int num, vector<int> &res) {
        if(n == 0) {
            res.push_back(num);
            return;
        }
        
        int lastDigit = num % 10;
        
        if((lastDigit + k) < 10) {
            dfs(n - 1, k, num * 10 + (lastDigit + k), res);
        }
        
        if((lastDigit - k) >= 0 && k != 0) {
            dfs(n - 1, k, num * 10 + (lastDigit - k), res);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        
        for(int d = 1; d < 10; d++) {
            dfs(n - 1, k, d, res);
        }
        
        return res;
    }
};