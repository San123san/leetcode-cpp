class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int currSum = 0;
        int res = 0;

        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            if(prefixCount.find(currSum - k) != prefixCount.end()){
                res += prefixCount[currSum - k];
            }
            prefixCount[currSum]++;
        }
        return res;
    }
};
