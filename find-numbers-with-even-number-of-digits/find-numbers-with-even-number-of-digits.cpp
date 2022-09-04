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
        
        for(auto num : nums) {
            if(countDigits(num) % 2 == 0) {
                countEvenDigits++;
            }
        }
        
        return countEvenDigits;
    }
};