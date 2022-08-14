class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for(auto word: wordList) wordSet.insert(word);
        
        if(wordSet.find(endWord) == wordSet.end()) return 0;
        
        int depth = 0;
        int n = beginWord.length();
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()) {
            depth += 1;
            int lsize = q.size();
            
            while(lsize--) {
                string curr = q.front();
                q.pop();
                
                for(int i = 0; i < n; i++) {
                    string temp = curr;
                    for(char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                    
                        if(temp == curr) continue;
                    
                        if(temp == endWord) return depth + 1;
                    
                        if(wordSet.find(temp) != wordSet.end()) {
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
        
    }
};