class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int minLength = INT_MAX;
        int left = 0;
        int sum = 0;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(sum >= target){
                minLength = min(minLength, right - left + 1);
                sum = sum - nums[left];
                left++;
            }
        }
        if(minLength == INT_MAX) return 0;
        return minLength;
    }
};
