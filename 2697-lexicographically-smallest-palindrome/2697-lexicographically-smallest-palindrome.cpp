class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        string res = s;
        
        while(l < r) {
            if(s[l] > s[r]) {
                res[l] = s[r];
            } else {
                res[r] = s[l];
            }
            
            l++;
            r--;
        }
        
        return res;
    }
};