class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        int maxNum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            maxNum = max(maxNum, nums[i]-nums[i-1]);
        }
        
        return maxNum;
    }
};
