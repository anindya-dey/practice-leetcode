class Solution {
public:
    string intToRoman(int num) {
        pair<int, string> m[13] = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        
        string ans = "";
        
        for(auto p : m) {
            /*
            int count = num / p.first;
            
            while(count--) {
                ans += p.second;
            }
            
            num %= p.first;
            
            if(num == 0) break;
            */
            while(num >= p.first) {
                num -= p.first;
                ans += p.second;
            }
        }
        
        
        return ans;
    }
};