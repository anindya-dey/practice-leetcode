class Solution {
private:
    int m(char c) {
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int curr = m(s[i]);
            if(((i + 1) < n) && (curr < m(s[i+1]))) {
                ans -= curr;
            } else {
                ans += curr;
            }
        }
        
        return ans;
    }
};