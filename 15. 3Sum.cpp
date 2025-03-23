class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 3) {
            int sum = 0;
            for(int i = 0; i < nums.size(); i++){
                sum += nums[i];
            }
            
            if(sum == 0){
                int i = 0;
                res.push_back({nums[i], nums[i+1], nums[i+2]});
            }
            return res;
        } 
        if(nums.size() < 3) return res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    res.push_back({nums[i], nums[left], nums[right]});

                    while(left < right && nums[left] == nums[left+1]) ++left;
                    while(left < right && nums[right] == nums[right-1]) --right;

                    ++left;
                    --right;
                } 
                else if( sum < 0){
                    ++left;
                }
                else{
                    --right;
                }
            }
        }
        return res;
    }
};
