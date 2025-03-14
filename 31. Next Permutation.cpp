// brute force - by skipping duplicate during backtracking - Memory Limit Exceeded
// time complexity: O(n!logn!) and Space Complexity: O(n! * n)
class Solution {
public:

    void next(int index, vector<vector<int>>& ans, vector<int>& nums, int n){
        if(index == n){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < n; i++){
            if (i > index && nums[i] == nums[index]) continue;
            swap(nums[index], nums[i]);
            next(index + 1, ans, nums, n);
            swap(nums[index], nums[i]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        next(0, ans, nums, n);
        sort(ans.begin(), ans.end());
        if(ans[ans.size()-1] == nums) {
            nums = ans[0];
            return;
        }
        for(int i = 0; i < ans.size(); i++){
            if(nums == ans[i]){
                nums = ans[i+1];
                return;
            }
        }
    }
};

//brute force - time limit exceed
// Time Complexity: O(n! * log(n!)) and Space Complexity: O(n! * n)
class Solution {
public:

    void next(int index, vector<vector<int>>& ans, vector<int>& nums, int n){
        if(index == n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> swapped;
        for(int i = index; i < n; i++){
            if (swapped.find(nums[i]) != swapped.end()) continue;
            swapped.insert(nums[i]);
            swap(nums[index], nums[i]);
            next(index + 1, ans, nums, n);
            swap(nums[index], nums[i]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        next(0, ans, nums, n);
        sort(ans.begin(), ans.end());
        if(ans[ans.size()-1] == nums) {
            nums = ans[0];
            return;
        }
        for(int i = 0; i < ans.size(); i++){
            if(nums == ans[i]){
                nums = ans[i+1];
                return;
            }
        }
    }
};


// greedy approach
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        for(int i = n-1 ; i > 0; i--){
            if(nums[i] > nums[i-1]){
                index = i-1;
                break;
            }
        }

        if(index != -1){
            int swap_index = index;

            for(int j = n-1; j >= index+1; j--){
                if(nums[j] > nums[index]){
                    swap_index = j;
                    break;
                }
            }
            swap(nums[index], nums[swap_index]);
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};
