class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        
        int maxLeft = height[l];
        int maxRight = height[r];
        
        int amountOfTrappedWater = 0;
        
        while(l < r) {
            if(height[l] < height[r]) {
                l++;
                maxLeft = max(maxLeft, height[l]);
                amountOfTrappedWater += maxLeft - height[l];
            } else {
                r--;
                maxRight = max(maxRight, height[r]);
                amountOfTrappedWater += maxRight - height[r];
            }
        }
        
        return amountOfTrappedWater;
    }
};