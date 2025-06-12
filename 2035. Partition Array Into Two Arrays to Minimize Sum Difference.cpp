class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int tSum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        unordered_map<int, vector<int>> leftSums;
        unordered_map<int, vector<int>> rightSums;

        generateSubsetSums(left, 0, 0, 0, leftSums);
        generateSubsetSums(right, 0, 0, 0, rightSums);

        for(auto& [k, vec]: rightSums){
            sort(vec.begin(), vec.end());
        }

        int res = INT_MAX;

        for(int i = 0; i <= n; ++i){
            const vector<int>& lSums = leftSums[i];
            const vector<int>& rSums = rightSums[n - i];
            for(int s1 : lSums){
                int target = tSum / 2 - s1;
                auto it = lower_bound(rSums.begin(), rSums.end(), target);
                if(it != rSums.end()){
                    int s2 = *it;
                    int pickedSum = s1 + s2;
                    int otherSum = tSum - pickedSum;
                    res = min(res, abs(pickedSum - otherSum));
                }
                if(it != rSums.begin()){
                    --it;
                    int s2 = *it;
                    int pickedSum = s1 + s2;
                    int otherSum = tSum - pickedSum;
                    res = min(res, abs(pickedSum - otherSum));
                }
            }
        }
        return res;
    }

    void generateSubsetSums(const vector<int>& arr, int idx, int count, int currSum, unordered_map<int, vector<int>>& sums){
        if(idx == arr.size()){
            sums[count].push_back(currSum);
            return;
        }
        generateSubsetSums(arr, idx + 1, count + 1, currSum + arr[idx], sums);
        generateSubsetSums(arr, idx + 1, count, currSum, sums);
    }
};
