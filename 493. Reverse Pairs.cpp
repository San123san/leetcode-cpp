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
