class Solution 
public:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[right];
        int i = left;
        for(int j = left; j <= right-1; j++){
            if(nums[j] > pivot){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[right]);
        return i;
    }
    int quickSelect(vector<int>& nums, int left, int right, int k){
        if(left == right) return nums[left];

        int partitionIndex = partition(nums, left, right);

        if(k == partitionIndex) return nums[partitionIndex];

        if(partitionIndex<k){
            return quickSelect(nums, partitionIndex+1, right, k);
        }else{
            return quickSelect(nums, left, partitionIndex-1, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n-1, k-1);
    }
};
