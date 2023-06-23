class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        // int i = 0, j = 1, k = 2, count = 0, n = nums.size();
        // for(int i = 0; i < n - 2; i++) {
        //     for(int j = i + 1; j < n -1; j++) {
        //         for(int k = j + 1; k < n; k++) {
        //             if(((nums[j] - nums[i]) == diff) && ((nums[k] - nums[j]) == diff)) {
        //                 count++;
        //             }
        //         }
        //     }
        // }
        

        // int count = 0;
        // unordered_map<int, bool> m = {};
        // for(int i = 0; i < nums.size(); i++) {
        //     m[nums[i]] = true;
        // }
        // for(int i = 0; i < nums.size(); i++) {
        //     count += m[nums[i] - diff] && m[nums[i] + diff];
        // }
        // return count;
        
        
        int count = 0;
        unordered_set<int> s = {};
        for(int num : nums) {
            if ( (s.find(num - diff) != s.end()) && (s.find(num - (2*diff)) != s.end()) ) {
                count++;
            }
            s.insert(num);
        }
        return count;
    }
};