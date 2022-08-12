class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tracker;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if(tracker.find(complement) != tracker.end()) {
                return { tracker[complement], i };
            }
            
            tracker.insert({nums[i], i});
        }

        return { -1, -1 };
    }
};