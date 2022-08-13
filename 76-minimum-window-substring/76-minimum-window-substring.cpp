class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(),
            n = t.size();
        
        if(m < n) return "";
        
        int l = 0, 
            r = 0, 
            counter = 0,
            start = 0,
            len = INT_MAX;
        
        unordered_map<char, int> letters;
        for(auto c: t) letters[c]++;
        
        while(r < m) {
            if(letters[s[r]] > 0) counter++;
            
            letters[s[r]]--;
            
            if(counter == n) {
                while(l < r && letters[s[l]] < 0) {
                    letters[s[l]]++;
                    l++;
                }
                
                if(len > (r - l + 1)) {
                    start = l;
                    len = r - l + 1;
                }
            }
            
            r++;
        }
        
        if (len == INT_MAX) return "";
        
        cout << "start: " << start << ", len: " << len << "\n";
        
        return s.substr(start, len);
    }
};