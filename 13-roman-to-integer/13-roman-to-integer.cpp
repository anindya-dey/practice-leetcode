class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
        /*
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int curr = m[s[i]];
            if(((i + 1) < n) && (curr < m[s[i+1]])) {
                ans -= curr;
            } else {
                ans += curr;
            }
        }
        
        return ans;
        
        */
        
        int sum = T[s.back()];
        for (int i = s.length() - 2; i >= 0; --i) 
        {
           if (T[s[i]] < T[s[i + 1]])
           {
               sum -= T[s[i]];
           }
           else
           {
               sum += T[s[i]];
           }
        }

        return sum;
    }
};