class Solution {
public:
    void permute(vector<int>& nums, int n, vector<vector<int>>& ans, int index=0){
        if(index >= n){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < n; i++){
            bool shouldSwap = true;
            for (int j = index; j < i; j++) {
                if (nums[j] == nums[i]) {
                    shouldSwap = false;
                    break;
                }
            }
            if (shouldSwap) {
                swap(nums[i], nums[index]);
                permute(nums, n, ans, index+1);
                swap(nums[i], nums[index]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        permute(nums, n, ans);
        return ans;
    }
};
