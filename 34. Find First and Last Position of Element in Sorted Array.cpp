class Solution {
public:
    int firstIdx(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                if(mid != 0 && nums[mid - 1] == target){
                    right = mid - 1;
                } else {
                    return mid;
                }
            }

            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
    int lastIdx(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                if(mid != nums.size() - 1 && nums[mid + 1] == target){
                    left = mid + 1;
                } else {
                    return mid;
                }
            }

            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstIdx(nums, target);
        int last = lastIdx(nums, target);

        vector<int> res;

        res.push_back(first);
        res.push_back(last);

        return res;
    }
};
