class Solution {
public:
    void solve(int idx, int n, vector<int>& nums, vector<vector<int>>& res){
        if(idx >= n){
            res.push_back(nums);
            return;
        }

        for(int i = idx; i < n; i++){
            swap(nums[i], nums[idx]);
            solve(idx + 1, n, nums, res);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> res;
        vector<int> temp;

        solve(0, n, nums, res);

        return res;
    }
};
