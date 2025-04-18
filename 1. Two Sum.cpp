
  class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> ans;
        for(int i=0; i<nums.size(); i++){
            int left = target - nums[i];
            if(ans.find(left) != ans.end()){
                return {ans[left], i};
            }
            ans[nums[i]] = i;
        }
        return {};
    }
};
