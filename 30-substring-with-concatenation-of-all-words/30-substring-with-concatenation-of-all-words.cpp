class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        
        int length = s.length(),
            totalWords = words.size(),
            wordSize = words[0].size(),
            limit = length - totalWords * wordSize;
        
        unordered_map<string, int> frequencyMap;
        for(string word: words) {
            frequencyMap[word]++;
        }
        
        for(int i = 0; i <= limit; i++) {
            unordered_map<string, int> seenWords;
            
            int j = 0;
            for(; j < totalWords; j++) {
                string subWord = s.substr(i + j * wordSize, wordSize);
                
                if(!frequencyMap[subWord]) break;
                
                seenWords[subWord]++;
                
                if(seenWords[subWord] > frequencyMap[subWord]) break;
            }
            
            if(j == totalWords) ans.push_back(i);
        }
        
        return ans;        
    }
};