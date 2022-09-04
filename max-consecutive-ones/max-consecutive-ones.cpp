class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int tempCount = 0;
        for(auto i : nums) {
            if(i == 1) {
                tempCount++;
            } else {
                maxCount = max(maxCount, tempCount);
                tempCount = 0;
            }
        }
        
        maxCount = max(maxCount, tempCount);
        
        return maxCount;
    }
};