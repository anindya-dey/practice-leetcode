class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> fm, hm;
        int n = nums.size();
        
        for(auto num : nums) fm[num]++;
        
        for(auto num : nums) {
            if(fm[num] == 0) continue;
            
            if(hm[num] > 0) {
                hm[num]--;
                hm[num+1]++;
                fm[num]--;
            } else if (fm[num] > 0 && fm[num+1] > 0 && fm[num+2] > 0) {
                fm[num]--;
                fm[num+1]--;
                fm[num+2]--;
                hm[num+3]++;
            } else {
                return false;
            }
        }
        
        return true;
    }
};