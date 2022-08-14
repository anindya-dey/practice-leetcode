class TrieNode {
  public:
    TrieNode *links[26];
    bool isEnd = false;
    
    bool containsChar(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    
    void putChar(char ch) {
        links[ch - 'a'] = new TrieNode();
    }
    
    TrieNode *next(char ch) {
        return links[ch - 'a'];
    }
    
    void setEnd() {
        isEnd = true;
    }
    
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        
        for(char ch : word) {
            if(!node->containsChar(ch)) {
                node->putChar(ch);
            }
            node = node->next(ch);
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode *node = root;
        
        for(char ch : word) {
            if(!node->containsChar(ch)) {
                return false;
            }
            node = node->next(ch);
        }
        
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        
        for(char ch : prefix) {
            if(!node->containsChar(ch)) {
                return false;
            }
            node = node->next(ch);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */