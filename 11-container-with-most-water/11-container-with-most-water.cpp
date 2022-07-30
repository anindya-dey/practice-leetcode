class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        
        int area = 0;
        int resultArea = 0;
        
        while(l < r) {
            if(height[l] < height[r]) {
                area = (r - l) * height[l];
                l++;
            } else {
                area = (r - l) * height[r];
                r--;
            }
            resultArea = max(resultArea, area);
        }
        
        return resultArea;
    }
};