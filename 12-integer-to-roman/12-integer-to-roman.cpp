class Solution {
public:
    string intToRoman(int num) {
        pair<int, string> m[13] = {};
        m[0] = {1000, "M"};
        m[1] = {900, "CM"};
        m[2] = {500, "D"};
        m[3] = {400, "CD"};
        m[4] = {100, "C"};
        m[5] = {90, "XC"};
        m[6] = {50, "L"};
        m[7] = {40, "XL"};
        m[8] = {10, "X"};
        m[9] = {9, "IX"};
        m[10] = {5, "V"};
        m[11] = {4, "IV"};
        m[12] = {1, "I"};
        
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