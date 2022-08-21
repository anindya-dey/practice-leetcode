class Solution {
private:
    bool stampEqualsSubsequence(string stamp, string target, int position) {
        int n = stamp.length();
        
        for(int i = 0; i < n; i++) {
            if(target[i + position] == '?') continue;
            
            if(stamp[i] != target[i + position]) {
                return false;
            }
        }
        return true;
    }
    
    int replaceSubsequence(string stamp, string &target, int position) {
        int n = stamp.length();
        int count = 0;
        
        for(int i = position; i < position + n; i++) {
            if(target[i] != '?') {
                target[i] = '?';
                count++;
            }
        }
        
        return count;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.length();
        int n = target.length();
        int count = 0;
        int turn = 0;
        int maxTurns = 10*n;
        vector<int> result;
        vector<bool> visited(n, false);
        
        while(turn < maxTurns) {
            bool replaced = false;
            
            for(int i = 0; i <= n - m; i++) {
                // check if stamp equals target subsequence
                if(!visited[i] && stampEqualsSubsequence(stamp, target, i)) {
                    // replace the subsequence in target with "?"
                    count += replaceSubsequence(stamp, target, i);
                    
                    // store the position from where target has been replaced
                    result.push_back(i);
                    
                    // if target is replaced completely, return result in reverse
                    if(count == n) {
                        reverse(result.begin(), result.end());
                        return result;
                    }
                    
                    replaced = true;
                    
                    // add position to visited to not repeat the same steps again
                    visited[i] = true;
                }
            }
            
            turn++;
            
            if(!replaced) return {};
        }
        
        return {};
    }
};