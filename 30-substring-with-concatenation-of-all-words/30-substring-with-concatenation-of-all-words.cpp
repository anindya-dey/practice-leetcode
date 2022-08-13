class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        
        int length = s.length(),
            totalWords = words.size(),
            wordSize = words[0].size();

        int limit = length - totalWords * wordSize;
        
        unordered_map<string, int> frequencyMap;
        for(string word: words) {
            frequencyMap[word]++;
        }
        
        for(int i = 0; i <= limit; i++) {
            unordered_map<string, int> seenWords;
            int j = 0;
            for(; j < totalWords; j++) {
                int wordIndex = i + j * wordSize;
                string subWord = s.substr(wordIndex, wordSize);
                
                if(!frequencyMap[subWord]) break;
                
                seenWords[subWord]++;
                
                if(seenWords[subWord] > frequencyMap[subWord]) break;
            }
            
            if(j == totalWords) ans.push_back(i);
        }
        
        return ans;
        
        
        /*
        unordered_map<string, int> counts;
        
        for (string word : words)
            counts[word]++;
        
        int n = s.length(), num = words.size(), len = words[0].length();
        vector<int> indexes;
        
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else break;
            }
        
            if (j == num) indexes.push_back(i);
        }
        return indexes;
        */
    }
};