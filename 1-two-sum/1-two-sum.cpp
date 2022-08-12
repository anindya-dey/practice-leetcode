class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tracker;
        int n = nums.size();
        
        for(int i = 0; i < n; tracker.insert({nums[i], i}), i++) {
            int complement = target - nums[i];
            if(tracker.find(complement) != tracker.end()) {
                return { tracker[complement], i };
            }
        }

        return { -1, -1 };
    }
};