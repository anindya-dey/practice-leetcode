class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        
        for(int i = 1; i <= n; i++) {
            bool isDivisibleBy3 = (i % 3) == 0;
            bool isDivisibleBy5 = (i % 5) == 0;
            
            string str = "";
            
            if(isDivisibleBy3) {
                str += "Fizz";
            }
            
            if(isDivisibleBy5) {
                str += "Buzz";
            }
            
            if(str.empty()) {
                str += to_string(i);
            }
            
            result.push_back(str);
        }
        
        return result;
    }
};