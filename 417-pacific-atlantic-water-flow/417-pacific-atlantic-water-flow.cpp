class Solution {
private:
    void dfs(vector<vector<int>>& heights, int row, int col, int prev, set<pair<int, int>>& ocean) {
        if(row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size()) return;
        
        if(ocean.find({row, col}) != ocean.end()) return;
        
        int curr = heights[row][col];
        
        if(curr < prev) return;
        
        ocean.insert({row, col});
        
        dfs(heights, row - 1, col, curr, ocean);
        dfs(heights, row + 1, col, curr, ocean);
        dfs(heights, row, col - 1, curr, ocean);
        dfs(heights, row, col + 1, curr, ocean);
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        
        if(heights.size() == 0 || heights[0].size() == 0) return res;
        
        int rows = heights.size();
        int cols = heights[0].size();
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;
        
        for(int i = 0; i < cols; i++) {
            dfs(heights, 0, i, INT_MIN, pacific);
            dfs(heights, rows - 1, i, INT_MIN, atlantic);
        }
        
        for(int i = 0; i < rows; i++) {
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, cols - 1, INT_MIN, atlantic);
        }
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if((pacific.find({i, j}) != pacific.end()) && (atlantic.find({i, j}) != atlantic.end())) {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
};