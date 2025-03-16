// Brute force - O(n^2)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if((long long)nums[i] > 2 * (long long)nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};

// merge sort 
//time complexity - O(n log n)
class Solution {
public:
    // Merge function that also counts reverse pairs while merging
    int merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        // Count reverse pairs
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge the two halves
        int i = left, k = left;
        j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= right) {
            temp[k++] = nums[j++];
        }

        for (int i = left; i <= right; i++) {
            nums[i] = temp[i]; // Copy the merged result back to the original array
        }

        return count;
    }
    int mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, temp, left, mid);
        count += mergeSort(nums, temp, mid + 1, right);
        count += merge(nums, temp, left, mid, right);
        return count;
    }

    // Main function to count the reverse pairs
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(nums, temp, 0, n - 1);
    }
};
