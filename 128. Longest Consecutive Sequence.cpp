class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> numsSet;
        for(int i = 0; i < nums.size(); i++){
            numsSet.insert(nums[i]);
        }
        int length = 0;
        for (auto it = numsSet.begin(); it != numsSet.end(); ++it) {
            int num = *it; 

            if (numsSet.find(num - 1) == numsSet.end()) {
                int currNum = num;
                int currLength = 1;

                while (numsSet.find(currNum + 1) != numsSet.end()) {
                    currNum++;
                    currLength++;
                }

                length = max(length, currLength);
            }
        }
        return length;
    }
};
