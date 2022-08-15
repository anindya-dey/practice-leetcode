class Solution {
public:
    int romanToInt(string s) {
        int m[24] = {};
        m['I'-'A'] = 1;
        m['V'-'A'] = 5;
        m['X'-'A'] = 10;
        m['L'-'A'] = 50;
        m['C'-'A'] = 100;
        m['D'-'A'] = 500;
        m['M'-'A'] = 1000;
        
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int curr = s[i] - 'A';
            if(((i + 1) < n) && (m[curr] < m[s[i+1]-'A'])) {
                ans -= m[curr];
            } else {
                ans += m[curr];
            }
        }
        
        return ans;
    }
};