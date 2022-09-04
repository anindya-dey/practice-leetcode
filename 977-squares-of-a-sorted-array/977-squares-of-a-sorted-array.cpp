class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        int l = 0, r = size - 1;
        vector<int> res(size);
        
        for(int k = size - 1; k >= 0; k--) {
            if(abs(nums[l]) > abs(nums[r])) {
                res[k] = nums[l] * nums[l];
                l++;
            } else {
                res[k] = nums[r] * nums[r];
                r--;
            }
        }
        
        return res;
    }
};