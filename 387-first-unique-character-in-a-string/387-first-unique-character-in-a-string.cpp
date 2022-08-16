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
        
        /*
        unordered_map<char, int> m;
        int n = s.size();
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(m.find(s[i]) == m.end()) {
                m[s[i]] = i;
            } else {
                m[s[i]] = INT_MAX;
            }
        }
        
        for(auto it : m) {
            ans = min(it.second, ans);
        }
        
        return (ans == INT_MAX) ? -1 : ans;
        */
    }
};