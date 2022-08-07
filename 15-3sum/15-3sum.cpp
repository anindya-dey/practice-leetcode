class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 2; i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int a = -nums[i];
                int lo = i + 1;
                int hi = n - 1;
                while(lo < hi) {
                    if((nums[lo] + nums[hi]) == a) {
                        result.push_back({ -a, nums[lo], nums[hi] });
                        while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1]) hi--;

                        lo++; hi--;
                    } else if((nums[lo] + nums[hi]) < a) {
                        lo++;
                    } else {
                        hi--;
                    }
                }
            }
        }
        
        return result;
    }
};