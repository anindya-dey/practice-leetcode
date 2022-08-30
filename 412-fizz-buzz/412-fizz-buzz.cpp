class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        
        for(int i = 1; i <= n; i++) {
            bool isDivisibleBy3 = (i % 3) == 0;
            bool isDivisibleBy5 = (i % 5) == 0;
            
            if(isDivisibleBy3 && isDivisibleBy5) {
                result.push_back("FizzBuzz");
            } else if(isDivisibleBy3) {
                result.push_back("Fizz");
            } else if(isDivisibleBy5) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(i));
            }
        }
        
        return result;
    }
};