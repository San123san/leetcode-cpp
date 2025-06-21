class Solution {
public:
    void solve(int idx, int n, int k, vector<int>& nums, int array_sum,
               vector<int>& sum, unordered_map<int, vector<vector<int>>>& mp,
               vector<bool>& vis) {

        if (idx >= n) {
            // Add the current sum to the map
            if (mp.find(array_sum) != mp.end()) {
                mp[array_sum].push_back(sum); // Correctly use push_back to add sum
            } else {
                mp[array_sum] = {sum}; // Initialize map with the sum and the subset
            }
            return;
        }

        // Try to include nums[idx] in the current subset
        if (!vis[idx]) {
            sum.push_back(nums[idx]);
            vis[idx] = true;
            solve(idx + 1, n, k, nums, array_sum + nums[idx], sum, mp, vis);
            sum.pop_back();  // Correct pop_back, no arguments needed
            vis[idx] = false;
        }

        // Try the case without including nums[idx]
        solve(idx + 1, n, k, nums, array_sum, sum, mp, vis);
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<vector<int>>> mp;
        vector<int> sum;
        int array_sum = 0;  // Initialize array_sum to 0
        vector<bool> vis(n, false);  // Initialize visited array to false for all elements

        solve(0, n, k, nums, array_sum, sum, mp, vis);

        // Check if any partition contains exactly k subsets
        for (auto& k_ordered : mp) {
            if (k_ordered.second.size() == k) {  // This is the correct way to access the subsets
                return true;
            }
        }
        return false;
    }
};
