class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prevNum = nums[0];
        int insertPosition = 1;
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            if(prevNum != nums[i]) {
                nums[insertPosition] = prevNum = nums[i];
                insertPosition++;
            }
        }
        
        return insertPosition;
    }
};