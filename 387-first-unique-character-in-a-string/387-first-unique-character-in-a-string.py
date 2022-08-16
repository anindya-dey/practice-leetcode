class Solution:
    def firstUniqChar(self, s: str) -> int:
        counter = {}
        
        for c in s:
            if c not in counter:
                counter[c] = 0
            
            counter[c] += 1
            
        
        for i, c in enumerate(s):
            if counter[c] == 1:
                return i
        
        return -1;