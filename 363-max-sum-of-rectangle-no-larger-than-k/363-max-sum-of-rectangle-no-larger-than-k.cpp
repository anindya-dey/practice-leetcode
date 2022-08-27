class Solution {
/*
private:    
    void setArray(vector<int> &arr, vector<vector<int>> &matrix, int colIndex) {
        int rows = matrix.size();
        for(int i = 0; i < rows; i++) {
            arr[i] = matrix[i][colIndex];
        }
    }
*/
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        /*
        int l = 0, r = 0, rows = matrix.size(), cols = matrix[0].size();
        vector<int> arr;
        
        for(int i = 0; i < rows; i++) {
            setArray(arr, matrix, i);
            for(int j = i; j < cols; j++) {
                
            }
        }
        */
        
        if (matrix.empty()) return 0;
        
        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        
        for (int l = 0; l < col; ++l) {
            vector<int> sums(row, 0);
            for (int r = l; r < col; ++r) {
                for (int i = 0; i < row; ++i) {
                    sums[i] += matrix[i][r];
                }

                // Find the max subarray no more than K 
                set<int> accuSet;
                accuSet.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (int sum : sums) {
                    curSum += sum;
                    set<int>::iterator it = accuSet.lower_bound(curSum - k);
                    if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
                    accuSet.insert(curSum);
                }
                res = std::max(res, curMax);
            }
        }
        return res;
    }
};