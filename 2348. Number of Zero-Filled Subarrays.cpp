class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long totalCount = 0;
        long long count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count++;
                totalCount += count;
            } else {
                count = 0;
            }
        }

        return totalCount;
    }
};
