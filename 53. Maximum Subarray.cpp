class Solution {
public:
    int cross(vector<int>& nums, int low, int mid, int high){
        int sum = 0;
        int leftSum = INT_MIN;
        for(int i = mid; i >= low; i--){
            sum += nums[i];
            if(sum > leftSum) leftSum = sum;
        }

        int rightSum = INT_MIN;
        sum = 0;
        for(int i = mid+1; i <= high; i++){
            sum += nums[i];
            if(sum > rightSum) rightSum = sum;
        }

        return leftSum + rightSum;
    }
    int max(vector<int>& nums, int low, int high){
        int mid = low + (high - low) / 2;
        if(low == high) return nums[low];

        int leftSum = max(nums, low, mid);
        int rightSum = max(nums, mid + 1, high);
        int crossSum = cross(nums, low, mid, high);

        if(leftSum >= crossSum && leftSum >= rightSum) return leftSum;
        if(rightSum >= crossSum && rightSum >= leftSum) return rightSum;
        return crossSum;
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        if(low == high) return nums[low];
        return max(nums, low , high);
    }
};
