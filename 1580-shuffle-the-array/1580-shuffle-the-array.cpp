class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int len = n*2;
        vector<int> ans(len);

        for(int i = 0, j = 0; i < n, j < n; i = i + 2, j++) {
            ans[i] = nums[j];
            ans[i+1] = nums[j+n];
        }
        
        return ans;
    }
};