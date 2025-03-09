class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<=1) return;
        if (k > n) k = k % n;
        int rotate = n-k;
        vector<int> store;
        for(int i = rotate; i < n; i++){
            store.push_back(nums[i]);
        }
        vector<int> num = nums;
        for(int i = 0; i < k; i++){    
            nums[i] = store[i];
        }
        for(int i = k; i < n; i++){    
            nums[i] = num[i-k];
        }
    }
};
