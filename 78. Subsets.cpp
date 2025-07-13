class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> res;

        subSet(0, sub, res, nums, nums.size());
        return res;
    }

    void subSet(int i, vector<int> sub, vector<vector<int>>& res, vector<int>& nums, int n){

        if(i >= n){
            res.push_back(sub);
            return;
        }


        sub.push_back(nums[i]);
        subSet(i + 1, sub, res, nums, n);
        sub.pop_back();
        subSet(i + 1, sub, res, nums, n);
    }
};
