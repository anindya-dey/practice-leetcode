class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        /*
        int r = ransomNote.length();
        int m = magazine.length();
        
        if(r > m) return false;
        
        unordered_map<char, int> r_map;
        unordered_map<char, int> m_map;
        
        for(auto x : ransomNote) r_map[x]++;
        
        for(auto y : magazine) m_map[y]++;
        
        for(auto z : ransomNote) {
            if(r_map[z] > m_map[z]) return false;
        }
        
        return true;
        */
        
        int r = ransomNote.length();
        int m = magazine.length();
        
        if(r > m) return false;
        
        vector<int> m_map(26, 0);
        
        for(int i = 0; i < m; i++) {
            m_map[magazine[i] - 'a']++;
        }
        
        for(int j = 0; j < r; j++) {
            if(--m_map[ransomNote[j] - 'a'] < 0) return false;
        }
        
        return true;
    }
};