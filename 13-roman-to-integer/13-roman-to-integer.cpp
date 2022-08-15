class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
        int n = s.size();
        int ans = m[s[n-1]];
        
        for(int i = n-2; i >= 0; i--) {
            int prev = m[s[i+1]];
            int curr = m[s[i]];
            
            if(curr < prev) {
                ans -= curr;
            } else {
                ans += curr;
            }
        }
        
        return ans;
    }
};