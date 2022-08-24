class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        
        int max_power_of_3 = 1162261467;
        
        return ((max_power_of_3 % n) == 0);
    }
};