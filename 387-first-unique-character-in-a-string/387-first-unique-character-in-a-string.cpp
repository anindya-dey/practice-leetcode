class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> ch(26,0);
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            ch[s[i] - 'a']++;
        }
        
        for(int i = 0; i < n; i++) {
            if(ch[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
};