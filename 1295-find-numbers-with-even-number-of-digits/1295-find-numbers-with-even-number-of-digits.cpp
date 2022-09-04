class Solution {
private:
    int countDigits(int num) {
        int count = 0;
        while(num > 0) {
            count++;
            num /= 10;
        }
        return count;
    }

public:
    int findNumbers(vector<int>& nums) {
        int countEvenDigits = 0;
        
        for(auto n : nums) {
            if((countDigits(n) % 2) == 0) {
                countEvenDigits++;
            }
            
            /*
            if(( 10<=n && n<=99) || (1000<=n && n<=9999 ) || ( n==100000 ))
            {
               countEvenDigits++;
            }
            */
        }
        
        return countEvenDigits;
    }
};