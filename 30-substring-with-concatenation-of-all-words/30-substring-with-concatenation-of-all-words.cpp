class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int length = s.size();
        int totalWords = words.size();
        vector<int> ans;
        
        if(length == 0 || totalWords == 0) return ans;
        
        int wordSize = words[0].size();
        int limit = length - totalWords * wordSize;
        
        unordered_map<string, int> frequencyMap;
        
        for(int i = 0; i < totalWords; i++) {
            string word = words[i];
            
            if(!frequencyMap[word]) frequencyMap[word] = 0;
            
            frequencyMap[word]++;
        }
        
        for(int i = 0; i <= limit; i++) {
            unordered_map<string, int> seenWords;
            
            for(int j = 0; j < totalWords; j++) {
                int wordIndex = i + j * wordSize;
                string subWord = s.substr(wordIndex, wordSize);
                
                if(!frequencyMap[subWord]) break;
                
                if(!seenWords[subWord]) seenWords[subWord] = 0;
                
                seenWords[subWord]++;
                
                if(seenWords[subWord] > frequencyMap[subWord]) break;

                if((j + 1) == totalWords) ans.push_back(i);
            }
        }
        
        return ans;
    }
};