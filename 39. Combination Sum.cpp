class Solution {
public:
    void solve(int idx, int n, vector<int>& candidates, int target,
               vector<vector<int>>& res, vector<int>& temp) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (idx >= n || target < 0) {
            return;
        }

        temp.push_back(candidates[idx]);
        solve(idx, n, candidates, target - candidates[idx], res, temp);
        temp.pop_back();

        solve(idx + 1, n, candidates, target, res, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> temp;

        solve(0, n, candidates, target, res, temp);

        return res;
    }
};
