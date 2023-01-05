class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;

        f(candidates, target, 0, ds, result);

        return result;
    }

    void f(vector<int>& candidates, int target, int idx, vector<int> &ds, vector<vector<int>>& result) {
        if(idx >= candidates.size()) {
            if(target == 0) {
                result.push_back(ds);
            }
            return;
        }

        if(target < 0) return;

        ds.push_back(candidates[idx]);
        f(candidates, target - candidates[idx], idx, ds, result);

        ds.pop_back();
        f(candidates, target, idx + 1, ds, result);
    }
};