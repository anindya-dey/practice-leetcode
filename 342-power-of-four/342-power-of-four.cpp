class Solution {
public:
    bool isPowerOfFour(int n) {
        // (n > 0)
        // -- The number should be positive and greater than zero
        
        // (n & (n-1) == 0)
        // -- Is there only one 1?
        //    -- e.g, 0100 (=4) or 0001 0000 (=16)
        // Power of 4 has only one 1.
        
        // ((n & 0x55555555) != 0)
        // -- If so, is the 1 in the right place?
        //    -- e.g, 0100 (=4) and not 0010 (=2)
        // -- This will exclude those numbers which are power of 2 but not of 4 (like 2, 8, 32, etc)
        // -- 0x55555555 = Hex representation of 0101 0101 0101 ... 0101
        
        return (n> 0) && ((n & (n-1)) == 0) && ((n & 0x55555555) != 0);
    }
};