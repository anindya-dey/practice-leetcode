class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string dict[26] =  { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
        
        unordered_set<string> s;
        
        for(auto word : words) {
            string str;
            for(auto ch : word) {
                str.append(dict[ch-'a']);
            }
            s.insert(str);
        }
        
        
        return s.size();
    }
};