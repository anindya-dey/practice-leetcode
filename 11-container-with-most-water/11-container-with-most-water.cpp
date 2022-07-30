class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        
        int leftMax = height[l];
        int rightMax = height[r];
        
        int area = 0;
        
        while(l < r) {
            if(height[l] < height[r]) {
                area = max(area, (r - l) * min(leftMax, rightMax));
                l++;
                leftMax = max(leftMax, height[l]);
            } else {
                area = max(area, (r - l) * min(leftMax, rightMax));
                r--;
                rightMax = max(rightMax, height[r]);
            }
        }
        
        return area;
    }
};