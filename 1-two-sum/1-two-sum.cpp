class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        unordered_map<int, int> tracker;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if(tracker.find(complement) == tracker.end()) {
                tracker.insert({nums[i], i});
            } else {
                result[0] = tracker[complement];
                result[1] = i;
                break;
            }
        }

        return result;
    }
};