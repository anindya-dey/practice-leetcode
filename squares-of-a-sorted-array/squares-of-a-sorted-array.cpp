class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        
        for(auto num : nums) {
            res.push_back(num * num);
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};