class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int len = n*2;
        vector<int> ans(len);

        for(int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                // for even "i", take from first half
                ans[i] = nums[i/2];
            } else {
                //for odd "i", take from second half
                ans[i] = nums[n + (i/2)];
            }
        }
        
        return ans;
    }
};