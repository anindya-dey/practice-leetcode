class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();

        for(int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            while(l < r) {
                swap(image[i][l], image[i][r]);
                image[i][l] = image[i][l] == 0 ? 1 : 0;
                image[i][r] = image[i][r] == 0 ? 1 : 0;
                l++;
                r--;
            }

            if(l == r) {
               image[i][l] = image[i][l] == 0 ? 1 : 0; 
            }
        }

        return image;
    }
};