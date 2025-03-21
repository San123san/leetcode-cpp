class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;

        unordered_map<int, int> appear;

        for(int i = 0; i < nums.size(); i++){
            if(appear.find(nums[i]) != appear.end()){
                appear[nums[i]]++;
            }else{
                appear[nums[i]] = 1;
            }
        }
        nums.clear();
        for(auto &maj: appear){
            if(maj.second > n){
                nums.push_back(maj.first);
            }
        }
        return nums;

    }
};
