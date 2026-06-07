class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0, count = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                max_count = max(max_count, count);
                count = 0;
            }
        }

        max_count = max(max_count, count);

        return max_count;
    }
};