class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        
        for(int n : nums) {
            if(hashSet.find(n) != hashSet.end()) return true;
            
            hashSet.insert(n);
        }
        
        return false;
    }
};